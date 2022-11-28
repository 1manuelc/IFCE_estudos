/* Codifique as regras equivalentes às seguintes sentenças:
a) Todo mundo que tem filhos é feliz.
b) Um casal é formado por duas pessoas que têm filhos em comum.
*/

pai(pai, filho).
pai(pai, filha).

mae(mae, filho).
mae(mae, filha).

casal(X,Y) :- pai(X,Z), mae(Y,Z).

feliz(X) :- pai(X,_) ; mae(X,_).