%{
#include <stdio.h>
#include <math.h>
#define MAX 100
void Salir();
%}
struct token
{
  char tokens[MAX];
}token1;

DIGITO   [0-9]
CADENA   [A-Za-z][A-Za-z0-9]*
VARIABLE ({'define'})\({TIPODATO})\[A-Z][a-z0-9]*
TIPODATO {'entero'}|{'flotante'}|{'caracter'}
%%
TIPODATO {ECHO;}

{DIGITO}+   {
            strcpy(token1.tokens, "Tkn_Entero\n");
            fwrite (&token1, sizeof(token1), 1, Tokens);

            printf( "Un entero: %s (%d)\n", yytext,
                    atoi( yytext ) );
            }

{DIGITO}+"."{DIGITO}*      {
            strcpy(token1.tokens, "Tkn_Real\n");
            fwrite (&token1, sizeof(token1), 1, Tokens);
            printf( "Un real: %s (%g)\n", yytext,
                    atof( yytext ) );
            }

Si|Hacer|SiNo|FinSi|Mientras|Hasta|Repetir|define|imprimir|leer {
            strcpy(token1.tokens, "Tkn_Palabra_Clave\n");
            fwrite (&token1, sizeof(token1), 1, Tokens);
            printf( "Una palabra clave: %s\n", yytext );
            }
Salir	    { Salir();
	    }

{CADENA}     {
            strcpy(token1.tokens, "Tkn_Palabra_Clave\n");
            fwrite (&token1, sizeof(token1), 1, Tokens);
            printf( "Una Cadena: %s\n", yytext );
            }

{VARIABLE}     {
            strcpy(token1.tokens, "Tkn_Variable\n");
            fwrite (&token1, sizeof(token1), 1, Tokens);
            printf( "Una Variable: %s\n", yytext );
   }

"+"|"-"|"*"|"/"  {
                strcpy(token1.tokens, "Tkn_Operador_Aritmetico\n");
                fwrite (&token1, sizeof(token1), 1, Tokens);
                printf( "Un operador: %s\n", yytext );
                }

"<"|">"|"<="|">="  {
                  strcpy(token1.tokens, "Tkn_Relacion\n");
                  fwrite (&token1, sizeof(token1), 1, Tokens);
                  printf( "Un operador de relacion: %s\n", yytext );
                  }

"{"[^}\n]*"}"     /* se come una linea de comentarios */

[ \t\n]+          /* se come los espacios en blanco */

.           printf( "Caracter no reconocido: %s\n", yytext );

%%

int main (int argc, char *argv[], char *args[])
{
FILE *pf,*Tokens;
if (argc == 2)
{
pf = fopen (argv["ArchivoAnalisis.txt"], "rt");
Tokens = fopen(args["Tokens.Txt"],"w+")
if (yyin == NULL)
{
printf ("El fichero %s no se puede abrir\n", argv[1]);
exit (-1);
}
}
else
  yyin = pf;
  yyparse();
  yylex ();
  fclose(pf);
  fclose(Tokens)
return 0;
}

void Salir(){
	printf("Saliendo...");
	exit(0);
}
