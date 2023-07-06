-- 06/06/2023
/*
	Cláusula HAVING (Condição após a criação do grupo): 
	Também é uma cláusula de condição, assim como o WHERE,
	mas utilizando funções agregadas para selecionar valores
	dentro da cláusula GROUP BY.

	Só existe se houver agrupamentos por GROUP BY.

	exemplo:
		SELECT ALU_CIDADE, COUNT(*) Q
		FROM tbAluno
		WHERE ALU_SEXO = 'M'
		GROUP BY ALU_CIDADE
		HAVING COUNT(*) > 1

		De tbAluno
		São selecionados a quantidade de alunos e a cidade
			Onde o sexo do aluno é Masculino
			Agrupando por cidade
				Onde a quantidade de alunos do agrupamento é maior que 1

*/

USE SistemaAcademicoBCC

/* 1) Obter a quantidade de alunos por cidade. 
Exibir apenas as cidades que possuem mais de 10 alunos. */
SELECT ALU_CIDADE, COUNT(*) QTDE
FROM tbAluno
GROUP BY ALU_CIDADE
HAVING COUNT(*) > 10

/* 2) Obter o somatório da carga horária e a quantidade das
disciplinas por curso. Exibir apenas os cursos que possuem mais
de duas disciplinas. */
SELECT SUM(DIS_CARGA_HORARIA) 'SUM(CH)', COUNT(*) QTDE
FROM tbDisciplina
GROUP BY CUR_CODIGO
HAVING COUNT(*) > 2

/* 3) Obter a média de carga horária dos cursos por nível.
Exibir apenas os cursos de nível Superior ou Graduação;
e apenas os cursos em que a menor carga horária é 
superior a 3000 horas. */
SELECT AVG(CUR_CARGA_HORARIA)
FROM tbCurso
WHERE
	CUR_NIVEL IN ('Superior', 'Graduação')
GROUP BY CUR_NIVEL
HAVING
	MIN(CUR_CARGA_HORARIA) > 3000

/* 4) Obter a quantidade de disciplinas ofertada por professor no
semestre 2 do ano 2014. Exibir os professores que possuem mais de
1 disciplina.*/
SELECT PRO_CODIGO, COUNT(*) 'QTDE_DISC'
FROM tbOfertaDisciplina
WHERE
	ODI_SEMESTRE = 2 AND
	ODI_ANO = 2014
GROUP BY PRO_CODIGO
HAVING COUNT(*) > 2

/* 5) Obter a média de carga horária e a quantidade de disciplinas
de Programação por curso. Exibir apenas quando possuir mais de 1 disciplina.*/
SELECT 
	CUR_CODIGO, 
	AVG(DIS_CARGA_HORARIA) 'AVG(CH)', 
	COUNT(*) 'QTDE_DIS_PROG'
FROM tbDisciplina
WHERE DIS_NOME LIKE '%Programação%'
GROUP BY CUR_CODIGO
HAVING COUNT(*) > 1

/* 6) Obter a quantidade de disciplinas por carga horária. Exibir apenas quando
houver mais de uma disciplina por carga horária. Ordene o resultado por carga 
horária. */
SELECT DIS_CARGA_HORARIA, COUNT(*) 'QTDE_DISC'
FROM tbDisciplina
GROUP BY DIS_CARGA_HORARIA
HAVING COUNT(*) > 1
ORDER BY DIS_CARGA_HORARIA DESC

/* 7) Obter a quantidade de alunos das cidades de Icapuí ou Aracati por sexo.
Exibir apenas quando possuir mais de 5 alunos. 
Ordene o resultado pela quantidade.*/
SELECT ALU_SEXO, COUNT(*) 'ALU_QTDE'
FROM tbAluno
WHERE
	ALU_CIDADE LIKE 'Icapu[íi]' OR
	ALU_CIDADE = 'Aracati'
GROUP BY ALU_SEXO
HAVING COUNT(*) > 5
ORDER BY COUNT(*) DESC