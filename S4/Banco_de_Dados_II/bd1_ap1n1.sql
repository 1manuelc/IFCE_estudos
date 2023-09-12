use SistemaAcademicoBCC

/* 1) Exibir o nome do curso e o nome dos alunos dos cursos de nível Graduação. 
Ordene o resultado pelo nome do curso. */
select CUR_NOME, ALU_NOME
from tbAluno A join tbCurso C
	on A.CUR_CODIGO = C.CUR_CODIGO
where CUR_NIVEL like 'GRADUA[ÇC][ÃA]O'
order by CUR_NOME


/* 2) Exibir o somatório da carga horária das disciplinas por curso. 
Ordene o resultado pelo nome do curso. */
select CUR_NOME, sum(DIS_CARGA_HORARIA) 'SUM_CARGA_HORARIA'
from tbDisciplina D join tbCurso C
	on D.CUR_CODIGO = C.CUR_CODIGO
group by CUR_NOME
order by CUR_NOME

/* 3) Exibir o nome dos alunos do professor Raimundo Maciel. 
Ordene o resultado pelo nome dos alunos. */
select distinct(ALU_NOME)
from tbAlunoMatricula AM join tbOfertaDisciplina OD
	on AM.ODI_CODIGO = OD.ODI_CODIGO
	join tbAluno A on AM.ALU_CODIGO = A.ALU_CODIGO
		join tbProfessor P on OD.PRO_CODIGO = P.PRO_CODIGO
where PRO_NOME = 'Raimundo Maciel'
order by ALU_NOME

/* 4) Exibir o nome dos professores que ensinam alguma disciplina do 
Curso Técnico em Informática no semestre 2 do ano 2014. 
Ordene o resultado pelo nome do professor. */
select PRO_NOME
from tbOfertaDisciplina OD join tbDisciplina D
	on OD.DIS_CODIGO = D.DIS_CODIGO
	join tbCurso C on D.CUR_CODIGO = C.CUR_CODIGO
		join tbProfessor P on OD.PRO_CODIGO = P.PRO_CODIGO
where
	C.CUR_NOME like 'T[ée]cnico em Inform[áa]tica' and
	OD.ODI_SEMESTRE = 2 and OD.ODI_ANO = 2014
order by P.PRO_NOME
