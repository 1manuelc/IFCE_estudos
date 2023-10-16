use BD_Empresa

/* Obter o nome dos funcion�rios que possuem sal�rio 
igual ao menor sal�rio em cada departamento */
select FUN_NOME, DEP_NOME
from tbFuncionario F join tbDepartamento D
	on F.DEP_CODIGO = D.DEP_CODIGO
where FUN_SALARIO in (
	select min(FUN_SALARIO)
	from tbFuncionario
	group by DEP_CODIGO
)

/* Obter o nome dos departamentos que n�o tem funcion�rios */
select DEP_NOME
from tbDepartamento
where DEP_CODIGO not in (
	select distinct(DEP_CODIGO)
	from tbFuncionario
)

/* Elaborar uma consulta que obtenha o nome do funcion�rio 
com sal�rio maior que todos entre os menores de cada departamento */
select FUN_NOME, FUN_SALARIO
from tbFuncionario
where FUN_SALARIO > ALL (
	select min(FUN_SALARIO)
	from tbFuncionario
	group by DEP_CODIGO
)

/* Elaborar uma consulta que obtenha o nome do funcion�rio 
com sal�rio maior que algum entre os menores de cada departamento */
select FUN_NOME, FUN_SALARIO
from tbFuncionario
where FUN_SALARIO > ANY (
	select min(FUN_SALARIO)
	from tbFuncionario
	group by DEP_CODIGO
)

-- "IN" == "= ANY"
-- "NOT IN" == "!= ALL"