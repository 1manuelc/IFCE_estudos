use BD_Empresa

-- Subconsultas com ALL ou ANY

/* 1) Obter o nome dos funcionários que possuem salário superior a de todos
os funcionários cujo cargo é Coordenador ou Gerente */
select FUN_NOME
from tbFuncionario
where FUN_SALARIO > all (
	select FUN_SALARIO
	from tbFuncionario
	where FUN_CARGO in ('Coordenador', 'Gerente')
)

/* 2) Obter o nome, o salário e o departamento dos funcionários que
possuem salário superior a de qualquer funcionário do
Departamento de Administração. Obs.: Os funcionários do
Departamento de Administração não devem ser exibidos. */
select FUN_NOME, FUN_SALARIO, DEP_NOME
from tbFuncionario F join tbDepartamento D
	on F.DEP_CODIGO = D.DEP_CODIGO
where
	FUN_SALARIO > any (
		select FUN_SALARIO
		from tbFuncionario F join tbDepartamento D
			on F.DEP_CODIGO = D.DEP_CODIGO
		where DEP_NOME like 'Administra[çc][ãa]o'
	) and
	DEP_NOME not like 'Administra[çc][ãa]o'

