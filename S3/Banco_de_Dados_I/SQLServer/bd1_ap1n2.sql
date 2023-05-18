INSERT INTO tbCategoria
(CAT_DESCRICAO)
VALUES
	('Cal�ado')

INSERT INTO tbUnidade
(UNI_DESCRICAO)
VALUES
	('pe�a')

INSERT INTO tbMarca
(MAR_NOME)
VALUES
	('Arezo')

INSERT INTO tbProduto
(PRO_DESCRICAO, PRO_PRECO_CUSTO, 
PRO_PRECO_VENDA, PRO_QTDE_ESTOQUE, 
PRO_QTDE_MINIMA, CAT_CODIGO, UNI_CODIGO, 
MAR_CODIGO, PRO_RESUMO)
VALUES
	('Sapato', 51.25, 
	85.50, 5,
	1, 1, 1,
	1, NULL)

UPDATE tbProduto
SET PRO_PRECO_VENDA = PRO_PRECO_CUSTO * 1.2
WHERE
	PRO_QTDE_ESTOQUE < PRO_QTDE_MINIMA AND
	PRO_PRECO_VENDA < PRO_PRECO_CUSTO

DELETE FROM tbProduto
WHERE
	PRO_QTDE_ESTOQUE < PRO_QTDE_MINIMA AND
	PRO_DESCRICAO LIKE '______'

DELETE FROM tbProduto
WHERE
	(PRO_DESCRICAO LIKE 'SAPATO' OR
	PRO_DESCRICAO LIKE 'CAL[�C]ADO' OR
	PRO_DESCRICAO LIKE 'CHINELO') AND
	PRO_CODIGO BETWEEN 2 AND 5 AND
	PRO_RESUMO IS NULL

SELECT * FROM tbProduto