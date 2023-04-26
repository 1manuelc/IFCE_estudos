USE SistemaAcademicoBCC

INSERT INTO tbCurso
VALUES	('Engenharia de Aquicultura', 'EAQ', 3200, 'Superior'),
		('Licenciatura em Química', 'QUI', 3000, 'Superior'),
		('Licenciatura em Física', 'FIS', 3200, 'Superior'),
		('Técnico em Agricultura', 'AGR', 1200, 'Técnico')

INSERT INTO tbDisciplina
VALUES	('Português Aplicado', 40, 6),
		('Informática Aplicada', 80, 6),
		('Química Orgânica', 120, 7),
		('Química Inorgânica', 80, 7),
		('Física Quântica', 80, 8)

INSERT INTO tbProfessor
VALUES	('Raimundo José', 'raimundojose@ifce.edu.br', '01/01/2010'),
		('Maria Esmeralda', 'esmeralda@ifce.edu.br', '05/10/2012'),
		('Pedro Emanuel', 'pedroe@ifce.edu.br', '10/02/2015'),
		('José Augusto', 'jaugusto@ifce.edu.br', '15/04/2017')

INSERT INTO tbAluno (ALU_NOME, ALU_MATRICULA, ALU_CIDADE, ALU_SEXO, CUR_CODIGO)
VALUES	('Augusto Nascimento', 2018101, 'Tianguá', 'M', 8),
		('Carla Albuquerque', 2018102, 'Viçosa', 'F', 7),
		('Maria Aparecida', 2018103, 'Tianguá', 'F', 9),
		('Marcos Aurélio', 2018104, 'Ibiapina', 'M', 8),
		('Paula Fernanda', 2018105, 'Tianguá', 'F', 7)

INSERT INTO tbOfertaDisciplina
VALUES	(41, 11, 2018, 1, 'Tarde', 30),
		(42, 12, 2018, 1, 'Noite', 40),
		(43, 13, 2018, 1, 'Tarde', 30),
		(44, 13, 2018, 1, 'Tarde', 30),
		(45, 14, 2018, 1, 'Noite', 40)

INSERT INTO tbAlunoMatricula
VALUES	(46, 29),
		(47, 30),
		(48, 31),
		(49, 32),
		(50, 33)