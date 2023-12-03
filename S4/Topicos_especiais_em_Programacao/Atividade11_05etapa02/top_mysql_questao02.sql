/* #2. Construa uma base de dados chamada (bdLojaMaterialEscolar) com duas tabelas (tbClientes e tbProdutos) relacionadas, cada uma possuindo pelo menos 5 atributos, inclusive com as chaves primárias e estrangeira. */

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
