%Nombre de las Personas con identificando su sexo
hombre(juan).
hombre(pedro).
hombre(judas).
hombre(mateo).
mujer(maria).
mujer(ruth).
mujer(lila).
mujer(juana).

%Carreras Disponibles
carreras(is).%is = Ingenieria en Sistemas
carreras(im).%im = Ingenieria Mecanica
carreras(ie).%ie = Ingenieria Electrica

%Asigando las personas a las carreras
alumno(is,juan).
alumno(is,pedro).
alumno(im,judas).
alumno(im,mateo).
alumno(ie,maria).
alumno(is,ruth).
alumno(is,lila).
alumno(is,juana).

%Clases que se imparten en cada Carrera en lista
clases(is,[intro_is,progr1,progr2,algo_estr,poo,leng_pro]).
clases(im,[intr_im, mecanica, electronica]).
clases(ie,[intro_ie,cir_elec,elec_magn]).

%Clases asignadas individualmente
clases(is,intro_is).
clases(is,progr1).
clases(is,progr2).
clases(is,algo_estr).
clases(is,poo).
clases(is,leng_pro).
clases(im,intr_im).
clases(im,mecanica).
clases(im,electronica).
clases(ie,intro_ie).
clases(ie,cir_elec).
clases(ie,elec_magn).


%Asignar clases a Alumno y nota obtenida
% El primer valor es para poder identificar cuantas clases a cursado y
% asi poder calcular el promedio.
claseCur(1,juan,progr1,80).
claseCur(2,juan,progr2,65).
claseCur(3,juan,algo_estr,50).
claseCur(1,pedro,progr2,70).
claseCur(2,pedro,algo_estr,60).
claseCur(1,judas,intro_im,70).
claseCur(2,judas,mecanica,60).
claseCur(1,mateo,mecanica,65).
claseCur(2,mateo,electronica,54).
claseCur(1,maria,intro_ie,80).
claseCur(1,ruth,intro_is,85).
claseCur(1,lila,intro_is,72).
claseCur(2,lila,progr1,35).
claseCur(1,juana,poo,71).
claseCur(2,juana,algo_estr,81).


%Regla para saber si un alumno aprobo una clase
aprobo(X,Y):-claseCur(_,X,Y,Z),Z>=65.


%Regla para listar las Clases tanto Aprobadas como Reprobada
listaCla(X):-claseCur(_,X,Y,Z),
              writeln(Y),
              (Z<65 -> write('Reprobo la Clase');
               Z>=65 -> write('Aprobo la Clase')).

%Regla para calcular el promedio total de un Alumno(X).
calcProm(X,P):-L=1,claseCur(L,X,_,Z),S is L+1,
                 sumanota(X,N,S) , promedio(Z,N,S,P),
                 (P<65 -> write('Reprobado');
                  P>=65 -> write('Aprobado')).

sumanota(X,N,L):- claseCur(L,X,_,Z), N is Z.%Suma las notas de X alumno
promedio(Z,N,S,P):-P is ((Z+N)/S).%Regla para calcular promerio
