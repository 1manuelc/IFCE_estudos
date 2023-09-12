use BD_Empresa

-- 1. Obter o nome dos funcionários da empresa ordenados pelo nome.
select FUN_NOME
from tbFuncionario
order by FUN_NOME

/* 2. Obter o nome dos funcionários cujo cargo é Gerente, o nome inicia
com A e o salário é superior a 1000.*/
select FUN_NOME
from tbFuncionario
where
	FUN_CARGO LIKE 'GERENTE' AND
	FUN_NOME LIKE 'A%' AND
	FUN_SALARIO > 1000

/* 3. Obter o maior, o menor e a média de salário dos funcionários cujo
cargo é Coordenador. */
select 
	max(FUN_SALARIO) 'MAIOR_SALARIO', 
	min(FUN_SALARIO) 'MENOR_SALARIO',
	avg(FUN_SALARIO) 'MEDIA_SALARIOS'
from tbFuncionario
where FUN_CARGO LIKE 'COORDENADOR'

/* 4. Obter o nome de todos os funcionários com o nome do seu respectivo
departamento. */
select FUN_NOME, DEP_NOME
from tbFuncionario F JOIN tbDepartamento D
	on F.DEP_CODIGO = D.DEP_CODIGO

/* 5. Obter o somatório dos salários dos fucnionários agrupados por
departamento. Exiba também o nome do departamento. */
select D.DEP_NOME, sum(FUN_SALARIO) 'SUM_SALARIOS_DEP'
from tbFuncionario F JOIN tbDepartamento D
	on F.DEP_CODIGO = D.DEP_CODIGO
group by D.DEP_NOME

/* 6. Obter a quantidade de funcionários da empresa em cada
departamento que possui mais de 1 funcionário.*/
select count(FUN_CODIGO) 'QTDE_FUN'
from tbFuncionario F JOIN tbDepartamento D
	on F.DEP_CODIGO = D.DEP_CODIGO
group by D.DEP_NOME
having count(FUN_CODIGO) > 1

/* 7. Obter a quantidade de funcionários do Cargo Coordenador que existe
em cada departamento (exiba também o nome do departamento),
ordenado pela quantidade. */
select count(FUN_CODIGO) 'QTDE_COORD_P_DEP', DEP_NOME
from tbFuncionario F JOIN tbDepartamento D
	on F.DEP_CODIGO = D.DEP_CODIGO
where FUN_CARGO LIKE 'COORDENADOR'
group by D.DEP_NOME
order by QTDE_COORD_P_DEP
