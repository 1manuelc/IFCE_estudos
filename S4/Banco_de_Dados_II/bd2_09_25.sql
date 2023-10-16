use BD_Empresa
-- Subconsultas correlacionadas
-- (consultas internas dependem de dados da consulta externa)
-- slide da Aula 03

-- ex01: Obter o nome dos funcion�rios cujo sal�rio � maior que 
-- a m�dia de sal�rio do seu departamento.
select FUN_NOME, FUN_SALARIO, F_E.DEP_CODIGO
from tbFuncionario F_E
where FUN_SALARIO > (
	select avg(FUN_SALARIO)
	from tbFuncionario
	where DEP_CODIGO = F_E.DEP_CODIGO
)

-- ex02: Obter o nome dos funcion�rios que possuem o menor sal�rio
-- de cada departamento.
select F.FUN_NOME, F.FUN_SALARIO, D.DEP_NOME
from tbFuncionario F join tbDepartamento D
	on F.DEP_CODIGO = D.DEP_CODIGO
where F.FUN_SALARIO = (
	select min(FUN_SALARIO)
	from tbFuncionario
	where DEP_CODIGO = F.DEP_CODIGO
)

-- ex03: Obter o nome dos funcion�rios que possuem o maior sal�rio de
-- cada cargo.
select FUN_NOME, FUN_SALARIO, F_E.FUN_CARGO
from tbFuncionario F_E
where FUN_SALARIO = (
	select max(FUN_SALARIO)
	from tbFuncionario
	where FUN_CARGO = F_E.FUN_CARGO
)

use SistemaAcademicoBCC

/* ex04: Obter o nome dos cursos de n�vel de gradua��o, cuja carga
hor�ria � inferior ao somat�rio da carga hor�ria das suas
disciplinas. Ordene o resultado pelo nome do curso. */
select C.CUR_NOME
from tbCurso C
where 
	C.CUR_NIVEL = 'Gradua��o' and
	C.CUR_CARGA_HORARIA < (
		select sum(DIS_CARGA_HORARIA)
		from tbDisciplina
		where C.CUR_CODIGO = CUR_CODIGO
	)
order by C.CUR_NOME

/* ex05: Obter o nome das disciplinas cuja carga hor�ria est� acima da
m�dia de carga hor�ria do seu curso. */
select D.DIS_NOME
from tbDisciplina D
where D.DIS_CARGA_HORARIA > (
	select avg(CUR_CARGA_HORARIA)
	from tbCurso
	where D.CUR_CODIGO = CUR_CODIGO
)
