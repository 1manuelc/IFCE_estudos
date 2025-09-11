// Questão 10: Princípio da Inversão de Dependência (DIP) - Prática 2

// Contexto: Uma classe GerenciadorDePoliticas cria instâncias concretas de
// RegraDeNegocioA e RegraDeNegocioB, ficando fortemente acoplada a elas.

// Desafio: Modifique o GerenciadorDePoliticas para que ele não dependa mais de
// implementações concretas das regras de negócio. As regras devem ser injetadas na
// classe.

// exemplo previo
/*
class RegraDeNegocioA {
	executar() {
		console.log('Executando regra A');
	}
}
class RegraDeNegocioB {
	executar() {
		console.log('Executando regra B');
	}
}
class GerenciadorDePoliticas {
	constructor() {
		// Dependências concretas!
		this.regraA = new RegraDeNegocioA();
		this.regraB = new RegraDeNegocioB();
	}
	aplicarRegras() {
		this.regraA.executar();
		this.regraB.executar();
	}
}
*/

// base contract strategy
class IPolicyStrategy {
	execute() {
		throw new Error('execute function must be implemented');
	}
}

// low-level classes/concrete strategies
class APolicyStrategy extends IPolicyStrategy {
	async execute() {
		return new Promise((resolve) => {
			setTimeout(() => {
				resolve();
			}, 1500);
		});
	}
}
class BPolicyStrategy extends IPolicyStrategy {
	async execute() {
		return new Promise((resolve) => {
			setTimeout(() => {
				resolve();
			}, 500);
		});
	}
}

// high-level service class
class PolicyExecutionService {
	constructor(strategies = []) {
		this.strategies = strategies;
	}

	async executeAll() {
		let idx = 1;

		console.log(`Policies are starting...`);
		for (const strategy of this.strategies) {
			await strategy.execute();
			console.log(`policy ${idx}: success`);
			idx++;
		}
		console.log('All policies executed successfully');
	}
}

function main() {
	const PolicyService = new PolicyExecutionService([
		new APolicyStrategy(),
		new BPolicyStrategy(),
	]);

	PolicyService.executeAll();
}

main();
