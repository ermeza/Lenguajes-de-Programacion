#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<stderr>


//---------------------------------------------------------------------------

int int main() {
  FILE *pf;
  char caracter;
  char pal_res[16][25]={"define", "imprimir", "leer", "Si", "SiNo", "Hacer", \
                        "FinSi", "Repetir", "Mientras", "Hasta", "entero", "flotante", "caracter"};
  pf=fopen("ArchivoAnalisis.txt"."rw");
  if (pf=NULL){
    fpats("Error",stderr);
    exit(1);
  }
  while ((caracter=fgetc(pf))!EOF) {
    printf("%c\n",caracter);
  }
  fclose(pf);

  char Estado;
  Estado=0;
  while (!EOF) {
    char Tkn=flex(caracter)
    printf("%s\n",Tkn);
    Estado=0;
      flex(char c){
      switch (c) {
        case ( c>=65 && c<=90 )||(c>=96 && c<=122)://Letras Mayusculas o Minusculas
          if (Estado==0||Estado==1||Estado==2||Estado==9) {
            Estado==1;
          }
          break;
        case (c<=57&&c>=48)://Numeros
          if (Estado==1||Estado==2) {
            Estado==2
          } else if (Estado==2||Estado==9) {
            Estado==8;
          } else if (Estado==9) {
            Estado==5;
          } else if (Estado==3||Estado==5) {
            Estado==3;
          } else if (Estado==4) {
            Estado==4;
          }else {
            Estado==7;
          }
          break;
        case '.':
            if (Estado==6) {
              Estado==7;
            } else if (Estado==3) {
              Estado==4;
            }
            break;
        case '\n':
            if (Estado==0||Estado==1||Estado==2) {
              printf("Tkn_cadena%s\n", );
            }else if((c=='-'||c=='+'||c=='/'||c=='*')&&(Estado==0||Estado==3||Estado==3||Estado==5)){
          		printf("Tkn_Operacion_Aritmetica%s\n");
          	}else if((c=='<'||c=='>'||c=='='||c=='!')&&(Estado==0||Estado==2||Estado==6)){
          		printf("Tkn_Relacion%s\n");
          	}else if((c=='<'||c=='-')&&(Estado==0||Estado==2||Estado==6||Estado==8)){
          		printf("Tkn_Asignacion%s\n");
          	}
            break;
        default;
        printf("Error de sintaxis\n");
        exit(1);
        }
      }
    }
  }
  return 0;
}
