Use Empresa

-- Exerc�cio 05 - SELECT (13/06/2023)

/* 1) Exibir todos os dados das categorias. */
SELECT * FROM Categorias

/* 2) Exibir o nome de todos os clientes ordenados pelo nome. */
SELECT Nome
FROM Clientes
ORDER BY Nome

/* 3) Exibir o nome dos funcion�rios de cargo gerente
(existem v�rios gerentes, por exemplo gerente de vendas,
gerente de marketing), que residem no Brasil e cujo 
sal�rio � superior a R$ 1500.*/
SELECT Nome
FROM Funcionarios
WHERE
	Cargo LIKE 'Gerente%' AND
	Pais = 'Brasil' AND
	Salario > 1500

/* 4) Exibir os produtos que n�o est�o descontinuados,
cujo pre�o � maior ou igual a 10 e menor ou igual a 100 e
cuja unidade � diferente de nulo.*/
SELECT * FROM Produtos
WHERE
	Descontinuado = 0 AND
	Preco BETWEEN 10 AND 100 AND
	Unidades IS NOT NULL

/* 5) Exibir o nome da empresa e o contato dos fornecedores 
da It�lia, Noruega, Alemanha ou Reino Unido. Renomeie o nome 
da empresa para Fornecedor e o contato para Telefone. Ordene o
resultado pelo nome da empresa.*/
SELECT Empresa 'Fornecedor', Contato 'Telefone'
FROM Fornecedores
WHERE
	Pais = 'It�lia' OR Pais = 'Noruega' OR
	Pais = 'Alemanha' OR Pais = 'Reino Unido'
ORDER BY Fornecedor

/* 6) Exibir o maior sal�rio, o menor sal�rio e a m�dia sal�rio dos
funcion�rios por pa�s.*/
SELECT	Pais, MAX(Salario) 'MAIOR_SALARIO', 
		MIN(Salario) 'MENOR_SALARIO', 
		AVG(Salario) 'MEDIA_SALARIO'
FROM Funcionarios
GROUP BY Pais

/* 7) Exibir o maior sal�rio dos funcion�rios de cargo Gerente
(existem v�rios gerentes, por exemplo gerente de vendas, gerente
de marketing) e que residem no Brasil.*/
SELECT MAX(Salario) 'MAIOR_SALARIO'
FROM Funcionarios
WHERE Cargo LIKE 'Gerente%' AND Pais = 'Brasil'

/* 8) Exibir o maior sal�rio dos funcion�rios de cada uma das 
cidades Tiangu�, Vi�osa, Ubajara e Ibiapina. Ordene o resultado
pelo maior sal�rio.*/
SELECT Cidade, MAX(Salario) 'MAIOR_SALARIO'
FROM Funcionarios
WHERE 
	Cidade LIKE 'Tiangu[�a]' OR
	Cidade LIKE 'Vi[�c]osa' OR
	Cidade = 'Ubajara' OR
	Cidade = 'Ibiapina'
GROUP BY Cidade
ORDER BY MAIOR_SALARIO DESC

/* 9) Exibir a m�dia de sal�rio dos funcion�rios de cargo 
Coordenador (considere que podem existir
diversos coordenadores) por cidade. Ordene o resultado pela m�dia
de sal�rio.*/
SELECT Cidade, AVG(Salario) 'MEDIA_SALARIO'
FROM Funcionarios
WHERE Cargo LIKE 'Coordenador%'
GROUP BY Cidade
ORDER BY MEDIA_SALARIO DESC

/* 10) Exibir o n�mero do pedido e o valor total do pedido. 
Considere que o valor total de um pedido � obtido a partir do 
somat�rio do pre�o do produto * Qtde � Desconto. 
Ordene o resultado pelo n�mero do pedido.*/
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

/* 12) Exibir a quantidade de produtos cujo pre�o � superior a 5.00
e inferior a 10.00, por fornecedor. Exibir apenas os fornecedores
que possuem mais de um produto nessa condi��o. Ordene o resultado 
pela quantidade.*/
SELECT CodFor, COUNT(*) 'QTD_PROD'
FROM Produtos
WHERE Preco BETWEEN 5 AND 10
GROUP BY CodFor
HAVING COUNT(*) > 1
ORDER BY QTD_PROD

/* 13) Exibir o somat�rio do sal�rio dos funcion�rios de cargo
Gerente ou Coordenador. Ordene o resultado pelo somat�rio. 
Renomeie a coluna para Total. Exiba tamb�m o cargo.*/
SELECT Cargo, SUM(Salario) 'TOTAL'
FROM Funcionarios
WHERE Cargo LIKE 'Gerente%' OR Cargo LIKE 'Coordenador%'
GROUP BY Cargo
ORDER BY TOTAL DESC

/* 14) Exibir a m�dia de sal�rio dos funcion�rios de acordo com o
Pa�s. Exibir apenas os pa�ses que possuem mais de 5 funcion�rios.*/
SELECT Pais, AVG(Salario) 'MEDIA_SALARIO'
FROM Funcionarios
GROUP BY Pais
HAVING COUNT(*) > 5

/* 15) Exibir a quantidade de produtos e a m�dia de pre�o dos
produtos descontinuados de cada categoria que possui mais de
10 produtos. Ordene o resultado pela m�dia de pre�o.*/
SELECT COUNT(*) 'QTDE_PROD', AVG(Preco) 'MEDIA_PRECO'
FROM Produtos
WHERE Descontinuado = 1
GROUP BY CodCategoria
HAVING COUNT(*) > 10
ORDER BY MEDIA_PRECO DESC
