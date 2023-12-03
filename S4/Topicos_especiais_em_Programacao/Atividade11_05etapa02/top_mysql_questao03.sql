/* #3. Implemente a estrutura abaixo cuja a base de dados 
chama-se (bdEstoque), e as tabelas (tb01_produtos, 
tb02_compras e tb03_itens_compra). */

CREATE DATABASE bdEstoque;
USE bdEstoque;

CREATE TABLE tb01_produtos (
	tb01_cod_produto INT NOT NULL,
    tb01_nome_produto VARCHAR(120),
    tb01_preco_produto DECIMAL(9,0),
    tb01_qtd_produto INT,
    
    PRIMARY KEY(tb01_cod_produto)
);

CREATE TABLE tb02_compras (
	tb02_cod_compra INT NOT NULL,
    tb02_data_compra DATE,
    tb02_hora_compra TIME,
    
    PRIMARY KEY(tb02_cod_compra)
);

CREATE TABLE tb03_itens_compra (
	tb03_cod_itens INT NOT NULL,
    tb03_cod_produto INT,
    tb03_preco_item DECIMAL(9,0),
    tb03_qtd_item INT,
    tb03_cod_compra INT,
    
    PRIMARY KEY(tb03_cod_itens),
    FOREIGN KEY(tb03_cod_produto) REFERENCES tb01_produtos(tb01_cod_produto),
    FOREIGN KEY(tb03_cod_compra) REFERENCES tb02_compras(tb02_cod_compra)
);