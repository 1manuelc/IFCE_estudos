USE SistemaAcademicoBCC

-- SQL não é case sensitive, pode-se usar qualquer case que dará no mesmo.
-- Flexibilizar os caracteres possivelmente acentuados [eé] essencial.
/*	Imaginar cenários de nomes parecidos com flexibilidade ou rigorosidade:
	p.ex.: Vi[cç]osa, Vi[cç]osa do Cear[aá], e se houver Viçosa do Maranhão? */

/*	Utilizando os comparadores usuais para Strings, eles levam em consideração
	a exata cadeia digitada, sem possibilidade de flexibilização como o like */
-- Operador in é usado para comparar diferentes possibilidades de elementos em uma lista (especificamente)



-- Slide 23
DELETE FROM tbCoordenador
	WHERE	COO_NUMERO IS NULL OR
			COO_CODIGO BETWEEN 8 AND 10 OR
			COO_RUA LIKE 'Av. %' OR
			COO_UF NOT LIKE '[A-Z][A-Z]' OR
			COO_CIDADE LIKE 'Tiangu[aá]' OR
			COO_CIDADE LIKE 'Vi[cç]osa Do Cear[aá]' OR
			COO_CIDADE LIKE 'Vi[cç]osa' OR
			COO_CIDADE LIKE 'Ibiapina' OR
			COO_NOME LIKE '[AEIOU]%'

DELETE FROM tbCoordenador
	WHERE	(COO_NOME LIKE '% Silva %') OR (COO_NOME LIKE '% Silva')

DELETE FROM tbCoordenador
	WHERE	(COO_RUA LIKE 'Rua %') AND (COO_NUMERO IS NOT NULL)

DELETE FROM tbCoordenador
	WHERE	COO_CODIGO > 5 AND (COO_CIDADE LIKE 'Vi[cç]osa' OR COO_CIDADE LIKE 'Vi[cç]osa Do Cear[aá]')

DELETE FROM tbCoordenador
	WHERE	(COO_CIDADE NOT LIKE 'Tiangu[aá]') OR (COO_CPF NOT LIKE '[0-9][0-9][0-9].[0-9][0-9][0-9].[0-9][0-9][0-9]-[0-9][0-9]')

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
	WHERE	ALU_CIDADE LIKE 'VI[CÇ]OSA' OR
			ALU_CIDADE LIKE 'VI[CÇ]OSA %' OR
			ALU_CIDADE LIKE 'TIANGU[AÁ]' OR
			ALU_CIDADE LIKE 'UBAJARA' OR
			ALU_CIDADE LIKE 'IBIAPINA'

DELETE FROM tbCurso
	WHERE (CUR_CARGA_HORARIA < 1000 AND CUR_CARGA_HORARIA > 4000) AND (CUR_NOME NOT LIKE '%INF%') AND (CUR_NIVEL IS NOT NULL)

DELETE FROM tbAluno
	WHERE (ALU_CODIGO = 10) OR (ALU_NOME LIKE '%O')

DELETE FROM tbAluno
	WHERE	ALU_NOME LIKE '% JOS[EÉ] %' AND
			ALU_CPF NOT LIKE '%-00'

DELETE FROM tbAluno
	WHERE ALU_CPF NOT LIKE '[0-9][0-9][0-9].[0-9][0-9][0-9].[0-9][0-9][0-9]-[0-9][0-9]'


DELETE FROM tbCurso
	WHERE	(CUR_NIVEL NOT LIKE 'T[eé]cnico') OR (CUR_NIVEL NOT LIKE 'Superior') AND
			(CUR_CARGA_HORARIA BETWEEN 1000 AND 1500) AND
			CUR_SIGLA LIKE '%[0-9]%'