-- 31/05/2023
Use SistemaAcademicoBCC

/*
	Cláusulas de consulta:
		SELECT
		FROM
		WHERE
		GROUP BY <-
		HAVING
		ORDER

	GROUP BY:
		Faz agrupamento de dados através de uma coluna-referência.
		exemplo:
			Agrupar quantidade de alunos por cidades:
*/				SELECT	COUNT(*) QTDE,
						ALU_CIDADE CIDADE
				FROM tbAluno
				GROUP BY ALU_CIDADE

--		"Separei em grupos, agora execute a função agregada para
--		cada um deles".
				SELECT	COUNT(*) QTDE,
						CUR_CODIGO
				FROM tbDisciplina
				GROUP BY CUR_CODIGO
/*
	Observação: Somente podemos exibir uma coluna a mais (nesse caso
	a CUR_CODIGO) fora do que estiver dentro da função COUNT() se estiver dentro
	da cláusula GROUP BY.

	Obs2: Convém exibir a coluna de agrupamento para discernir facilmente
	o agrupamento feito.
*/

-- Exercícios propostos em sala:

-- 1) Obter quantidade de cursos.
SELECT	COUNT(*) 'QTDE DE CURSOS', 
		CUR_NOME
FROM tbCurso
GROUP BY CUR_NOME

-- 2) Obter a média de carga horária dos cursos.
SELECT	AVG(CUR_CARGA_HORARIA) MEDIA_CH,
		CUR_NOME
FROM tbCurso
GROUP BY CUR_NOME
ORDER BY MEDIA_CH DESC

-- 3) Obter a quantidade de alunos do sexo masculino da cidade de Tianguá.
SELECT COUNT(*) 'Alunos de Tianguá'
FROM tbAluno
WHERE
	ALU_SEXO = 'M' AND
	ALU_CIDADE LIKE 'Tiangu[áa]'

-- 4) Obter a média de carga horária das disciplinas cujo curso é diferente de nulo.
SELECT	AVG(DIS_CARGA_HORARIA) MEDIA_CH,
		CUR_CODIGO
FROM tbDisciplina
WHERE CUR_CODIGO IS NOT NULL
GROUP BY CUR_CODIGO
ORDER BY MEDIA_CH DESC

-- 5) Obter a quantidade de disciplinas ofertadas a tarde no semestre 2 do ano de 2018.
SELECT COUNT(*)
FROM tbOfertaDisciplina -- FALTA COMPLETAR
WHERE 
	ODI_TURNO = 'Tarde' AND
	ODI_SEMESTRE = 2 AND
	ODI_ANO = 2018

-- 6) Obter maior, menor e a média de carga horária por nível de curso.
SELECT	CUR_NIVEL,
		MAX(CUR_CARGA_HORARIA) 'MAIOR_CH', 
		MIN(CUR_CARGA_HORARIA) 'MENOR_CH', 
		AVG(CUR_CARGA_HORARIA) 'MEDIA_CH'
FROM tbCurso
GROUP BY CUR_NIVEL

-- 7) Obter a quantidade de alunos por cidade.
SELECT 
	ALU_CIDADE CIDADE, 
	COUNT(*) QTDE
FROM tbAluno
GROUP BY ALU_CIDADE

-- 8) Obter a quantidade de disciplinas e o somatório da carga
-- horária das disciplinas por curso.
SELECT 
	CUR_CODIGO, 
	COUNT(*) 'QTDE_DISC',
	SUM(DIS_CARGA_HORARIA) 'SUM(CH)'
FROM tbDisciplina
GROUP BY CUR_CODIGO

-- 9) Obter a quantidade de disciplinas de Banco de Dados por curso.
SELECT 
	CUR_CODIGO, 
	COUNT(*) 'DISC_BD'
FROM tbDisciplina
WHERE DIS_NOME LIKE 'Banco de Dados%'
GROUP BY CUR_CODIGO

-- 10) Obter a quantidade de alunos do sexo feminino por cidade.
SELECT	COUNT(*) ALUNAS, 
		ALU_CIDADE CIDADE
FROM tbAluno
WHERE ALU_SEXO = 'F'
GROUP BY ALU_CIDADE
ORDER BY 'ALUNAS' DESC
		/*
			Aqui podemos ordenar por COUNT(*) ou pelo apelido dado 'ALUNAS'
		
			detalhe: somente podemos usar esse apelido na cláusula ORDER BY,
			pois ele só vale após o SELECT, tendo como ordem de execução:
				FROM > WHERE > GROUP BY > HAVING > SELECT > ORDER BY
		
			 É essencial manter a ordem de escrita:
			 SELECT
			 FROM
			 WHERE
			 GROUP BY
			 HAVING
			 ORDER BY
		*/