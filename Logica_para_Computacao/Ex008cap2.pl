/*
2.5. O peso ideal para uma modelo é no máximo 62.1*Altura–44.7 . Além

disso, para ser modelo, uma mulher precisa ter mais que 1.70m de altu-
ra e menos de 25 anos de idade. Com base nessas informações, e conside-
rando a tabela do exercício anterior, defina um predicado capaz de recu-
perar apenas os nomes das mulheres que podem ser modelos.
*/

pessoa('Ana', 'fem', 23, 1.55, 56.0).
pessoa('Bia', 'fem', 19, 1.71, 61.3).
pessoa('Ivo', 'masc', 22, 1.80, 70.5).
pessoa('Lia', 'fem', 17, 1.85, 57.3).
pessoa('Eva', 'fem', 28, 1.75, 68.7).
pessoa('Ary', 'masc', 25, 1.72, 68.9).

modelo(N) :- pessoa(N, 'fem', I, A, P), A > 1.70, I < 25, P =< 62.1 * A - 44.7.