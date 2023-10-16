use Empresa

-- Exercício 03, Subconsultas

/* 1) Obter o nome dos produtos que possuem o maior preço. Ordene o resultado pelo nome do
produto. */
select Pr.Descr 'NOME_PRODUTO'
from Produtos Pr
where Pr.Preco in (
	select max(Preco)
	from Produtos
)
order by NOME_PRODUTO

/* 2) O número do pedido realizado no ano de 1996 que possui o maior valor de frete. */
select Pd.NumPed
from Pedidos Pd
where Pd.Frete = (
		select max(Frete)
		from Pedidos
		where year(DataPed) = 1996
	)

/* 3) Obter o nome dos funcionários do Brasil que possuem o salário superior à média de salário da
empresa. */
select Fun.Nome
from Funcionarios Fun
where 
	Fun.Pais = 'Brasil' and
	Fun.Salario > (
		select avg(Salario)
		from Funcionarios
		where Pais = 'Brasil'
	)

/* 4) O nome dos produtos da categoria Bebidas que possuem o menor preço. */
select Pro.Descr
from Produtos Pro join Categorias Cat
	on Pro.CodCategoria = Cat.CodCategoria
where
	Cat.Descr = 'Bebidas' and
	Pro.Preco = (
		select min(Preco)
		from Produtos Pro join Categorias Cat
			on Pro.CodCategoria = Cat.CodCategoria
		where Cat.Descr = 'Bebidas'
	)

/* 5) O nome dos produtos da categoria Bebidas que também estão em outra categoria. */
select Pro.Descr
from Produtos Pro join Categorias Cat
	on Pro.CodCategoria = Cat.CodCategoria
where
	Cat.Descr = 'Bebidas' and
	Pro.Descr = any (
		select Pro.Descr
		from Produtos Pro join Categorias Cat
			on Pro.CodCategoria = Cat.CodCategoria
		where Cat.Descr != 'Bebidas'
	)

/* 6) O nome dos produtos fornecidos pela Empresa Refrescos Americanas LTDA que possuem
preço superior a algum produto fornecido pela Empresa Ma Maison. */
select Pro.Descr
from Produtos Pro join Fornecedores Frn
	on Pro.CodFor = Frn.CodFor
where
	Frn.Empresa = 'Refrescos Americanas LTDA' and
	Pro.Preco > any (
		select Pro.Preco
		from Produtos Pro join Fornecedores Frn
			on Pro.CodFor = Frn.CodFor
		where Frn.Empresa = 'Ma Maison'
	)

/* 7) O nome dos funcionários que não realizaram nenhum pedido no ano de 1999. */
select Nome
from Funcionarios
where CodFun not in (
	select CodFun
	from Pedidos
	where year(DataPed) = 1999
)

/* 8) O nome dos produtos da categoria Confeitos que possuem preço superior que todos os preços
dos produtos da categoria Condimentos.*/
select Pro.Descr
from Produtos Pro join Categorias Cat
	on Pro.CodCategoria = Cat.CodCategoria
where
	Cat.Descr = 'Confeitos' and
	Pro.Preco > all (
		select Preco
		from Produtos Pr join Categorias Ct
			on Pr.CodCategoria = Ct.CodCategoria
		where Ct.Descr = 'Condimentos'
	)
