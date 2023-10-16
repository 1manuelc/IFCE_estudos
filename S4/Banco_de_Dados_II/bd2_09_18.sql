use BD_Empresa

-- Subconsultas com ALL ou ANY

/* 1) Obter o nome dos funcion�rios que possuem sal�rio superior a de todos
os funcion�rios cujo cargo � Coordenador ou Gerente */
select FUN_NOME
from tbFuncionario
where FUN_SALARIO > all (
	select FUN_SALARIO
	from tbFuncionario
	where FUN_CARGO in ('Coordenador', 'Gerente')
)

/* 2) Obter o nome, o sal�rio e o departamento dos funcion�rios que
possuem sal�rio superior a de qualquer funcion�rio do
Departamento de Administra��o. Obs.: Os funcion�rios do
Departamento de Administra��o n�o devem ser exibidos. */
select FUN_NOME, FUN_SALARIO, DEP_NOME
from tbFuncionario F join tbDepartamento D
	on F.DEP_CODIGO = D.DEP_CODIGO
where
	FUN_SALARIO > any (
		select FUN_SALARIO
		from tbFuncionario F join tbDepartamento D
			on F.DEP_CODIGO = D.DEP_CODIGO
		where DEP_NOME like 'Administra[�c][�a]o'
	) and
	DEP_NOME not like 'Administra[�c][�a]o'

