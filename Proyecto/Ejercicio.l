%{
#include <stdio.h>
int nc, np, nl;
%}
%%
/*----- Seccion de Reglas ----------------*/
[^ \t\n]+ { np++; nc += yylength; }
[ \t]+ { nc += yylength; }
$ { nl++; nc++; }
%%
/*----- Seccion de Procedimientos --------*/
int main (int argc, char *argv[])
{
if (argc == 2)
{
yyin = fopen (argv[1], "rt");
if (yyin == NULL)
{
printf ("El fichero %s no se puede abrir\n", argv[1]);
exit (-1);
}
}
else yyin = stdin;
nc = np = nl = 0;
yylex ();
printf ("%d\t%d\t%d\n", nc, np, nl);
return 0;
}
