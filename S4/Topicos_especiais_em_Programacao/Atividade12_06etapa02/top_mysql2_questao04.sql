/* #4. Implemente uma base de dados chamada (bdPapelaria) com uma tabela chamada 
(tbMateriaisEscolares), com pelo menos 4 atributos incluindo a chave primária.   
Usar scripts SQL para:
	a) Insira pelo menos 5 tuplas (valores);
	b) Altere os valores das linhas 1, 2 e 3;
	c) Delete as tuplas, 4 e 5. 
*/

CREATE DATABASE bdPapelaria;
USE bdPapelaria;

CREATE TABLE tbMateriaisEscolares (
	MAT_ID INT NOT NULL,
    MAT_NOME VARCHAR(50),
    MAT_PRECO DECIMAL(10,2),
    MAT_DATACAD DATE NOT NULL,
    MAT_ESTOQUE INT,
    
    PRIMARY KEY(MAT_ID)
);

-- a) Insira pelo menos 5 tuplas (valores);
INSERT INTO tbMateriaisEscolares
	(MAT_NOME,		MAT_PRECO,	MAT_DATACAD,	MAT_ESTOQUE)
VALUES
	("Lápis",		1.00,		NOW(),			1500),
    ("Caneta",		1.50,		NOW(),			2500),
    ("Borracha",	1.25,		NOW(),			500),
    ("Tesoura",		2.50,		NOW(),			250),
    ("Apontador",	1.75,		NOW(),			1250);

-- 	b) Altere os valores das linhas 1, 2 e 3;
UPDATE tbMateriaisEscolares
SET MAT_NOME = "Lapiseira", 
	MAT_PRECO = 2.25, 
    MAT_ESTOQUE = 550
WHERE MAT_ID = 1;

UPDATE tbMateriaisEscolares
SET MAT_NOME = "Caneta preta", 
	MAT_PRECO = 2.00, 
    MAT_ESTOQUE = 150
WHERE MAT_ID = 2;

UPDATE tbMateriaisEscolares
SET MAT_NOME = "Cx. lápis de cor", 
	MAT_PRECO = 20.00, 
    MAT_ESTOQUE = 100
WHERE MAT_ID = 3;

-- c) Delete as tuplas, 4 e 5. 
DELETE FROM tbMateriaisEscolares
WHERE MAT_ID IN(4, 5);