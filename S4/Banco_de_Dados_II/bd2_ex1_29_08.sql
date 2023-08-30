-- BD2 - Exercício I

use SistemaAcademicoBCC

-- 1) Obter o nome do aluno e o nome do curso que ele está associado.
select ALU_NOME, CUR_NOME
from tbAluno A join tbCurso C
	on A.CUR_CODIGO = C.CUR_CODIGO

/* 2) Obter o nome e a carga horária das disciplinas do curso de Bacharelado em Ciência da
Computação. Ordene o resultado pelo nome da disciplina.*/
select DIS_NOME, DIS_CARGA_HORARIA
from tbDisciplina D join tbCurso C
	on D.CUR_CODIGO = C.CUR_CODIGO
where CUR_NOME like 'Bacharelado em Ci[êe]ncia da Computa[çc][ãa]o'
order by DIS_NOME

/* 3) Obter a quantidade de alunos do curso do sexo feminino de cada curso. Exibir, além da
quantidade, o nome do curso. Ordenar o resultado pela quantidade (em ordem decrescente).*/
select count(ALU_CODIGO) 'QTD_ALUNAS_P_CURSO', C.CUR_NOME
from tbAluno A join tbCurso C
	on A.CUR_CODIGO = C.CUR_CODIGO
where ALU_SEXO = 'F'
group by CUR_NOME
order by QTD_ALUNAS_P_CURSO desc

/* 4) Obter o nome do professor e a quantidade de disciplinas que ele ministrou no semestre 1 do
ano 2022.*/
select PRO_NOME, count(DIS_CODIGO) 'QTD_DISC_MINIST'
from tbProfessor P join tbOfertaDisciplina OD
	on P.PRO_CODIGO = OD.PRO_CODIGO
where OD.ODI_SEMESTRE = 1 and OD.ODI_ANO = 2022
group by PRO_NOME

/* 5) Obter o nome e a carga horária das disciplinas ofertadas no semestre 2 do ano 2022 para o
curso Bacharelado em Ciência da Computação.*/
select DIS_NOME, DIS_CARGA_HORARIA
from tbDisciplina D join tbOfertaDisciplina OD
	on D.DIS_CODIGO = OD.DIS_CODIGO
	join tbCurso C
		on D.CUR_CODIGO = C.CUR_CODIGO
where
	OD.ODI_SEMESTRE = 2 and
	OD.ODI_ANO = 2022 and
	C.CUR_NOME like 'Bacharelado em Ci[êe]ncia da Computa[çc][ãa]o'

/* 6) Obter o nome de cada curso com a respectiva quantidade de alunos. Exibir apenas os cursos
cuja quantidade de alunos é superior a 5. Ordenar o resultado pela quantidade de alunos.*/
select CUR_NOME, count(ALU_CODIGO) 'QTD_ALU'
from tbAlunoMatricula AM join tbOfertaDisciplina OD
	on AM.ODI_CODIGO = OD.ODI_CODIGO
	join tbDisciplina D
		on OD.DIS_CODIGO = D.DIS_CODIGO
		join tbCurso C
			on C.CUR_CODIGO = D.CUR_CODIGO
group by CUR_NOME
having count(ALU_CODIGO) > 5
order by QTD_ALU

/* 7) Obter a quantidade de disciplinas que cada professor ministrou no semestre 1 do ano 2018.
Exibir apenas os professores que ministraram mais de uma disciplina. Exibir também o nome
do professor. Ordene o resultado pela quantidade de disciplinas. */
select PRO_NOME, count(DIS_CODIGO) 'QTD_DISC_MINS_P_PRO'
from tbOfertaDisciplina OD join tbProfessor P
	on OD.PRO_CODIGO = P.PRO_CODIGO
where
	OD.ODI_SEMESTRE = 1 and
	OD.ODI_ANO = 2018
group by PRO_NOME
having count(DIS_CODIGO) > 1
order by QTD_DISC_MINS_P_PRO
