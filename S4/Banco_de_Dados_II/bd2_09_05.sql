use BD_Empresa

select FUN_NOME, FUN_SALARIO
from tbFuncionario
where FUN_SALARIO = (
	select min(FUN_SALARIO) from tbFuncionario
)

-- Consultas SQL de �nica linha
/* 1. Obter o Nome, o Sal�rio e o Departamento dos funcion�rios
que possuem o sal�rio superior a m�dia salarial da empresa.*/
select FUN_NOME, FUN_SALARIO, DEP_NOME
from tbFuncionario F join tbDepartamento D
	on F.DEP_CODIGO = D.DEP_CODIGO
where FUN_SALARIO > (
	select avg(FUN_SALARIO) from tbFuncionario
)

/* 2. Obter o Nome e o Sal�rio dos funcion�rios cujo sal�rio � superior
ao sal�rio do funcion�rio Jos� Ant�nio. */
select FUN_NOME, FUN_SALARIO
from tbFuncionario
where FUN_SALARIO > (
	select FUN_SALARIO
	from tbFuncionario
	where FUN_NOME like 'Jos[�e] Ant[�o]nio'
)

/* 3. Obter o Nome dos funcion�rios cujo sal�rio � maior que o menor
sal�rio do cargo Coordenador. */
select FUN_NOME
from tbFuncionario
where FUN_SALARIO > (
	select min(FUN_SALARIO)
	from tbFuncionario
	where FUN_CARGO = 'Coordenador'
)

/* 4. Exibir os funcion�rios cujo cargo � o mesmo que o cargo do
funcion�rio Paulo Viegas e cujo sal�rio � maior que o sal�rio do
funcion�rio Ant�nio Dias. */
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
		where FUN_NOME like 'Ant[�o]nio Dias'
	)

/* 5. Obter o Nome do funcion�rio do Departamento de Administra��o
que possui o maior sal�rio. */
select FUN_NOME
from tbFuncionario
where 
	FUN_SALARIO = (
		select max(FUN_SALARIO)
		from tbFuncionario F join tbDepartamento D 
			on F.DEP_CODIGO = F.DEP_CODIGO
		where DEP_NOME like 'Administra[�c][�a]o'
	)
