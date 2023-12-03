/* #5. Implemente uma base de dados chamada (bdPapelaria) com uma 
tabela chamada (tbMateriaisEscolares), com pelo menos 4 atributos 
incluindo a chave primária. */

CREATE DATABASE bdPapelaria;
USE bdPapelaria;

CREATE TABLE tbMateriaisEscolares (
	MAT_ID INT NOT NULL,
    MAT_PRECO DECIMAL(10,2),
    MAT_DATACAD DATE NOT NULL,
    MAT_ESTOQUE INT,
    
    PRIMARY KEY(MAT_ID)
)