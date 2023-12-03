/* #4. Implemente uma base de dados com apenas uma tabela cuja 
temática é (bdControleEstoque) com uma tabela (tbProdutosEstoque) 
com pelo menos 6 atributos incluindo a chave primária. */

CREATE DATABASE bdControleEstoque;
USE bdControleEstoque;

CREATE TABLE tbProdutosEstoque (
	PRO_ID INT NOT NULL,
    PRO_NOME VARCHAR(40) NOT NULL,
    PRO_PRECO DECIMAL(10,2),
    PRO_ESTOQUE INT,
    PRO_DATACAD DATE NOT NULL,
    PRO_ATIVO BOOLEAN,
    
    PRIMARY KEY(PRO_ID)
)