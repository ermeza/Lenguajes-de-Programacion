#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<stderr>


//---------------------------------------------------------------------------

int int main(int argc, char const *argv[]) {
  FILE *pf;
  char caracter;
  char letraMa[30];
  char letraMi[30];
  int numero[10]={0,1,2,3,4,5,6,7,8,9};
  char pal_res[16][25]={"define", "imprimir", "leer", "Si", "SiNo", "Hacer", \
  "FinSi", "Repetir", "Mientras", "Hasta", "entero", "flotante", "caracter"};
  pf=fopen(""."rw");
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
    enumTkn flex(char c){
      switch (c) {
        case letraMa:
          if (Estado==0||Estado==1||Estado==2||Estado==9) {
            Estado==1;
          }
          break;
        case numero:
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
        case '.':
            if (Estado==6) {
              Estado==7;
            } else if (Estado==3) {
              Estado==4;
            }
        default;
        printf("Error de sintaxis\n");
        exit(1); 
        }
      }
    }
  }
  return 0;
}
