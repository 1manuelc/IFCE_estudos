/*	30/05/2023
	Fun��es Agregadas:
	Conceito:
		Fun��es que realizam opera��es entre colunas
		visando retornar um �nico valor com contexto.

	Exemplos: 
		AVG(m�dia), MIN(menor valor), MAX(maior valor),
		SUM(soma) e COUNT(quantidade de valores).

	Observa��es:
		0) Fun��es s�o aplicadas somente a execu��o do WHERE,
		ou seja, ap�s selecionar as tuplas com condi��es.

		1) COUNT sozinho conta a quantidade de tuplas de uma tabela.

		2) Ao utilizar fun��es na cl�usula SELECT, n�o ser� poss�vel
		fazer sele��o sem fun��es, pois a quantidade de tuplas difere
		muito.
			
			exemplo:	SELECT	AVG(CUR_CARGA_HORARIA) M�dia,
								*
						--> Retorna um erro dizendo que n�o est�o
						contidas somente fun��es agregadas.
*/

USE SistemaAcademicoBCC

-- Exemplo de m�dia, m�ximo, m�nimo, soma e contagem.
SELECT	AVG(CUR_CARGA_HORARIA) M�dia,
		MAX(CUR_CARGA_HORARIA) M�xima,
		MIN(CUR_CARGA_HORARIA) M�nima,
		SUM(CUR_CARGA_HORARIA) Soma,
		COUNT(CUR_CARGA_HORARIA) Quantidade
FROM tbCurso

-- Contagem somente de valores distintos.
SELECT COUNT(DISTINCT CUR_NIVEL) 'Quantidade de Cursos'
FROM tbCurso

-- Exemplos em sala:
	-- Quantidade de alunos de Tiangu�.
		SELECT COUNT(ALU_CODIGO) 'Alunos de Tiangu�'
		FROM tbAluno
		WHERE ALU_CIDADE LIKE 'Tiangu[�a]'

	-- Maior carga hor�ria dos cursos de n�vel t�cnico.
		SELECT MAX(CUR_CARGA_HORARIA) 'Maior carga hor�ria de curso t�cnico'
		FROM tbCurso
		WHERE CUR_NIVEL = 'T�cnico'

	-- Quantidade de cidades diferentes dos alunos.
		SELECT COUNT(DISTINCT ALU_CIDADE) 'Cidades dos alunos'
		FROM tbAluno