CREATE DATABASE BD_OFICINA
USE BD_OFICINA

CREATE TABLE tbPeca
(
	PEC_CODIGO INT NOT NULL,
	PEC_DESCRICAO VARCHAR(150) NOT NULL,
	PEC_UNIDADE DECIMAL(10,2) NOT NULL,
	PEC_VALOR DECIMAL(10,2) NOT NULL
)

CREATE TABLE tbServico
(
	SER_CODIGO INT NOT NULL PRIMARY KEY IDENTITY,
	SER_VALOR DECIMAL(10,2) NOT NULL,
	SER_TEMPO DECIMAL(4,2) NOT NULL
)

CREATE TABLE tbCarro
(
	CAR_CODIGO INT NOT NULL PRIMARY KEY IDENTITY,
	CAR_PLACA INT NOT NULL,
	CAR_MODELO VARCHAR(50) NOT NULL UNIQUE,
	CAR_ANO INT NULL,
	CAR_CHASSI VARCHAR(17) NULL,
	CAR_COR VARCHAR(30)
)

CREATE TABLE tbOrdemServico
(
	ORD_CODIGO INT NOT NULL PRIMARY KEY IDENTITY,
	ORD_DATA DATE NOT NULL,
	CAR_CODIGO INT NOT NULL FOREIGN KEY REFERENCES tbCarro(CAR_CODIGO)
)

CREATE TABLE tbPecaOrdemServ
(
	POS_CODIGO INT NOT NULL PRIMARY KEY IDENTITY,
	POS_VALOR DECIMAL(10,2) NOT NULL,
	POS_QTDE INT NOT NULL,
	PEC_CODIGO INT NOT NULL,
	ORD_CODIGO INT NOT NULL FOREIGN KEY REFERENCES tbOrdemServico(ORD_CODIGO)
)

CREATE TABLE tbServicoOrdemServ
(
	SOS_CODIGO INT NOT NULL PRIMARY KEY IDENTITY,
	SOS_VALOR DECIMAL(10,2) NOT NULL,
	SER_CODIGO INT NOT NULL FOREIGN KEY REFERENCES tbServico(SER_CODIGO),
	ORD_CODIGO INT NOT NULL FOREIGN KEY REFERENCES tbOrdemServico(ORD_CODIGO)
)


-- 1) Adicionar o atributo SOS_QTDE a tabela tbServicoOrdemServ.

ALTER TABLE tbServicoOrdemServ
	ADD SOS_QTDE INT NOT NULL


-- 2) Remover o atributo SER_TEMPO da tabela tbServico.

ALTER TABLE tbServico
	DROP COLUMN SER_TEMPO


-- 3) Alterar o atributo SER_VALOR da tabela tbServico para decimal(10,2).

ALTER TABLE tbServico
	ALTER COLUMN SER_VALOR DECIMAL(10,2) NOT NULL


-- 4) Adicionar o campo PEC_CODIGO na tabela tbPeca e adicionar a chave primaria
-- a este campo.

ALTER TABLE tbPeca
	ADD PEC_CODIGO INT NOT NULL

ALTER TABLE tbPeca
	ADD CONSTRAINT PK_PEC_CODIGO PRIMARY KEY (PEC_CODIGO)


-- 5) Adicionar a chave estrangeira ao atributo PEC_CODIGO da tabela
-- tbPecaOrdemServ.

ALTER TABLE tbPecaOrdemServ
	ADD CONSTRAINT FK_PEC_CODIGO FOREIGN KEY (PEC_CODIGO) REFERENCES tbPeca(PEC_CODIGO)


-- 6) Adicionar as chaves unicas aos campos CAR_PLACA e CAR_CHASSI da tabela
-- tbCarro.

ALTER TABLE tbCarro
	ADD CONSTRAINT UK_CAR_PLACA UNIQUE (CAR_PLACA),
		CONSTRAINT UK_CAR_CHASSI UNIQUE (CAR_CHASSI)


-- 7) Remover a chave unica do atributo CAR_MODELO da tabela tbCarro.

ALTER TABLE tbCarro
	DROP CONSTRAINT UK_CAR_MODELO


-- 8) (Tentar) remover o atributo SER_CODIGO da tabela tbServico.

ALTER TABLE tbServicoOrdemServ
	DROP CONSTRAINT FK__tbServico__SER_C__5812160E,
		COLUMN SER_CODIGO

ALTER TABLE tbServico
	DROP CONSTRAINT PK__tbServic__CACEE86DDDAAE132,
		COLUMN SER_CODIGO

/* JUSTIFICATIVA:
		E necessario remover a restricao Foreign Key da tabela "tbServicoOrdemServ" que referencia a Primary Key
		a ser removida, alem de seu atributo SER_CODIGO que abriga a Foreign Key, depois, e necessario remover
		a restricao Primary Key da tabela em questao tbServico, e finalmente, remover seu atributo SER_CODIGO. */


-- 9) (Tentar) remover a tabela tbServico.

DROP TABLE tbServico

/* JUSTIFICATIVA:
	Se tornou facil remover a tabela tbServico por conta da remocao de sua Primary Key e respectivo atributo na
	questao anterior. */


-- 10) Remover a tabela tbPecaOrdemServ.

DROP TABLE tbPecaOrdemServ

	/* JUSTIFICATIVA:
	A remocao da tabela tbPecaOrdemServ e simples por conta de nao haver nenhuma restricao Foreign Key de outra tabela
	que se referencia a sua Primary Key, visto que as Foreign Keys contidas nela propria nao impedem a remocao */


/* Obs.: Justifique a execucao dos itens 8 a 10, ressaltando as tentativas sem sucesso dos itens 8 e 9. Elabore maneiras que seria possivel a execucao desses itens. */