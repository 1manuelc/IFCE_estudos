/*	Componente DML (Linguagem de Manipulação de Dados)
	--> Agora não estamos usando mais DDL, mesmo com operações similares estaremos
	definindo dados e não estruturas.

	Objetivo:
		Inserir, alterar, excluir e consultar.

01) INSERT
		Para inserir dados em uma tabela, usamos o comando INSERT.
		Lê-se: "inserir linha na tabela".

	Sintaxe:
		INSERT INTO <table_name> 
		(<column_name1>, <column_name2>, <column_nameN>) 
		
		--> com exceção de colunas com a propriedade IDENTITY que é auto-incrementada.

		VALUES -- (é uma cláusula).
		(<value1>, <value2>, <valueN>)

		--> respectivamente para cada coluna.

		Obs: 
			* se o nome das colunas for omitido, devemos seguir a ordem de criação das mesmas para
			preenchê-las.
			* devemos ter cuidado com o valor a ser atribuído e o tipo de dados definido para o dado.
				* VARCHAR, BIT E DATETIME deve ser preenchido com aspas simples: 'sql'.
				* parte fracionária em números deve ser separada por ".": 4.5.
*/


-- 01.1) Inserção de Linha em Banco de Dados preexistente.
	USE SistemaAcademicoBCC

	INSERT INTO tbCurso (CUR_NOME, CUR_SIGLA, CUR_CARGA_HORARIA, CUR_NIVEL)
	VALUES ('Informática para Internet', 'IFINT', 1000, 'Técnico')-- Adicionar + de 1 -- , ('Informática', 'INF', 1200, 'Técnico')


/* 01.2) Inserção de Valores Nulos		
	I) Não definir coluna e valor
		INSERT INTO tbCurso (CUR_NOME, CUR_CARGA_HORARIA, CUR_NIVEL)
		VALUES ('Técnico em Aquicultura', 1200, 'Técnico')
			-- Coluna que ficar ausente receberá automaticamente o NULL, a depender da configuração da estrutura,

	II) Definir valor como NULL
		INSERT INTO tbCurso (CUR_NOME, CUR_SIGLA, CUR_CARGA_HORARIA, CUR_NIVEL)
		VALUES ('Técnico em Aquicultura', NULL, 1200, 'Técnico')

	Exemplo: */
	INSERT INTO tbCurso
	VALUES ('Técnico em Aquicultura', NULL, 1200, 'Técnico')

-- 01.3) Inserção de Valores nas Chaves Estrangeiras
	INSERT INTO tbDisciplina (DIS_NOME, DIS_CARGA_HORARIA, CUR_CODIGO)
	VALUES ('Desenvolvimento Web', 80, 1002)	/* valor 1002 foi consultado na outra tabela tbCurso
												através da opção "Selecionar 1000 linhas superiores". */

/* 01.4) Possíveis erros no script:
	* inserir char em número, o contrário é posível
	* dados atribuídos maiores que a estrutura definida (truncamento necessário)
	* FK não definida preenchida (integridade referencial)
	* deixar um atributo NOT NULL em branco, ou inserir NULL em coluna NOT NULL
	* não preencher todas as colunas referenciadas ou preencher a mais
	* inserir valor repetido em PK ou UK