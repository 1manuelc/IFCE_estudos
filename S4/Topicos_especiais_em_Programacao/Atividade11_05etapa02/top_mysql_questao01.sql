/* #1. Implemente uma base de dados relacionada a produtos de beleza (bdLimpeza), onde a tabela chamada (tbProdutos) terá pelo menos 5 atributos, inclusive com a chave primária. */

CREATE DATABASE bdLimpeza;
USE bdLimpeza;

CREATE TABLE tbProdutos (
	id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    nome VARCHAR(20) NOT NULL,
    preco DECIMAL(10,2),
    dataCadastro DATE NOT NULL,
    estoque INT
);
