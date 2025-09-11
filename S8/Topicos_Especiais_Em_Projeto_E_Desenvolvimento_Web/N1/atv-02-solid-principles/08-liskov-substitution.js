// Questão 8: Princípio da Substituição de Liskov (LSP) - Prática 2

// Contexto: O clássico problema do Retângulo/Quadrado. Uma classe Quadrado herda de
//  Retangulo. Alterar a altura de um quadrado deve também alterar sua largura, o
// que quebra o comportamento esperado da classe base Retangulo.

// Desafio: Uma função que espera um Retangulo pode se comportar de maneira
// inesperada se receber um Quadrado. Explique por que isso viola o LSP e proponha
// uma nova estrutura de classes que resolva o problema (Dica: talvez eles não
// devessem ter uma relação de herança direta).

// R: A solução prévia viola o LSP por considerar que todo retângulo pode ser um
// quadrado, o que não é verdade. Assim, é necessário abstrair um contrato que
// obriga as duas classes implementar de forma particular a função que retorna a
// área, independente de forma (largura e altura ou lado).

// exemplo previo
/*
class Retangulo {
	constructor(largura, altura) {
		this.largura = largura;
		this.altura = altura;
	}
	setLargura(valor) {
		this.largura = valor;
	}
	setAltura(valor) {
		this.altura = valor;
	}
	getArea() {
		return this.largura * this.altura;
	}
}
class Quadrado extends Retangulo {
	constructor(lado) {
		super(lado, lado);
	}
	setLargura(valor) {
		this.largura = valor;
		this.altura = valor;
	}

	setAltura(valor) {
		this.largura = valor;
		this.altura = valor;
	}
}
*/

// base abstraction
class IGeometricForm {
	getArea() {
		throw new Error('getArea function needs to be implemented');
	}
}

// concrete classes obligated to implement the abstraction
class Rectangle extends IGeometricForm {
	constructor(width, height) {
		super();
		this.width = width;
		this.height = height;
	}

	getHeight() {
		return this.height;
	}
	setHeight(height) {
		this.height = height;
	}
	getWidth() {
		return this.width;
	}
	setWidth(width) {
		this.width = width;
	}

	getArea() {
		return this.width * this.height;
	}
}
class Square extends IGeometricForm {
	constructor(side) {
		super();
		this.side = side;
	}

	setSide(side) {
		this.side = side;
	}

	getArea() {
		return this.side ** 2;
	}
}

function main() {
	const rect = new Rectangle(15, 3);
	const square = new Square(6);

	console.log('Rectangle area:', rect.getArea()); // 15 * 3 => 45
	console.log('Square area:', square.getArea()); // 6 ** 2 => 36

	rect.setHeight(4);
	square.setSide(7);

	console.log('Rectangle updated area:', rect.getArea()); // 15 * 4 => 60
	console.log('Square updated area:', square.getArea()); // 7 ** 2 => 49
}

main();
