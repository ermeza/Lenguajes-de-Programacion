%{
#include <stdio.h>
#include <math.h>
void Salir();
%}

DIGITO   [0-9]
CADENA   [A-Za-z][A-Za-z0-9]*
ID	 ['define'TIPODATO][A-Z][A-Za-z0-9]*
TIPODATO {'entero'}|{'flotante'}|{'caracter'}
%%
TIPODATO {ECHO;}

{DIGITO}+   {
            printf( "Un entero: %s (%d)\n", yytext,
                    atoi( yytext ) );
            }

{DIGITO}+"."{DIGITO}*      {
            
            printf( "Un real: %s (%g)\n", yytext,
                    atof( yytext ) );
            }

Si|Hacer|SiNo|FinSi|Mientras|Hasta|Repetir|define|imprimir|leer {
           
            printf( "Una palabra clave: %s\n", yytext );
            }
Salir	    { Salir();
	    }

{CADENA}     	printf( "Una Cadena: %s\n", yytext );


{ID}     	printf( "Una Variable: %s\n", yytext );

"+"|"-"|"*"|"/"    printf( "Un operador: %s\n", yytext );
                

"<"|">"|"<="|">="  printf( "Un operador de relacion: %s\n", yytext );
                  

"{"[^}\n]*"}"     /* se come una linea de comentarios */

[ \t\n]+          /* se come los espacios en blanco */

.           printf( "Caracter no reconocido: %s\n", yytext );

%%

int main (int argc, char *argv[])
{
FILE *pf;
if (argc == 2)
{
pf = fopen ("ArchivoAnalisis.txt", "r");
if (pf == NULL)
{
printf ("El fichero %s no se puede abrir\n", argv[1]);
exit (-1);
}
}
else
  yyin = pf;
  yylex ();
  fclose(pf);
return 0;
}

void Salir(){
	printf("Saliendo...");
	exit(0);
}
