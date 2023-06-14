Use Empresa

-- Exercício 05 - SELECT (13/06/2023)

/* 1) Exibir todos os dados das categorias. */
SELECT * FROM Categorias

/* 2) Exibir o nome de todos os clientes ordenados pelo nome. */
SELECT Nome
FROM Clientes
ORDER BY Nome

/* 3) Exibir o nome dos funcionários de cargo gerente
(existem vários gerentes, por exemplo gerente de vendas,
gerente de marketing), que residem no Brasil e cujo 
salário é superior a R$ 1500.*/
SELECT Nome
FROM Funcionarios
WHERE
	Cargo LIKE 'Gerente%' AND
	Pais = 'Brasil' AND
	Salario > 1500

/* 4) Exibir os produtos que não estão descontinuados,
cujo preço é maior ou igual a 10 e menor ou igual a 100 e
cuja unidade é diferente de nulo.*/
SELECT * FROM Produtos
WHERE
	Descontinuado = 0 AND
	Preco BETWEEN 10 AND 100 AND
	Unidades IS NOT NULL

/* 5) Exibir o nome da empresa e o contato dos fornecedores 
da Itália, Noruega, Alemanha ou Reino Unido. Renomeie o nome 
da empresa para Fornecedor e o contato para Telefone. Ordene o
resultado pelo nome da empresa.*/
SELECT Empresa 'Fornecedor', Contato 'Telefone'
FROM Fornecedores
WHERE
	Pais = 'Itália' OR Pais = 'Noruega' OR
	Pais = 'Alemanha' OR Pais = 'Reino Unido'

/* 6) Exibir o maior salário, o menor salário e a média salário dos
funcionários por país.*/
SELECT	Pais, MAX(Salario) 'MAIOR_SALARIO', 
		MIN(Salario) 'MENOR_SALARIO', 
		AVG(Salario) 'MEDIA_SALARIO'
FROM Funcionarios
GROUP BY Pais

/* 7) Exibir o maior salário dos funcionários de cargo Gerente
(existem vários gerentes, por exemplo gerente de vendas, gerente
de marketing) e que residem no Brasil.*/
SELECT MAX(Salario) 'MAIOR_SALARIO'
FROM Funcionarios
WHERE
	Cargo LIKE 'Gerente%' AND Pais = 'Brasil'

/* 8) Exibir o maior salário dos funcionários de cada uma das 
cidades Tianguá, Viçosa, Ubajara e Ibiapina. Ordene o resultado
pelo maior salário.*/
SELECT Cidade, MAX(Salario) 'MAIOR_SALARIO'
FROM Funcionarios
WHERE 
	Cidade LIKE 'Tiangu[áa]' OR
	Cidade LIKE 'Vi[çc]osa' OR
	Cidade = 'Ubajara' OR
	Cidade = 'Ibiapina'
GROUP BY Cidade
ORDER BY MAIOR_SALARIO DESC

/* 9) Exibir a média de salário dos funcionários de cargo 
Coordenador (considere que podem existir
diversos coordenadores) por cidade. Ordene o resultado pela média
de salário.*/
SELECT Cidade, AVG(Salario) 'MEDIA_SALARIO'
FROM Funcionarios
WHERE Cargo LIKE 'Coordenador%'
GROUP BY Cidade
ORDER BY MEDIA_SALARIO DESC

/* 10) Exibir o número do pedido e o valor total do pedido. 
Considere que o valor total de um pedido é obtido a partir do 
somatório do preço do produto * Qtde – Desconto. 
Ordene o resultado pelo número do pedido.*/
SELECT NumPed, SUM(Preco * Qtde - Desconto) 'TOTAL_PEDIDO'
FROM DetalhesPed
GROUP BY NumPed

/* 11) Exibir a quantidade de produtos por categoria. Exiba apenas
as categorias que possuem mais de 10 produtos. 
Ordene o resultado pela quantidade de produtos.*/
SELECT CodCategoria, COUNT(*) 'QTD_PROD'
FROM Produtos
GROUP BY CodCategoria
HAVING COUNT(*) > 10
ORDER BY QTD_PROD

/* 12) Exibir a quantidade de produtos cujo preço é superior a 5.00
e inferior a 10.00, por fornecedor. Exibir apenas os fornecedores
que possuem mais de um produto nessa condição. Ordene o resultado 
pela quantidade.*/
SELECT CodFor, COUNT(*) 'QTD_PROD'
FROM Produtos
WHERE Preco BETWEEN 5 AND 10
GROUP BY CodFor
HAVING COUNT(*) > 1
ORDER BY QTD_PROD

/* 13) Exibir o somatório do salário dos funcionários de cargo
Gerente ou Coordenador. Ordene o resultado pelo somatório. 
Renomeie a coluna para Total. Exiba também o cargo.*/
SELECT Cargo, SUM(Salario) 'TOTAL'
FROM Funcionarios
WHERE Cargo LIKE 'Gerente%' OR Cargo LIKE 'Coordenador%'
GROUP BY Cargo
ORDER BY TOTAL DESC

/* 14) Exibir a média de salário dos funcionários de acordo com o
País. Exibir apenas os países que possuem mais de 5 funcionários.*/
SELECT Pais, AVG(Salario) 'MEDIA_SALARIO'
FROM Funcionarios
GROUP BY Pais
HAVING COUNT(*) > 5

/* 15) Exibir a quantidade de produtos e a média de preço dos
produtos descontinuados de cada categoria que possui mais de
10 produtos. Ordene o resultado pela média de preço.*/
SELECT COUNT(*) 'QTDE_PROD', AVG(Preco) 'MEDIA_PRECO'
FROM Produtos
WHERE Descontinuado = 1
GROUP BY CodCategoria
HAVING COUNT(*) > 10
ORDER BY MEDIA_PRECO DESC
