/* #3. Implemente uma base de dados chamada (bdRH) com uma tabela funcionários (tbFuncionarios) 
com os atributos (idFuncionario, nome, idade, sexo, endereco, sal, rg) em seguida implemente 
outra tabela chamada (tbDependentes) com pelo menos 5 atributos inclusive a chave estrangeira.
Usar scripts SQL para cada tabela:
	a) Insira pelo menos 5 tuplas (valores);
	b) Altere os valores das linhas 3, 4 e 5;
	c) Delete as tuplas, 1 e 2. 
*/

CREATE DATABASE bdRH;
USE bdRH;

CREATE TABLE tbFuncionarios (
	idFuncionario INT NOT NULL AUTO_INCREMENT,
    nome VARCHAR(50) NOT NULL,
    idade INT,
    sexo VARCHAR(1),
    endereco VARCHAR(100),
    salario DECIMAL(10,2),
    rg VARCHAR(12) NOT NULL,
	
    PRIMARY KEY(idFuncionario)
);

CREATE TABLE tbDependentes (
	idDependente INT NOT NULL AUTO_INCREMENT,
    nome VARCHAR(50) NOT NULL,
    idade INT,
    sexo VARCHAR(1),
    parentesco VARCHAR(25),
    idFuncionario INT,
    
    PRIMARY KEY(idDependente),
    FOREIGN KEY(idFuncionario) REFERENCES tbFuncionario(idFuncionario)
);

-- a) Insira pelo menos 5 tuplas (valores);
INSERT INTO tbFuncionarios
	(nome,				idade,	sexo,	endereco,			salario,	rg)
VALUES
	('Fernanda Lima', 	30, 	'F', 	'Rua E, 567', 		5500.25, 	'23456789012'),
	('Rafael Oliveira', 25, 	'M', 	'Avenida F, 890', 	4800.80, 	'45678901234'),
	('Juliana Santos', 	33, 	'F', 	'Travessa G, 123', 	6200.50, 	'56789012345'),
	('Pedro Silva', 	27, 	'M', 	'Rua H, 456', 		5300.75, 	'67890123456'),
	('Camila Pereira', 	38, 	'F', 	'Avenida I, 789', 	7500.00, 	'78901234567');
    
INSERT INTO tbDependentes 
	(nome, 					idade, 	sexo, 	parentesco, idFuncionario)
VALUES
	('Lucas Lima', 			10, 	'M', 	'Filho', 	1),
	('Isabela Oliveira', 	8, 		'F', 	'Filha', 	2),
	('Miguel Santos', 		5, 		'M', 	'Filho', 	3),
	('Laura Silva', 		12, 	'F', 	'Filha', 	4),
	('Enzo Pereira', 		7, 		'M', 	'Filho', 	5);
    
-- b) Altere os valores das linhas 3, 4 e 5;
UPDATE tbFuncionarios
SET nome = "Silvio Santos", 
	idade = 90, sexo = 'M', 
    endereco = 'Rua Abravanel, 200', 
    salario = 10000.00, 
    rg = '000000000000'
WHERE idFuncionario = 3;

UPDATE tbFuncionarios
SET nome = "Luiz Pedro", 
	idade = 22, sexo = 'M', 
    endereco = 'Rua Fictícia, 199', 
    salario = 2000.00, 
    rg = '010500609000'
WHERE idFuncionario = 4;

UPDATE tbFuncionarios
SET nome = "Márcia Souza", 
	idade = 41, sexo = 'F', 
    endereco = 'Rua Fictícia, 159', 
    salario = 3600.00, 
    rg = '112200402000'
WHERE idFuncionario = 5;

-- c) Delete as tuplas, 1 e 2.
DELETE FROM tbDependentes
WHERE idDependente IN (1, 2);
	