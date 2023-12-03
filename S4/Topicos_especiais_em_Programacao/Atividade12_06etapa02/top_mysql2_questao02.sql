/* #2. Construa uma base de dados chamada (bdLojaMaterialEscolar) com duas tabelas 
relacionadas (tbClientes e tbProdutos) cada uma possuindo pelo menos 5 atributos, 
inclusive com as chaves primárias e estrangeira. Usar scripts SQL para:
	a) Insira pelo menos 5 tuplas (valores);
	b) Altere os valores das linhas 3, 4 e 5;
	c) Delete as tuplas, 1 e 2.
*/

CREATE DATABASE bdLojaMaterialEscolar;
USE bdLojaMaterialEscolar;

CREATE TABLE tbClientes (
	CLI_ID INT NOT NULL AUTO_INCREMENT,
    CLI_NOME VARCHAR(40) NOT NULL,
    CLI_CPF VARCHAR(14) NOT NULL,
    CLI_DATACADASTRO DATE,
    PRO_ID INT,
    
    PRIMARY KEY(CLI_ID),
    FOREIGN KEY(PRO_ID) REFERENCES tbProdutos(PRO_ID)
);

CREATE TABLE tbProdutos (
	PRO_ID INT NOT NULL AUTO_INCREMENT,
    PRO_NOME VARCHAR(25) NOT NULL,
    PRO_PRECO DECIMAL(10,2) NOT NULL,
    PRO_ESTOQUE INT,
    CLI_ID INT,
    
    PRIMARY KEY(PRO_ID),
    FOREIGN KEY(CLI_ID) REFERENCES tbClientes(CLI_ID)
);

-- a) Insira pelo menos 5 tuplas (valores);
INSERT INTO tbClientes 
	(CLI_NOME, 	CLI_CPF, 			CLI_DATACADASTRO)
VALUES
	("José",	"000.000.000-00",	NOW()),
    ("Maria",	"111.111.111-11",	NOW()),
    ("Pedro",	"222.222.222-22",	NOW()),
    ("João",	"333.333.333-33",	NOW()),
    ("Tiago",	"444.444.444-44",	NOW());
    
INSERT INTO tbProdutos
	(PRO_NOME,		PRO_PRECO,	PRO_ESTOQUE,	CLI_ID)
VALUES
	("Lápis",		1.25,		1500,			1),
    ("Borracha",	0.90,		2500,			2),
    ("Apontador",	1.75,		300,			3),
    ("Caneta Azul",	1.90,		3500,			1),
    ("Azul Caneta",	2.10,		500,			4);
    
-- b) Altere os valores das linhas 3, 4 e 5;
UPDATE tbClientes
SET nome = "Rafael", CLI_CPF = "777.777.777-77"
WHERE CLI_ID = 3;

UPDATE tbClientes
SET nome = "Gabriel", CLI_CPF = "888.888.888-88"
WHERE CLI_ID = 4;

UPDATE tbClientes
SET nome = "Miguel", CLI_CPF = "999.999.999-99"
WHERE CLI_ID = 5;

-- 	c) Delete as tuplas, 1 e 2.
DELETE FROM tbProdutos
WHERE PRO_ID IN(1, 2);