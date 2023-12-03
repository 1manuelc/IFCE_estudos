/* #1. Implemente uma base de dados relacionada a produtos de limpeza (bdLimpeza), 
onde a tabela chamada produtos (tbProdutos) terá pelo menos 5 atributos, inclusive 
com a chave primária. A seguir faça o uso de scripts para:
	a) Insira pelo menos 5 tuplas (valores);
	b) Altere os valores das linhas 2 e 3;
	c) Delete as tuplas, 1, 4 e 5. 
*/

CREATE DATABASE bdLimpeza;
USE bdLimpeza;

CREATE TABLE tbProdutos (
	id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    nome VARCHAR(50) NOT NULL,
    preco DECIMAL(10,2),
    dataCadastro DATE NOT NULL,
    estoque INT
);

-- a) Insira pelo menos 5 tuplas (valores)
INSERT INTO tbProdutos 
	(nome, 				preco, 		estoque,	dataCadastro)
VALUES 
	("Bombril", 		4.50, 		250, 		NOW()),
    ("Pinho Sol", 		8, 			170,		NOW()),
    ("Detergente Ipê", 	1.49, 		700,		NOW()),
    ("Sabão em barra", 	4.25, 		500,		NOW()),
    ("Panos perfex", 	5.50, 		1250,		NOW());
    
-- b) Altere os valores das linhas 2 e 3;
UPDATE tbProdutos
SET nome = "Desinfetante", preco = 12.50, estoque = 1000
WHERE id = 2;

UPDATE tbProdutos
SET nome = "Água sanitária", preco = 9.79, estoque = 250
WHERE id = 3;

-- c) Delete as tuplas, 1, 4 e 5. 
DELETE FROM tbProdutos
WHERE id IN(1, 4, 5);