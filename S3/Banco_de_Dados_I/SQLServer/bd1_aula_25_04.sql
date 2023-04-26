/*	Componente DML (Linguagem de Manipula��o de Dados)
	--> Agora n�o estamos usando mais DDL, mesmo com opera��es similares estaremos
	definindo dados e n�o estruturas.

	Objetivo:
		Inserir, alterar, excluir e consultar.

01) INSERT
		Para inserir dados em uma tabela, usamos o comando INSERT.
		L�-se: "inserir linha na tabela".

	Sintaxe:
		INSERT INTO <table_name> 
		(<column_name1>, <column_name2>, <column_nameN>) 
		
		--> com exce��o de colunas com a propriedade IDENTITY que � auto-incrementada.

		VALUES -- (� uma cl�usula).
		(<value1>, <value2>, <valueN>)

		--> respectivamente para cada coluna.

		Obs: 
			* se o nome das colunas for omitido, devemos seguir a ordem de cria��o das mesmas para
			preench�-las.
			* devemos ter cuidado com o valor a ser atribu�do e o tipo de dados definido para o dado.
				* VARCHAR, BIT E DATETIME deve ser preenchido com aspas simples: 'sql'.
				* parte fracion�ria em n�meros deve ser separada por ".": 4.5.
*/


-- 01.1) Inser��o de Linha em Banco de Dados preexistente.
	USE SistemaAcademicoBCC

	INSERT INTO tbCurso (CUR_NOME, CUR_SIGLA, CUR_CARGA_HORARIA, CUR_NIVEL)
	VALUES ('Inform�tica para Internet', 'IFINT', 1000, 'T�cnico')-- Adicionar + de 1 -- , ('Inform�tica', 'INF', 1200, 'T�cnico')


/* 01.2) Inser��o de Valores Nulos		
	I) N�o definir coluna e valor
		INSERT INTO tbCurso (CUR_NOME, CUR_CARGA_HORARIA, CUR_NIVEL)
		VALUES ('T�cnico em Aquicultura', 1200, 'T�cnico')
			-- Coluna que ficar ausente receber� automaticamente o NULL, a depender da configura��o da estrutura,

	II) Definir valor como NULL
		INSERT INTO tbCurso (CUR_NOME, CUR_SIGLA, CUR_CARGA_HORARIA, CUR_NIVEL)
		VALUES ('T�cnico em Aquicultura', NULL, 1200, 'T�cnico')

	Exemplo: */
	INSERT INTO tbCurso
	VALUES ('T�cnico em Aquicultura', NULL, 1200, 'T�cnico')

-- 01.3) Inser��o de Valores nas Chaves Estrangeiras
	INSERT INTO tbDisciplina (DIS_NOME, DIS_CARGA_HORARIA, CUR_CODIGO)
	VALUES ('Desenvolvimento Web', 80, 1002)	/* valor 1002 foi consultado na outra tabela tbCurso
												atrav�s da op��o "Selecionar 1000 linhas superiores". */

/* 01.4) Poss�veis erros no script:
	* inserir char em n�mero, o contr�rio � pos�vel
	* dados atribu�dos maiores que a estrutura definida (truncamento necess�rio)
	* FK n�o definida preenchida (integridade referencial)
	* deixar um atributo NOT NULL em branco, ou inserir NULL em coluna NOT NULL
	* n�o preencher todas as colunas referenciadas ou preencher a mais
	* inserir valor repetido em PK ou UK