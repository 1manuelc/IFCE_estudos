% pais(Nome, Área, População)
pais(brasil, 9, 130).
pais(china, 12, 1800).
pais(eua, 9, 230).
pais(india, 3, 450).

/* Inclua no Programa 2.1 uma regra para o predicado dens(P,D), que
relaciona cada pais P à sua densidade demográfica correspondente D.
Em seguida, faça consultas para descobrir:
a) qual a densidade demográfica de cada um dos paises;
b) se a india é mais populosa que a China.
*/

% a) pais(Nomepais,Area,Pop), Dens is Pop/Area.
% b) pais(pais1,_,Pop1), pais(pais2,_,Pop2), Pop1 > Pop2.