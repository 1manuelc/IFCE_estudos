Use SistemaAcademicoBCC

/* 1) Exibir o Nome das disciplinas que contém no nome Programação
e que possuem carga horária entre 40 e 120 horas. Ordenar o 
resultado pela carga horária de forma decrescente. */
SELECT DIS_CARGA_HORARIA, DIS_NOME
FROM tbDisciplina
WHERE
	DIS_NOME LIKE '%Programação%' AND
	DIS_CARGA_HORARIA BETWEEN 40 AND 120
ORDER BY DIS_CARGA_HORARIA DESC

/* 2) Exibir a quantidade de cursos de nível Técnico que possuem 
carga horária abaixo de 1000 horas.*/
SELECT COUNT(*) 'QTDE'
FROM tbCurso
WHERE
	CUR_NIVEL = 'Técnico' AND
	CUR_CARGA_HORARIA < 1000

/* 3) Exibir a quantidade de cursos de cada nível. Exibir a 
quantidade e a o nível. Ordenar o resultado pela quantidade.*/
SELECT CUR_NIVEL, COUNT(*) 'QTDE'
FROM tbCurso
GROUP BY CUR_NIVEL
ORDER BY QTDE

/* Exibir o total de alunos do sexo masculino por cidade. Exibir
apenas as cidades que possuem acima de 2 alunos nessa condição.
Ordene o resultado pelo nome da cidade.*/
SELECT ALU_CIDADE 'CIDADE', COUNT(*) 'QTDE_ALUNOS'
FROM tbAluno
WHERE ALU_SEXO = 'M'
GROUP BY ALU_CIDADE
HAVING COUNT(*) > 2
ORDER BY CIDADE
