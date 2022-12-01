comida(amendoim).
comida(frango).

gosta(_, X) :- comida(X).

vivo(_,X) :- comida(X),!.