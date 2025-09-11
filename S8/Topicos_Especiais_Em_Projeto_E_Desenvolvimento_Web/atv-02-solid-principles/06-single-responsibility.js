// Questão 6: Princípio da Responsabilidade Única (SRP) - Prática 2

// Contexto: Uma função processarPedido é responsável por validar o pedido, calcular
// o total e salvar o pedido no banco de dados.

// Desafio: Refatore esta função, quebrando-a em funções menores, cada uma com uma 
// única responsabilidade (ex: validarPedido, calcularTotalPedido, salvarPedido).

// exemplo previo
/*
function processarPedido(pedido) {
	// 1. Validação
	if (!pedido.id || !pedido.itens || pedido.itens.length === 0) {
		console.error('Pedido inválido!');
		return;
	}
	// 2. Cálculo do Total
	let total = 0;
	for (const item of pedido.itens) {
		total += item.preco * item.quantidade;
	}
	console.log(`Total calculado: ${total}`);
	// 3. Salvar no Banco de Dados
	console.log(`Salvando pedido ${pedido.id} no banco de dados...`);
	// db.save(pedido);

	return true;
}
*/

function validateOrder(order) {
	if (!order.id) {
		console.error('Invalid order: id not provided');
		return false;
	}

	if (!order.items || order.items.length === 0) {
		console.error('Invalid order: there are no items in cart');
		return false;
	}

	return true;
}

function calculateOrderTotal(order) {
	let total = 0;
	for (item of order.items) total += item.price * item.quantity;
	console.log(`order total value: $${total}`);
	return total;
}

function saveOrderInDb(order, total) {
	console.log(`saving order ${order.id}, $${total}`);
	console.log('order saved!');
}

function main() {
	const order = {
		id: 1,
		items: [
			{ id: '256', name: 'Gamer Mouse', price: 240, quantity: 1 },
			{ id: '384', name: 'Gamer Keyboard', price: 320, quantity: 3 },
			{ id: '512', name: 'Gamer Mousepad', price: 90, quantity: 2 },
		],
	};

	const isOrderValid = validateOrder(order);

	if (isOrderValid) {
		const total = calculateOrderTotal(order);
		saveOrderInDb(order, total);
		return;
	}
}

main();
