/*	30/05/2023
	Funções Agregadas:
	Conceito:
		Funções que realizam operações entre colunas
		visando retornar um único valor com contexto.

	Exemplos: 
		AVG(média), MIN(menor valor), MAX(maior valor),
		SUM(soma) e COUNT(quantidade de valores).

	Observações:
		0) Funções são aplicadas somente a execução do WHERE,
		ou seja, após selecionar as tuplas com condições.

		1) COUNT sozinho conta a quantidade de tuplas de uma tabela.

		2) Ao utilizar funções na cláusula SELECT, não será possível
		fazer seleção sem funções, pois a quantidade de tuplas difere
		muito.
			
			exemplo:	SELECT	AVG(CUR_CARGA_HORARIA) Média,
								*
						--> Retorna um erro dizendo que não estão
						contidas somente funções agregadas.
*/

USE SistemaAcademicoBCC

-- Exemplo de média, máximo, mínimo, soma e contagem.
SELECT	AVG(CUR_CARGA_HORARIA) Média,
		MAX(CUR_CARGA_HORARIA) Máxima,
		MIN(CUR_CARGA_HORARIA) Mínima,
		SUM(CUR_CARGA_HORARIA) Soma,
		COUNT(CUR_CARGA_HORARIA) Quantidade
FROM tbCurso

-- Contagem somente de valores distintos.
SELECT COUNT(DISTINCT CUR_NIVEL) 'Quantidade de Cursos'
FROM tbCurso

-- Exemplos em sala:
	-- Quantidade de alunos de Tianguá.
		SELECT COUNT(ALU_CODIGO) 'Alunos de Tianguá'
		FROM tbAluno
		WHERE ALU_CIDADE LIKE 'Tiangu[áa]'

	-- Maior carga horária dos cursos de nível técnico.
		SELECT MAX(CUR_CARGA_HORARIA) 'Maior carga horária de curso técnico'
		FROM tbCurso
		WHERE CUR_NIVEL = 'Técnico'

	-- Quantidade de cidades diferentes dos alunos.
		SELECT COUNT(DISTINCT ALU_CIDADE) 'Cidades dos alunos'
		FROM tbAluno