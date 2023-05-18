USE SistemaAcademicoBCC

-- SQL n�o � case sensitive, pode-se usar qualquer case que dar� no mesmo.
-- Flexibilizar os caracteres possivelmente acentuados [e�] essencial.
/*	Imaginar cen�rios de nomes parecidos com flexibilidade ou rigorosidade:
	p.ex.: Vi[c�]osa, Vi[c�]osa do Cear[a�], e se houver Vi�osa do Maranh�o? */

/*	Utilizando os comparadores usuais para Strings, eles levam em considera��o
	a exata cadeia digitada, sem possibilidade de flexibiliza��o como o like */
-- Operador in � usado para comparar diferentes possibilidades de elementos em uma lista (especificamente)



-- Slide 23
DELETE FROM tbCoordenador
	WHERE	COO_NUMERO IS NULL OR
			COO_CODIGO BETWEEN 8 AND 10 OR
			COO_RUA LIKE 'Av. %' OR
			COO_UF NOT LIKE '[A-Z][A-Z]' OR
			COO_CIDADE LIKE 'Tiangu[a�]' OR
			COO_CIDADE LIKE 'Vi[c�]osa Do Cear[a�]' OR
			COO_CIDADE LIKE 'Vi[c�]osa' OR
			COO_CIDADE LIKE 'Ibiapina' OR
			COO_NOME LIKE '[AEIOU]%'

DELETE FROM tbCoordenador
	WHERE	(COO_NOME LIKE '% Silva %') OR (COO_NOME LIKE '% Silva')

DELETE FROM tbCoordenador
	WHERE	(COO_RUA LIKE 'Rua %') AND (COO_NUMERO IS NOT NULL)

DELETE FROM tbCoordenador
	WHERE	COO_CODIGO > 5 AND (COO_CIDADE LIKE 'Vi[c�]osa' OR COO_CIDADE LIKE 'Vi[c�]osa Do Cear[a�]')

DELETE FROM tbCoordenador
	WHERE	(COO_CIDADE NOT LIKE 'Tiangu[a�]') OR (COO_CPF NOT LIKE '[0-9][0-9][0-9].[0-9][0-9][0-9].[0-9][0-9][0-9]-[0-9][0-9]')

DELETE FROM tbCoordenador
	WHERE COO_RUA IN ('Rua A', 'Rua B', 'Rua X')



-- Slide 24
DELETE FROM tbDisciplina
	WHERE DIS_CODIGO = 10

DELETE FROM tbCurso
	WHERE (CUR_CARGA_HORARIA BETWEEN 500 AND 1000)
	
DELETE FROM tbAluno
	WHERE ALU_TELEFONE IS NULL

DELETE FROM tbAluno
	WHERE ALU_NOME LIKE 'J%' AND ALU_NOME NOT LIKE '%A%'

DELETE FROM tbAluno
	WHERE	ALU_CIDADE LIKE 'VI[C�]OSA' OR
			ALU_CIDADE LIKE 'VI[C�]OSA %' OR
			ALU_CIDADE LIKE 'TIANGU[A�]' OR
			ALU_CIDADE LIKE 'UBAJARA' OR
			ALU_CIDADE LIKE 'IBIAPINA'

DELETE FROM tbCurso
	WHERE (CUR_CARGA_HORARIA < 1000 AND CUR_CARGA_HORARIA > 4000) AND (CUR_NOME NOT LIKE '%INF%') AND (CUR_NIVEL IS NOT NULL)

DELETE FROM tbAluno
	WHERE (ALU_CODIGO = 10) OR (ALU_NOME LIKE '%O')

DELETE FROM tbAluno
	WHERE	ALU_NOME LIKE '% JOS[E�] %' AND
			ALU_CPF NOT LIKE '%-00'

DELETE FROM tbAluno
	WHERE ALU_CPF NOT LIKE '[0-9][0-9][0-9].[0-9][0-9][0-9].[0-9][0-9][0-9]-[0-9][0-9]'


DELETE FROM tbCurso
	WHERE	(CUR_NIVEL NOT LIKE 'T[e�]cnico') OR (CUR_NIVEL NOT LIKE 'Superior') AND
			(CUR_CARGA_HORARIA BETWEEN 1000 AND 1500) AND
			CUR_SIGLA LIKE '%[0-9]%'