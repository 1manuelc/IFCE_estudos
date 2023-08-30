USE SistemaAcademicoBCC

/* 1) Obter o nome das disciplinas e o nome dos
cursos aos quais são vinculadas */ 
SELECT DIS_NOME, CUR_NOME
FROM tbDisciplina D JOIN tbCurso C
	ON D.CUR_CODIGO = C.CUR_CODIGO

/* 2) Obter os dados dos alunos dos cursos de 
nível Técnico */
SELECT A.*
FROM tbAluno A JOIN tbCurso C
	ON A.CUR_CODIGO = C.CUR_CODIGO
WHERE CUR_NIVEL LIKE 'T[ÉE]CNICO'

/* 3) Obter o nome e a matrícula dos alunos do 
curso de Bacharelado em Ciência da Computação */
SELECT ALU_NOME, ALU_MATRICULA
FROM tbAluno A JOIN tbCurso C
	ON A.CUR_CODIGO = C.CUR_CODIGO
WHERE CUR_NOME LIKE 'BACHARELADO EM CI[ÊE]NCIA DA COMPUTA[ÇC][ÃA]O'

/* 4) Obter o nome a carga horária das disciplinas
ofertadas no semestre 2 do ano 2014. Ordene o 
resultado pela carga horária.*/
SELECT DISTINCT(DIS_NOME), DIS_CARGA_HORARIA
FROM tbDisciplina D JOIN tbOfertaDisciplina OD
	ON D.DIS_CODIGO = OD.DIS_CODIGO
WHERE 
	OD.ODI_SEMESTRE = 2 AND OD.ODI_ANO = 2014
ORDER BY D.DIS_CARGA_HORARIA

/* 5) Obter o nome dos professores (de forma distinta) 
que ministram disciplina no semestre 2 do ano 2014.*/
SELECT DISTINCT(PRO_NOME)
FROM tbProfessor P JOIN tbOfertaDisciplina OD
	ON P.PRO_CODIGO = OD.PRO_CODIGO
WHERE OD.ODI_SEMESTRE = 2 AND OD.ODI_ANO = 2014

/* 6) Obter a quantidade de disciplinas do curso de 
Ciência da Computação. */
SELECT COUNT(DIS_CODIGO) 'QTDE_DISC_CC'
FROM tbDisciplina D JOIN tbCurso C
	ON D.CUR_CODIGO = C.CUR_CODIGO
WHERE C.CUR_NOME LIKE '%CI[ÊE]NCIA DA COMPUTA[ÇC][ÃA]O'

/* 7) Obter o nome da disciplinas ofertadas no turno 
da noite do semestre 2 do ano 2014, com o nome do 
respectivo professor.*/
SELECT DIS_NOME, PRO_NOME
FROM tbDisciplina D JOIN tbOfertaDisciplina OD
	ON D.DIS_CODIGO = OD.DIS_CODIGO
	JOIN tbProfessor P
		ON OD.PRO_CODIGO = P.PRO_CODIGO
WHERE 
	OD.ODI_TURNO LIKE 'Noite' AND
	OD.ODI_SEMESTRE = 2 AND
	OD.ODI_ANO = 2014

/* 8) Obter o nome dos alunos que cursam a disciplina 
de Banco de Dados I no semestre 2 do ano 2014.*/
SELECT ALU_NOME
FROM tbAlunoMatricula AM JOIN tbAluno A
	ON AM.ALU_CODIGO = A.ALU_CODIGO
	JOIN tbOfertaDisciplina OD
		ON AM.ODI_CODIGO = OD.ODI_CODIGO
		JOIN tbDisciplina D
			ON D.DIS_CODIGO = OD.DIS_CODIGO
WHERE
	D.DIS_NOME LIKE 'BANCO DE DADOS I' AND
	OD.ODI_SEMESTRE = 2 AND OD.ODI_ANO = 2014

/* 9) Obter o nome e a carga horária das disciplinas 
ofertadas no semestre 2 do ano 2014 para o curso 
Bacharelado em Ciência da Computação. */
SELECT DISTINCT(DIS_NOME), DIS_CARGA_HORARIA
FROM tbOfertaDisciplina OD JOIN tbDisciplina D
	ON OD.DIS_CODIGO = D.DIS_CODIGO
WHERE OD.ODI_SEMESTRE = 2 AND OD.ODI_ANO = 2014

/* 10) Obter a quantidade de alunos matriculados 
por disciplina no semestre 2 do ano 2014. 
Exibir apenas as disciplinas que possuem mais de 5 alunos.
Ordene o resultado pela quantidade de alunos. */
SELECT COUNT(A.ALU_CODIGO) 'QTD_ALU_P_DISC'
FROM tbAluno A JOIN tbAlunoMatricula AM
	ON A.ALU_CODIGO = AM.ALU_CODIGO
	JOIN tbOfertaDisciplina OD
		ON AM.ODI_CODIGO = OD.ODI_CODIGO
		JOIN tbDisciplina D
			ON D.DIS_CODIGO = OD.DIS_CODIGO
WHERE OD.ODI_SEMESTRE = 2 AND OD.ODI_ANO = 2014
GROUP BY DIS_NOME
HAVING COUNT(A.ALU_CODIGO) > 5
ORDER BY QTD_ALU_P_DISC
