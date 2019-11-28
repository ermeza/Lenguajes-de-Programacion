#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<stderr>
#define MAX 100

//---------------------------------------------------------------------------


struct token
{
  char tokens[MAX];
};
struct error
{
  char errors[MAX];
};
//---------------------------------------------------------------------------

token token1;
error error1;
int int main() {
  FILE *pf,*Tokens;
  FILE *Errores;
  char c;
  char Estado=0;
  char pal_res[]={"define", "imprimir", "leer", "Si", "SiNo", "Hacer", \
                        "FinSi", "Repetir", "Mientras", "Hasta", "entero", "flotante", "caracter"};
  pf=fopen("ArchivoAnalisis.txt","r");
  Tokens=fopen("Tokens.txt", "w+");
  Errores=fopen("Errores.txt", "w+");
  if (pf=NULL){
    fpats("Error en el ArchivoAnalisis",stderr);
    exit(1);
  }else{
    while ((c=fgetc(pf))!EOF) {
      switch (c) {
        case ( c>=65 && c<=90 )://Letras Mayusculas
          if (Estado==0||Estado==1||Estado==2||Estado==9) {
            strcpy(token1.tokens, "Tkn_LetraMa");
            fwrite (&token1, sizeof(token1), 1, Tokens);
            Estado==1;
          }
          break;
        case (c>=96 && c<=122)://Letras Minusculas
            if (Estado==1||Estado==2) {
              strcpy(token1.tokens, "Tkn_LetraMi");
              fwrite (&token1, sizeof(token1), 1, Tokens);
              Estado==1;
            }
            break;
        case (c<=57&&c>=48)://Numeros
          if (Estado==1||Estado==2) {
            strcpy(token1.tokens, "Tkn_numero");
            fwrite (&token1, sizeof(token1), 1, Tokens);
            Estado==2
          } else if (Estado==2||Estado==9) {
            strcpy(token1.tokens, "Tkn_numero");
            fwrite (&token1, sizeof(token1), 1, Tokens);
            Estado==8;
          } else if (Estado==9) {
            strcpy(token1.tokens, "Tkn_numero");
            fwrite (&token1, sizeof(token1), 1, Tokens);
            Estado==5;
          } else if (Estado==3||Estado==5) {
            strcpy(token1.tokens, "Tkn_numero");
            fwrite (&token1, sizeof(token1), 1, Tokens);
            Estado==3;
          } else if (Estado==4) {
            strcpy(token1.tokens, "Tkn_numero");
            fwrite (&token1, sizeof(token1), 1, Tokens);
            Estado==4;
          }else {
            strcpy(token1.tokens, "Tkn_numero");
            fwrite (&token1, sizeof(token1), 1, Tokens);
            Estado==7;
          }
          break;
        case '.':
            if (Estado==6) {
              strcpy(token1.tokens, "Punto Decimal");
              fwrite (&token1, sizeof(token1), 1, Tokens);
              Estado==7;
            } else if (Estado==3) {
              strcpy(token1.tokens, "Punto Decimal");
              fwrite (&token1, sizeof(token1), 1, Tokens);
              Estado==4;
            }
            break;
        case (c=='-'||c=='+'||c=='/'||c=='*'):
              strcpy(token1.tokens, "Tkn_Operador_Aritmetico");
              fwrite (&token1, sizeof(token1), 1, Tokens);
            break;
        case (c=='<'||c=='>'||c=='='||c=='!'):
              strcpy(token1.tokens, "Tkn_Relacion");
              fwrite (&token1, sizeof(token1), 1, Tokens);
            break;
        case(c=='<'&& c=='-'):
              strcpy(token1.tokens, "Tkn_Asignacion");
              fwrite (&token1, sizeof(token1), 1, Tokens);
            break;
        case(pal_res.includes(c)):
            strcpy(token1.tokens, "Tkn_Palabra_Reservada");
            fwrite (&token1, sizeof(token1), 1, Tokens);
            break;
        case '\n':
            if (Estado==0||Estado==1||Estado==2) {
              strcpy(token1.tokens, "Tkn_cadena");
              fwrite (&token1, sizeof(token1), 1, Tokens);
            }else if(Estado==3||Estado==4||Estado==5){
              strcpy(token1.tokens, "Tkn_Operacion_Aritmetica");
              fwrite (&token1, sizeof(token1), 1, Tokens);
          	}else if(Estado==2||Estado==6)){
              strcpy(token1.tokens, "Tkn_Relacion");
              fwrite (&token1, sizeof(token1), 1, Tokens);
          	}else if(Estado==0||Estado==2||Estado==6||Estado==8)){
              strcpy(token1.tokens, "Tkn_Asignacion");
              fwrite (&token1, sizeof(token1), 1, Tokens);
          	}
            break;
        default;
          strcpy(error1.errors, "Tkn_No_Reconocido");
          fwrite (&error1, sizeof(error1), 1, Errores);
        }
      }
      fclose(pf);
      fclose (Errores);
      strcpy(token1.tokens, "$");
      fwrite (&token1, sizeof(token1), 1, Tokens);
      fclose (Tokens);
    }
    return 0;
  }
