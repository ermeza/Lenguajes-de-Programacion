hombre(juan).
hombre(pedro).
hombre(judas).
hombre(mateo).
mujer(maria).
mujer(ruth).
mujer(lila).

progenitor(juan,pedro).
progenitor(juan,judas).
progenitor(maria,pedro).
progenitor(maria,judas).
progenitor(pedro,mateo).
progenitor(ruth,mateo).
progenitor(pedro,lila).
progenitor(ruth,lila).

hermano(X,Y):-progenitor(Z,X),progenitor(Z,Y),hombre(X).
hermana(X,Y):-progenitor(Z,X),progenitor(Z,Y),mujer(X).

tio(X,Y):-hermano(X,Z),progenitor(Z,Y),hombre(X).

abuelo(X,Y):-progenitor(Z,Y),progenitor(X,Z),hombre(X).
abuela(X,Y):-progenitor(Z,Y),progenitor(X,Z),mujer(X).

suma(A,B,R):-R is A+B.
resta(A,B,R):-R is A-B.

contar(A,B):- A=<B,write(A),nl,S is A+1,contar(S,B).


imprimirlista([]):-!.
imprimirlista([A|B]):-write(A),imprimirlista(B).

primero(A,[A|_]).


ultimo(X,[X|[]]).
ultimo(X,[_|Y]):-ultimo(X,Y).


miembro(X,[X|_]).
miembro(X,[_|Y]):-miembro(X,Y).


sumarlista([],0).
sumarlista([X|Xs],S):-sumarlista(Xs,S2),S is S2+X.


factorial(0,R):-R is 1.
factorial(N,R):-N>0,N1 is N-1,factorial(N1,R1),R is R1*N.

concatenar([],L,L).
concatenar([A|C1],L2,[A|C2]):-concatenar(C1,L2,C2).


duplicar(L,L1):-concatenar(L,L,L1).

adyacente(X,Y,[X,Y|_]):-!.
adyacente(X,Y,[_|L]):-adyacente(X,Y,L).





alumnoL([]).
alumnoL([_|Xs]):-alumnoL(Xs).

long([],0).
long([_|Xs],L):-long(Xs,Lc),L is Lc+1.

notas([]).
notas([X|Xs]):-number(X),X>=0,X=<100,notas(Xs).

sumar([],0).
sumar([X|Xs],S):-sumar(Xs,S2),S is S2+X.

%Regla para saber el promedio

promedio(X,R):-long(X,L),sumar(X,S),R is S/L.

calcProm(X,Prom):-claseCur(X,_,Z),promedio(Z,Prom),
                  write(X),
                 (Prom<65 -> write('Reprobado');
                  Prom>=65 -> write('Aprobado')).

genera(X,S,L):-claseCur(X,_,Z),sumar(Z,S),long(Z,L),genera(X,S,L).
calProm(X,Prom):-genera(X,S,L),Prom is S/L.
