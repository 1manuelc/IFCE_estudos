USE BD_JOIN

-- JOIN ou mantém somente os dados que se correspondem entre as tabelas.
-- LEFT JOIN mantém os dados da tabela á esquerda na consulta mesmo se não houver correspondência.
-- RIGHT JOIN mantém os dados da tabela á direita na consulta mesmo se não houver correspondência.
-- FULL JOIN mantém os dados de ambas as tabeles na consulta mesmo se não houver correspondência.
-- CROSS JOIN equivale ao JOIN, mas com a linha ON como um WHERE.
-- , entre as tabelas equivale ao CROSS JOIN.

-- JOIN + ON = CROSS JOIN + WHERE (com a mesma condição de correspondência entre as chaves)
/* A diferença é que o CROSS JOIN exige um custo computacional maior para filtrar os dados em outra cláusula,
		diferente do JOIN que exige um ON para já tratar em sequência a consulta. */
-- p.ex: cláusula JOIN = 4 linhas, cláusula CROSS JOIN = 16 linhas -> cláusula WHERE = 4 linhas.

-- OBS:
-- * A importância do CROSS JOIN aparece quando precisamos do produto cartesiano na consulta sem correspondências.
-- * Usando o JOIN, não corremos o risco de esquecer a condição de correspondência, pois é necessária para a cláusula,
--		diferente do CROSS JOIN onde a mesma é opcional.

-- Mesmos resultados com condições iguais -> JOIN, CROSS JOIN, ",".
-- Mesmos resultados sem diferença alguma -> CROSS JOIN, ","

SELECT *
FROM tbDisciplina D CROSS JOIN tbProfessor P
WHERE D.PRO_CODIGO = P.PRO_CODIGO
