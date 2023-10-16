USE SistemaAcademicoBCC

-- 1) Obter os alunos.
SELECT * FROM tbAluno

/* 2) Obter o nome e a carga horária das disciplinas. Ordenar o resultado pelo
nome da disciplina. */
SELECT DIS_NOME, DIS_CARGA_HORARIA
FROM tbDisciplina
ORDER BY DIS_NOME

/* 3) Obter o nome dos alunos do sexo masculino da cidade de Tianguá
(Tiangua ou Tianguá). */
SELECT ALU_NOME FROM tbAluno
WHERE
	ALU_SEXO = 'M' AND
	ALU_CIDADE LIKE 'TIANGU[ÁA]'

-- 4) Obter a quantidade de cursos.
SELECT COUNT(*) 'QTDE_CURSOS'
FROM tbCurso

-- 5) Obter a quantidade de disciplinas.
SELECT COUNT(*) 'QTDE_DISCIPLINAS'
FROM tbDisciplina

-- 6) Obter a média da carga horária dos cursos de nível técnico.
SELECT AVG(CUR_CARGA_HORARIA) 'AVG_CARGA_HORARIA'
FROM tbCurso
WHERE CUR_NIVEL LIKE 'T[EÉ]CNICO'

-- 7) Obter a quantidade de alunos por cidade.
SELECT ALU_CIDADE, COUNT(*) 'QTDE_ALUNOS'
FROM tbAluno
GROUP BY ALU_CIDADE

/* 8) Obter a quantidade de disciplinas e o somatório da carga horária das
disciplinas por curso. */
SELECT 
	CUR_CODIGO, COUNT(*) 'QTDE_DISCIPLINAS', 
	SUM(DIS_CARGA_HORARIA) 'SUM_CARGA_HORARIA'
FROM tbDisciplina
GROUP BY CUR_CODIGO

-- 9) Obter a quantidade de disciplinas de Banco de Dados por curso.
SELECT CUR_CODIGO, COUNT(*) 'QTDE_DISC_BD'
FROM tbDisciplina
WHERE DIS_NOME LIKE '%BANCO DE DADOS%'
GROUP BY CUR_CODIGO

-- 10) Obter a quantidade de alunos do sexo feminino por cidade.
SELECT ALU_CIDADE, COUNT(*) 'QTDE_ALUNAS'
FROM tbAluno
WHERE ALU_SEXO = 'F'
GROUP BY ALU_CIDADE
