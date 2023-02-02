/*
Codifique um programa contendo as informações da tabela abaixo e faça
as consultas indicadas a seguir:

Nome    Sexo    Idade   Altura  Peso
Ana     fem     23      1.55    56.0
Bia     fem     19      1.71    61.3
Ivo     masc    22      1.80    70.5
Lia     fem     17      1.85    57.3
Eva     fem     28      1.75    68.7
Ary     masc    25      1.72    68.9

a) Quais são as mulheres com mais de 20 anos de idade?
b) Quem tem pelo menos 1.70m de altura e menos de 65kg?
c) Quais são os possíveis casais onde o homem é mais alto que a mulher?
*/

% pessoa(Nome,Sexo,Idade,Altura,Peso).
pessoa('Ana', 'fem', 23, 1.55, 56.0).
pessoa('Bia', 'fem', 19, 1.71, 61.3).
pessoa('Ivo', 'masc', 22, 1.80, 70.5).
pessoa('Lia', 'fem', 17, 1.85, 57.3).
pessoa('Eva', 'fem', 28, 1.75, 68.7).
pessoa('Ary', 'masc', 25, 1.72, 68.9).

% a) pessoa(N, 'fem', I, _, _), I > 20.
% b) pessoa(N, _, _, A, P), A >= 1.70, P < 65.0.
% c) pessoa(Nh, 'masc', _, Ah, _), pessoa(Nm, 'fem', _, Am, _), Ah > Am.