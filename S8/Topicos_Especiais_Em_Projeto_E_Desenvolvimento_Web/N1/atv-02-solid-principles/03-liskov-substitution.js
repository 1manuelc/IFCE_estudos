// Questão 3: Princípio da Substituição de Liskov (LSP)

// Contexto: Temos uma classe Ave com um método voar. A classe Pinguim herda de Ave,
// mas um pinguim não voa. Lançar um erro no método voar da classe Pinguim viola o 
// LSP, pois Pinguim não pode ser substituído por Ave sem quebrar o programa.

// Desafio: Refatore a hierarquia de classes para que o LSP não seja violado. Pense
// em como estruturar as classes para que Pinguim não precise implementar um método
// voar que não faz sentido para ele. (Dica: Crie classes mais específicas como 
// AveVoadora).

// exemplo previo
/* 
class Ave {
	voar() {
		console.log('Estou voando!');
	}
}
class Pinguim extends Ave {
	voar() {
		throw new Error('Pinguins não podem voar!');
	}
	nadar() {
		console.log('Estou nadando!');
	}
}
function fazerAveVoar(ave) {
	ave.voar();
}
*/

// base class
class Bird {
	constructor(species) {
		this.species = species;
	}
}

// flying specialized class
class FlyingBird extends Bird {
	constructor(species) {
		super(species);
		this.canFly = true;
	}

	fly() {
		console.log(this.species, 'flying...');
	}
}

// non-flying specialized class
class NonFlyingBird extends Bird {
	constructor(species) {
		super(species);
		this.canFly = false;
	}

	walk() {
		console.log(this.species, 'moonwalking...');
	}
}

function main() {
	const eagle = new FlyingBird('eagle');
	console.log('eagle canFly:', eagle.canFly);
	eagle.fly();

	const penguin = new NonFlyingBird('penguin');
	console.log('penguin canFly:', penguin.canFly);
	penguin.walk();
}

main();
