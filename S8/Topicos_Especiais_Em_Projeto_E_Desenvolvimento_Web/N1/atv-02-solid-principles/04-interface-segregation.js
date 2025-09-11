// Questão 4: Princípio da Segregação de Interfaces (ISP)

// Contexto: Uma interface "gorda" Trabalhador define métodos para trabalhar e
// comer. Uma classe Robô implementa essa interface, mas o método comer não se
// aplica a um robô.

// Desafio: Refatore o código segregando a interface ITrabalhador em interfaces
// menores e mais específicas, de forma que as classes implementem apenas os métodos
// que fazem sentido para elas.

// exemplo previo
// Em JavaScript, interfaces são conceituais, mas podemos simular com classes base
/* 
class ITrabalhador {
	trabalhar() {
		throw new Error("Método 'trabalhar' deve ser implementado");
	}
	comer() {
		throw new Error("Método 'comer' deve ser implementado");
	}
}

class Humano extends ITrabalhador {
	trabalhar() {
		console.log('Humano trabalhando...');
	}
	comer() {
		console.log('Humano comendo...');
	}
}

class Robo extends ITrabalhador {
	trabalhar() {
		console.log('Robô trabalhando...');
	}
	comer() {
		// Este método não faz sentido para um robô
		throw new Error('Robôs não comem!');
	}
}
*/

// base interface
class IWorker {
	work() {
		throw new Error('feed function must be implemented');
	}
}
// composed interface (segregates here)
class IFeedableWorker extends IWorker {
	feed() {
		throw new Error('feed function must be implemented');
	}
}

// implement composed/segregated interface
class Human extends IFeedableWorker {
	feed = () => console.log('human eating...');
	work = () => console.log('human working...');
}
// implement base interface
class Robot extends IWorker {
	work = () => console.log('robot working...');
}

function main() {
	const man = new Human();
	const machine = new Robot();

	console.log('lunch time:');
	man.feed();
	console.log('---');

	console.log('back to work:');
	man.work();
	machine.work();
}

main();
