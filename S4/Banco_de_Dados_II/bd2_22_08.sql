USE BD_JOIN

-- JOIN ou mant�m somente os dados que se correspondem entre as tabelas.
-- LEFT JOIN mant�m os dados da tabela � esquerda na consulta mesmo se n�o houver correspond�ncia.
-- RIGHT JOIN mant�m os dados da tabela � direita na consulta mesmo se n�o houver correspond�ncia.
-- FULL JOIN mant�m os dados de ambas as tabeles na consulta mesmo se n�o houver correspond�ncia.
-- CROSS JOIN equivale ao JOIN, mas com a linha ON como um WHERE.
-- , entre as tabelas equivale ao CROSS JOIN.

-- JOIN + ON = CROSS JOIN + WHERE (com a mesma condi��o de correspond�ncia entre as chaves)
/* A diferen�a � que o CROSS JOIN exige um custo computacional maior para filtrar os dados em outra cl�usula,
		diferente do JOIN que exige um ON para j� tratar em sequ�ncia a consulta. */
-- p.ex: cl�usula JOIN = 4 linhas, cl�usula CROSS JOIN = 16 linhas -> cl�usula WHERE = 4 linhas.

-- OBS:
-- * A import�ncia do CROSS JOIN aparece quando precisamos do produto cartesiano na consulta sem correspond�ncias.
-- * Usando o JOIN, n�o corremos o risco de esquecer a condi��o de correspond�ncia, pois � necess�ria para a cl�usula,
--		diferente do CROSS JOIN onde a mesma � opcional.

-- Mesmos resultados com condi��es iguais -> JOIN, CROSS JOIN, ",".
-- Mesmos resultados sem diferen�a alguma -> CROSS JOIN, ","

SELECT *
FROM tbDisciplina D CROSS JOIN tbProfessor P
WHERE D.PRO_CODIGO = P.PRO_CODIGO
