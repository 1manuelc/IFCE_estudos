pai(adao, cain).
pai(adao, abel).
pai(adao, seth).
pai(seth, enos).

filho(X,Y) :- pai(Y,X).
irmao(X,Y) :- pai(Z,X), pai(Z,Y), X\=Y.
tio(X,Y) :- irmao(X, pai(_,Y)).
avo(X,Y) :- pai(X,Z), pai(Z,Y).
neto(X,Y) :- avo(Y,X).