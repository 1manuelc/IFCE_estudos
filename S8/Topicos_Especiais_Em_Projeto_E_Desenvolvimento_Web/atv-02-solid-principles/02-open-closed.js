// Questão 2: Princípio Aberto/Fechado (OCP)

// Contexto: Temos uma função que calcula o desconto para diferentes tipos de
// clientes. Se um novo tipo de  cliente for adicionado (ex: "Platinum"), a função
// calcularDesconto precisará ser modificada, violando o OCP.

// Desafio: Refatore o código usando um padrão (como Strategy ou classes
// polimórficas) para que seja possível adicionar novos tipos de clientes com suas
// próprias regras de desconto sem modificar a classe GerenciadorDeDescontos.

// exemplo previo
/*
class GerenciadorDeDescontos {
	calcularDesconto(cliente) {
		if (cliente.tipo === 'Normal') {
			return cliente.valorCompra * 0.05;
		} else if (cliente.tipo === 'Vip') {
			return cliente.valorCompra * 0.1;
		} else if (cliente.tipo === 'Premium') {
			return cliente.valorCompra * 0.15;
		}
		return 0;
	}
}
*/

// base strategy interface
class IDiscountStrategy {
	calculateDiscount() {
		throw new Error('function needs to be overrided');
	}
}

// strategy-specialized classes
class NormalClientDiscountStrategy extends IDiscountStrategy {
	calculateDiscount(value) {
		return value * 0.05;
	}
}
class VipClientDiscountStrategy extends IDiscountStrategy {
	calculateDiscount(value) {
		return value * 0.1;
	}
}
class PremiumClientDiscountStrategy extends IDiscountStrategy {
	calculateDiscount(value) {
		return value * 0.15;
	}
}

// high level service that uses specialized strategies
class DiscountService {
	constructor() {
		this.strategies = {
			normal: new NormalClientDiscountStrategy(),
			vip: new VipClientDiscountStrategy(),
			premium: new PremiumClientDiscountStrategy(),
		};
	}

	/**
	 * @param {'normal' | 'vip' | 'premium'} costumerType
	 * @param {number} value
	 */
	calculateDiscount(costumerType, value) {
		const strategy = this.strategies[costumerType];

		if (strategy) {
			return strategy.calculateDiscount(value);
		}

		throw new Error('Invalid costumer type');
	}
}

function main() {
	const discount = new DiscountService();

	console.log('costumer\tvalue\tdiscount');
	console.log('---');
	console.log('normal\t\t$100\t$', discount.calculateDiscount('normal', 100));
	console.log('vip\t\t$100\t$', discount.calculateDiscount('vip', 100));
	console.log(
		'premium\t\t$100\t$',
		discount.calculateDiscount('premium', 100),
	);
}

main();
