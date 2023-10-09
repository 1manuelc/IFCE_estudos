-- BD2 - Exercício 05
-- Subconsultas Correlacionadas
use Empresa

/* a) Obter o nome dos funcionários que atenderam pedidos com valor de frete acima da
média de valor de frete de todos os pedidos. */
select distinct(Nome)
from Funcionarios F join Pedidos P
	on F.CodFun = P.CodFun
where P.Frete > (
	select avg(Frete)
	from Pedidos
)

/* b) Obter a descrição das categorias que possuem produtos com preço abaixo da média de
preço dos produtos. */
select distinct(C.Descr)
from Categorias C join Produtos P
	on C.CodCategoria = P.CodCategoria
where P.Preco < (
	select avg(Preco)
	from Produtos
)

/* c) Obter a descrição dos produtos que possuem preço superior a qualquer produto da
categoria Bebidas. Obs.: Não exibir os produtos da categoria Bebidas. */
select P.Descr
from Produtos P join Categorias C
	on P.CodCategoria = C.CodCategoria
where 
	C.Descr != 'Bebidas' and
	P.Preco > any (
		select Preco
		from Produtos P join Categorias C
			on P.CodCategoria = C.CodCategoria
		where C.Descr = 'Bebidas'
	)

/* d) Obter a descrição e o preço dos produtos mais caros de cada categoria. Ordene o
resultado pela descrição do produto. */
select P.Descr, Preco, C.Descr
from Produtos P join Categorias C
	on P.CodCategoria = C.CodCategoria
where Preco = (
	select max(Preco)
	from Produtos
	where C.CodCategoria = CodCategoria
)
order by P.Descr

/* e) O nome dos funcionários que possuem salário acima da média de salário de seu cargo. */
select Nome
from Funcionarios Fun_Ex
where Salario > (
	select avg(Salario)
	from Funcionarios
	where Fun_Ex.Cargo = Cargo
)

-- f) O nome do funcionário de maior salário em cada cargo.
select Nome
from Funcionarios Fun_Ex
where Salario = (
	select max(Salario)
	from Funcionarios
	where Cargo = Fun_Ex.Cargo
)

/* g) A descrição dos produtos da categoria Bebidas, cujo preço é inferior à média de preço
dos produtos do seu fornecedor. Ordene o resultado pelo nome do produto. */
select Prods_Ex.Descr
from Produtos Prods_Ex join Categorias Cats_Ex
	on Prods_Ex.CodCategoria = Cats_Ex.CodCategoria
	join Fornecedores Forn_Ex
		on Forn_Ex.CodFor = Prods_Ex.CodFor
where
	Cats_Ex.Descr = 'Bebidas' and
	Prods_Ex.Preco < (
		select avg(Preco)
		from Produtos Prods_In join Fornecedores Forn_In
			on Prods_In.CodFor = Forn_In.CodFor
		where Forn_In.CodFor = Forn_Ex.CodFor
	)
order by Prods_Ex.Descr

/* h) Obter os Clientes cujo valor total de pedidos é maior que o dobro da média de valores
de pedidos de todos os clientes. */
select distinct Clientes.*
from DetalhesPed DetPed_Ex join Pedidos
	on DetPed_Ex.NumPed = Pedidos.NumPed
	join Clientes
		on Pedidos.CodCli = Clientes.CodCli
where
	DetPed_Ex.Preco > (
		select 2 * avg(DetalhesPed.Preco)
		from DetalhesPed
	)

/* i) Obter o pedido mais recente de cada cliente. No resultado da consulta exibir o número
do pedido, a data do pedido e o nome do cliente. */
select P_Ex.NumPed 'Pedidos.NumPed', P_Ex.DataPed 'Pedidos.DataPed', C_Ex.Nome 'Clientes.Nome'
from Pedidos P_Ex join Clientes C_Ex
	on P_Ex.CodCli = C_Ex.CodCli
where P_Ex.DataPed = (
	select max(DataPed)
	from Pedidos
	where P_Ex.CodCli = CodCli
)
