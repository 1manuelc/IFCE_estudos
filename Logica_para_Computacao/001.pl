mae(ana,eva).
mae(eva,noe).
mae(bia,rai).
mae(bia,clo).
mae(bia,ary).
mae(lia,gal).

pai(ivo,eva).
pai(rai,noe).
pai(gil,rai).
pai(gil,clo).
pai(gil,ary).
pai(ary,gal).

mulher(ana).
mulher(eva).
mulher(bia).
mulher(clo).
mulher(lia).
mulher(gal).

homem(ivo).
homem(rai).
homem(noe).
homem(gil).
homem(ary).

%regras
gerou(X,Y) :- pai(X,Y);
    mae(X,Y).

filho(X) :- gerou(_,X),
    homem(X).

filho(X,Y) :- gerou(Y,X),
    homem(X).

filha(X,Y) :- gerou(Y,X),
    mulher(X).

irmao(X,Y) :- pai(Z,X),
    pai(Z,Y),
    X \= Y,
    homem(X).

irmao(X,Y) :- mae(Z,X),
    mae(Z,Y),
    X \= Y,
    homem(X).

irma(X,Y) :- pai(Z,X),
    pai(Z,Y),
    X \= Y,
    mulher(X).

irma(X,Y) :- mae(Z,X),
    mae(Z,Y),
    X \= Y,
    mulher(X). 

tio(X,Y) :- (mae(Z,Y);pai(Z,Y)),
	irmao(X,Z).

tia(X,Y) :- (pai(Z,Y);mae(Z,Y)),
	irma(X,Z).

% x é primo de y se o pai de x é irmao do pai de Y
%                     pai de x é irmao da mae de y
% x é primo de y se a mae de x é irma do pai de Y
%                     mae de x é irma da mae de y
%                     
% x é primo de y se y é filho do Tio de x
%                   y é filho da Tia de x
% x é primo de y se y é filha do Tio de x
%                   y é filha da Tia de x

primo(X,Y) :- filho(Y,Z),
    (tio(Z,X);tia(Z,X)),
    homem(X).

primo(X,Y) :- filha(Y,Z),
    (tio(Z,X);tia(Z,X)),
    homem(X).

prima(X,Y) :- filho(Y,Z),
    (tio(Z,X);tia(Z,X)),
    mulher(X).

prima(X,Y) :- filha(Y,Z),
    (tio(Z,X);tia(Z,X)),
    mulher(X).