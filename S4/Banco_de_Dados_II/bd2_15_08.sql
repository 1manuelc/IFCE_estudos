USE SistemaAcademicoBCC

-- 1) Nome do curso de cada disciplina
SELECT DIS_NOME, CUR_NOME
FROM tbDisciplina JOIN tbCurso
ON tbDisciplina.CUR_CODIGO = tbCurso.CUR_CODIGO

-- 2) Nome dos alunos do curso Bacharelado em Ci�ncia da Computa��o
SELECT ALU_NOME, CUR_NOME
FROM tbAluno JOIN tbCurso
ON tbAluno.CUR_CODIGO = tbCurso.CUR_CODIGO
WHERE CUR_NOME LIKE 'Bacharelado em Ci[�e]ncia da Computa[�c][�a]o'

-- 3) Nome dos alunos da disciplina de Banco de Dados II
-- Modo errado (tbAluno -> tbCurso -> tbDisciplina)
SELECT ALU_NOME, DIS_NOME
FROM tbAluno A JOIN tbCurso C
	ON A.CUR_CODIGO = C.CUR_CODIGO
	JOIN tbDisciplina D
		ON D.CUR_CODIGO = C.CUR_CODIGO
WHERE DIS_NOME LIKE 'BANCO DE DADOS II'

-- Modo certo (tbAluno -> tbOfertaDisciplina -> tbDisciplina)
SELECT ALU_NOME
FROM tbAluno A JOIN tbAlunoMatricula AM
ON A.ALU_CODIGO = AM.ALU_CODIGO
	JOIN tbOfertaDisciplina OD
ON AM.ODI_CODIGO = OD.ODI_CODIGO 
	JOIN tbDisciplina DS
ON DS.DIS_CODIGO = OD.DIS_CODIGO
WHERE DIS_NOME LIKE 'BANCO DE DADOS II'

-- 4) Quantidade de professores vinculados �s disciplinas de Computa��o
-- tbProfessor -> tbOfertaDisciplina -> tbDisciplina -> tbCurso
SELECT COUNT(DISTINCT PRO_NOME) 'QTD_PRO_BCC'
FROM tbProfessor P JOIN tbOfertaDisciplina OD
	ON P.PRO_CODIGO = OD.PRO_CODIGO
JOIN tbDisciplina D
	ON OD.DIS_CODIGO = D.DIS_CODIGO
JOIN tbCurso C
	ON D.CUR_CODIGO = C.CUR_CODIGO
WHERE CUR_NOME LIKE 'Bacharelado em Ci[e�]ncia da Computa[�c][�a]o'