#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX 100

//---------------------------------------------------------------------------


struct token
{
  char tokens[MAX];
}token1;
struct error
{
  char errors[MAX];
}error1;

//---------------------------------------------------------------------------


int main() {
  FILE *pf,*Tokens;
  FILE *Errores;
  int i,j;
  char c;
  char Estado=0;
  char pal_res[16][25]={"define", "imprimir", "leer", "Si", "SiNo", "Hacer", \
                        "FinSi", "Repetir", "Mientras", "Hasta", "entero", "flotante", "caracter"};
  pf=fopen("ArchivoAnalisis.Txt","r");
  Tokens=fopen("Tokens.Txt", "w+");
  Errores=fopen("Errores.Txt", "w+");
  if (pf==NULL){
    strcpy(error1.errors, "Error en el archivo");
    fwrite (&error1, sizeof(error1), 1, Errores);
    exit(1);
  }else{
    while ((c=fgetc(pf))!=EOF) {
      for(i=0;i<=16;i++){//Busca en el arreglo pal_res
        for(j=0;j<=25;j++){
          if(pal_res[i][j]==c){
            strcpy(token1.tokens, "Tkn_Palabra_Reservada\n");
            fwrite (&token1, sizeof(token1), 1, Tokens);
            Estado=9;
          }
        }
      }
      switch (Estado) {
        case 0:
          if (c>='A'&&c<='Z'){//Letras Mayusculas
            strcpy(token1.tokens, "Tkn_LetraMa\n");
            fwrite (&token1, sizeof(token1), 1, Tokens);
              Estado=1;
            }else if (c=='-'||c=='+'||c=='/'||c=='*'){//Tnk Operadores y Relacion
                    Estado=3;
            }else if(c<='0'&&c>='9'){//Numeros
                Estado=5;
              }else{
              strcpy(error1.errors, "Error en el archivo\n");
              fwrite (&error1, sizeof(error1), 1, Errores);
              exit(1);
            }
        break;
        case 1:
          if ((c>='a'&&c<='z')||(c>='A'&&c<='Z')){//Letras Minusculas
                Estado==1;
            }if(c<='0'&&c>='9'){//Numeros
                Estado=2;
            }
        break;
        case 2:
          if(c<='0'&&c>='9'){//Numeros
              Estado=2;
            }else if ((c=='-'||c=='+'||c=='/'||c=='*')&&(c<='0'&&c>='9')){//Tnk Operadores y Relacion
                    Estado=6;
            }else if((c=='<'&&c=='-')&&(c<='0'&&c>='9')){//Tnk de Asignacion
                  Estado=8;
            }else if((c=='<'&&c=='-')&&(c<='A'&&c>='Z')){//Tnk de Asignacion
                  Estado=0;
            }
        break;
        case 3:
          if(c<='0'&&c>='9'){//Numeros
            Estado=3;
          }else if (c=='-'||c=='+'||c=='/'||c=='*'){//Tnk Operadores y Relacion
                Estado=5;
          }else if(c=='.'){//Punto Decimal
                strcpy(token1.tokens, "Punto Decimal\n");
                fwrite (&token1, sizeof(token1), 1, Tokens);
                  Estado=4;
          }else  if ((c=='-'||c=='+'||c=='/'||c=='*')&&(c<='0'&&c>='9')){//Tnk Operadores y Relacion
                  Estado=5;
          }
        break;
        case 4:
          if(c<='0'&&c>='9'){//Numeros
            Estado=4;
          }else if ((c=='-'||c=='+'||c=='/'||c=='*')&&(c<='0'&&c>='9')){//Tnk Operadores y Relacion
                  Estado=5;
          }else if ((c=='-'||c=='+'||c=='/'||c=='*')&&(c<='A'&&c>='Z')){//Tnk Operadores y Relacion
                  Estado=0;
          }
        break;
        case 5:
          if(c<='0'&&c>='9'){//Numeros
            Estado=3;
          }else if (c=='-'||c=='+'||c=='/'||c=='*'){//Tnk Operadores y Relacion
                strcpy(token1.tokens, "Tkn_Operador_Aritmetico\n");
                fwrite (&token1, sizeof(token1), 1, Tokens);
                Estado=0;
          }
        break;
        case 6:
          strcpy(token1.tokens, "Punto Decimal\n");
          fwrite (&token1, sizeof(token1), 1, Tokens);
          if(c<='0'&&c>='9'){//Numeros
            Estado=6;
          }else if(c=='.'){//Punto Decimal
                Estado=7;
          }
        break;
        case 7:
          if(c<='0'&&c>='9'){//Numeros
            Estado=7;
          }
        break;
        case 8:
        if((c=='<'&&c=='-')&&(c<='0'&&c>='9')){//Tnk de Asignacion
              Estado=3;
        }else if((c=='<'&&c=='-')&&(c<='A'&&c>='Z')){//Tnk de Asignacion
              Estado=0;
        }
        break;
        case 9:
          if(c<='0'&&c>='9'){//Numeros
            Estado=8;
          }else if(c<='A'&&c>='Z'){//Numeros
            Estado=0;
          }
        break;
      }
      if( c=='\n'){//Ultimo Tnk Analizado
          if (Estado==0||Estado==1||Estado==2) {
            strcpy(token1.tokens, "Tkn_cadena\n");
            fwrite (&token1, sizeof(token1), 1, Tokens);
          }else if(Estado==3||Estado==4||Estado==5){
            strcpy(token1.tokens, "Tkn_Operacion_Aritmetica\n");
            fwrite (&token1, sizeof(token1), 1, Tokens);
          }else if(Estado==6){
            strcpy(token1.tokens, "Tkn_Relacion\n");
            fwrite (&token1, sizeof(token1), 1, Tokens);
          }else if(Estado==7){
            strcpy(token1.tokens, "Tkn_numeroDecimal\n");
            fwrite (&token1, sizeof(token1), 1, Tokens);
          }else {
            strcpy(error1.errors, "Tkn_NoReconocido\n");
            fwrite (&error1, sizeof(error1), 1, Errores);
          }
        }
      }
}
    fclose(pf);
    fclose (Errores);
    strcpy(token1.tokens, "$");
    fwrite (&token1, sizeof(token1), 1, Tokens);
    fclose (Tokens);
  return 0;
  }
