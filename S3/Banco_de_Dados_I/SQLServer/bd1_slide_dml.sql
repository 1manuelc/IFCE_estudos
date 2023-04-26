USE SistemaAcademicoBCC

INSERT INTO tbCurso
VALUES	('Engenharia de Aquicultura', 'EAQ', 3200, 'Superior'),
		('Licenciatura em Qu�mica', 'QUI', 3000, 'Superior'),
		('Licenciatura em F�sica', 'FIS', 3200, 'Superior'),
		('T�cnico em Agricultura', 'AGR', 1200, 'T�cnico')

INSERT INTO tbDisciplina
VALUES	('Portugu�s Aplicado', 40, 6),
		('Inform�tica Aplicada', 80, 6),
		('Qu�mica Org�nica', 120, 7),
		('Qu�mica Inorg�nica', 80, 7),
		('F�sica Qu�ntica', 80, 8)

INSERT INTO tbProfessor
VALUES	('Raimundo Jos�', 'raimundojose@ifce.edu.br', '01/01/2010'),
		('Maria Esmeralda', 'esmeralda@ifce.edu.br', '05/10/2012'),
		('Pedro Emanuel', 'pedroe@ifce.edu.br', '10/02/2015'),
		('Jos� Augusto', 'jaugusto@ifce.edu.br', '15/04/2017')

INSERT INTO tbAluno (ALU_NOME, ALU_MATRICULA, ALU_CIDADE, ALU_SEXO, CUR_CODIGO)
VALUES	('Augusto Nascimento', 2018101, 'Tiangu�', 'M', 8),
		('Carla Albuquerque', 2018102, 'Vi�osa', 'F', 7),
		('Maria Aparecida', 2018103, 'Tiangu�', 'F', 9),
		('Marcos Aur�lio', 2018104, 'Ibiapina', 'M', 8),
		('Paula Fernanda', 2018105, 'Tiangu�', 'F', 7)

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