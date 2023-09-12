use BD_Empresa

select FUN_NOME, FUN_SALARIO
from tbFuncionario
where FUN_SALARIO = (
	select min(FUN_SALARIO) from tbFuncionario
)

-- Consultas SQL de única linha
/* 1. Obter o Nome, o Salário e o Departamento dos funcionários
que possuem o salário superior a média salarial da empresa.*/
select FUN_NOME, FUN_SALARIO, DEP_NOME
from tbFuncionario F join tbDepartamento D
	on F.DEP_CODIGO = D.DEP_CODIGO
where FUN_SALARIO > (
	select avg(FUN_SALARIO) from tbFuncionario
)

/* 2. Obter o Nome e o Salário dos funcionários cujo salário é superior
ao salário do funcionário José Antônio. */
select FUN_NOME, FUN_SALARIO
from tbFuncionario
where FUN_SALARIO > (
	select FUN_SALARIO
	from tbFuncionario
	where FUN_NOME like 'Jos[ée] Ant[ôo]nio'
)

/* 3. Obter o Nome dos funcionários cujo salário é maior que o menor
salário do cargo Coordenador. */
select FUN_NOME
from tbFuncionario
where FUN_SALARIO > (
	select min(FUN_SALARIO)
	from tbFuncionario
	where FUN_CARGO = 'Coordenador'
)

/* 4. Exibir os funcionários cujo cargo é o mesmo que o cargo do
funcionário Paulo Viegas e cujo salário é maior que o salário do
funcionário Antônio Dias. */
select FUN_NOME
from tbFuncionario
where 
	FUN_CARGO = (
		select FUN_CARGO
		from tbFuncionario
		where FUN_NOME like 'Paulo Viegas'
	) and
	FUN_SALARIO > (
		select FUN_SALARIO
		from tbFuncionario
		where FUN_NOME like 'Ant[ôo]nio Dias'
	)

/* 5. Obter o Nome do funcionário do Departamento de Administração
que possui o maior salário. */
select FUN_NOME
from tbFuncionario
where 
	FUN_SALARIO = (
		select max(FUN_SALARIO)
		from tbFuncionario F join tbDepartamento D 
			on F.DEP_CODIGO = F.DEP_CODIGO
		where DEP_NOME like 'Administra[çc][ãa]o'
	)
