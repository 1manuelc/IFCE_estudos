// Questão 9: Princípio da Segregação de Interfaces (ISP) - Prática 2

// Contexto: Uma interface de "gestão de documentos" (IGestaoDocumento) possui
// métodos para abrir, salvar e imprimir. Um DocumentoApenasLeitura não deveria
// poder implementar o método salvar.

// Desafio: Refatore a estrutura de interfaces para que a classe
// DocumentoApenasLeitura não seja forçada a ter um método salvar.

// exemplo previo
// Simulando interface com classe base
/*
class IGestaoDocumento {
	abrir() {}
	salvar() {}
	imprimir() {}
}
class DocumentoEditavel extends IGestaoDocumento {
	abrir() {
		console.log('Abrindo documento editável...');
	}
	salvar() {
		console.log('Salvando documento editável...');
	}
	imprimir() {
		console.log('Imprimindo documento editável...');
	}
}
class DocumentoApenasLeitura extends IGestaoDocumento {
	abrir() {
		console.log('Abrindo documento de leitura...');
	}
	salvar() {
		// Problema: este método não deveria existir aqui.
		throw new Error(
			'Não é possível salvar um documento de apenas leitura.',
		);
	}
	imprimir() {
		console.log('Imprimindo documento de leitura...');
	}
}
*/

// base document abstraction
class IDocument {
	constructor(data) {
		this.data = data;
	}
}

// base capacities
class IReadable extends IDocument {
	open() {
		throw new Error('open document method must be implemented');
	}
}
class IPrintable extends IDocument {
	print() {
		throw new Error('print document method must be implemented');
	}
}
class IWritable extends IDocument {
	save() {
		throw new Error('save document method must be implemented');
	}
}

// concrete classes
class ReadOnlyDocument extends IReadable {
	constructor() {
		super();
		// adds printing capacity with mixin
		Object.assign(this, {
			print: () => console.log('printing readonly document...'),
		});
	}
	open() {
		console.log('opening readonly document...');
	}
}

class WritableDocument extends IWritable {
	constructor() {
		super();
		Object.assign(this, {
			// adds opening and printing capacities with mixins
			open: () => console.log('opening document...'),
			print: () => console.log('printing document...'),
		});
	}
	save() {
		console.log('saving document...');
	}
}
