use SistemaAcademicoBCC
-- Exercício 06, consultas não correlacionadas e correlacionadas.

/* a) Obter o nome das disciplinas do curso de Ciência da Computação que possuem a maior
carga horária. */
select DIS_NOME
from tbDisciplina join tbCurso
	on tbDisciplina.CUR_CODIGO = tbCurso.CUR_CODIGO
where 
	CUR_NOME like '%Ciência da Computação' and
	DIS_CARGA_HORARIA = (
		select max(DIS_CARGA_HORARIA)
		from tbDisciplina
)

/* b) Obter o nome dos cursos de menor carga horária em cada nível. Exibir também a carga
horária e ordenar o resultado pela carga horária em ordem decrescente. */
select CUR_NOME
from tbCurso C
where
	CUR_CARGA_HORARIA = (
		select min(CUR_CARGA_HORARIA)
		from tbCurso
		where C.CUR_NIVEL = CUR_NIVEL
	)
order by CUR_CARGA_HORARIA desc

-- c) Obter o nome do professor com maior tempo de serviço.
select PRO_NOME
from tbProfessor
where PRO_DATA_ADMISSAO = (
	select min(PRO_DATA_ADMISSAO)
	from tbProfessor
)

/* d) Obter o nome dos cursos cuja carga horária é superior a carga horária de suas
disciplinas. */
select CUR_NOME
from tbCurso C
where
	CUR_CARGA_HORARIA > (
		select sum(DIS_CARGA_HORARIA)
		from tbDisciplina
		where tbDisciplina.CUR_CODIGO = C.CUR_CODIGO
	)

/* e) Obter o nome dos cursos de nível técnico que possuem carga horária superior a carga
horária de algum curso de nível de graduação. */
select CUR_NOME
from tbCurso
where
	CUR_NIVEL = 'Técnico' and
	CUR_CARGA_HORARIA > any (
		select CUR_CARGA_HORARIA
		from tbCurso
		where CUR_NIVEL like 'Graduação'
	)

-- f) Obter o nome das disciplinas de menor carga horária em cada curso.
select DIS_NOME
from tbDisciplina D
where 
	DIS_CARGA_HORARIA = (
		select min(DIS_CARGA_HORARIA)
		from tbDisciplina
		where D.CUR_CODIGO = CUR_CODIGO
	) 
