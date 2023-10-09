use SistemaAcademicoBCC
-- Exerc�cio 06, consultas n�o correlacionadas e correlacionadas.

/* a) Obter o nome das disciplinas do curso de Ci�ncia da Computa��o que possuem a maior
carga hor�ria. */
select DIS_NOME
from tbDisciplina join tbCurso
	on tbDisciplina.CUR_CODIGO = tbCurso.CUR_CODIGO
where 
	CUR_NOME like '%Ci�ncia da Computa��o' and
	DIS_CARGA_HORARIA = (
		select max(DIS_CARGA_HORARIA)
		from tbDisciplina
)

/* b) Obter o nome dos cursos de menor carga hor�ria em cada n�vel. Exibir tamb�m a carga
hor�ria e ordenar o resultado pela carga hor�ria em ordem decrescente. */
select CUR_NOME
from tbCurso C
where
	CUR_CARGA_HORARIA = (
		select min(CUR_CARGA_HORARIA)
		from tbCurso
		where C.CUR_NIVEL = CUR_NIVEL
	)
order by CUR_CARGA_HORARIA desc

-- c) Obter o nome do professor com maior tempo de servi�o.
select PRO_NOME
from tbProfessor
where PRO_DATA_ADMISSAO = (
	select min(PRO_DATA_ADMISSAO)
	from tbProfessor
)

/* d) Obter o nome dos cursos cuja carga hor�ria � superior a carga hor�ria de suas
disciplinas. */
select CUR_NOME
from tbCurso C
where
	CUR_CARGA_HORARIA > (
		select sum(DIS_CARGA_HORARIA)
		from tbDisciplina
		where tbDisciplina.CUR_CODIGO = C.CUR_CODIGO
	)

/* e) Obter o nome dos cursos de n�vel t�cnico que possuem carga hor�ria superior a carga
hor�ria de algum curso de n�vel de gradua��o. */
select CUR_NOME
from tbCurso
where
	CUR_NIVEL = 'T�cnico' and
	CUR_CARGA_HORARIA > any (
		select CUR_CARGA_HORARIA
		from tbCurso
		where CUR_NIVEL like 'Gradua��o'
	)

-- f) Obter o nome das disciplinas de menor carga hor�ria em cada curso.
select DIS_NOME
from tbDisciplina D
where 
	DIS_CARGA_HORARIA = (
		select min(DIS_CARGA_HORARIA)
		from tbDisciplina
		where D.CUR_CODIGO = CUR_CODIGO
	) 
