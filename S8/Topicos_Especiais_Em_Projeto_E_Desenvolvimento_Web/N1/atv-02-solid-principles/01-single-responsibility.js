// Questão 1: Princípio da Responsabilidade Única (SRP)

// Contexto: Uma classe Relatório é responsável por buscar dados de um banco de 
// dados, processar esses dados e depois formatá-los

// Desafio: Refatore o código acima para que cada classe tenha uma única 
// responsabilidade. Crie classes separadas para busca de dados, processamento e 
// formatação.

// exemplo previo
/*
class Relatorio {
	constructor(dados) {
		this.dados = dados;
	}
	buscarDadosDoBanco() {
		// Simula a busca de dados complexos
		console.log('Buscando dados no banco...');
		return { id: 1, valor: 100, data: new Date() };
	}
	processarDados() {
		// Simula um processamento
		console.log('Processando dados...');
		const dadosProcessados = this.dados.valor * 1.1;
		return dadosProcessados;
	}
	formatarParaHTML() {
		const dadosProcessados = this.processarDados();
		return `<div><h1>Relatório</h1><p>Valor Final: ${dadosProcessados}</p></div>`;
	}
}
*/

class Report {
	constructor(data) {
		this.data = data;
	}
}

class ReportRepository {
	getReports() {
		return new Promise((resolve) => {
			console.log('fetching data...');
			setTimeout(() => {
				const response = { id: 1, valor: 100, date: new Date() };
				console.log('data fetched: ', response);
				resolve(response);
			}, 500);
		});
	}
}

class ReportProcessor {
	processReport(data) {
		// Simula um processamento
		return data.valor * 1.1;
	}
}

class ReportFormatter {
	formatToHTML(finalData) {
		return new Report(
			`<div><h1>Relatório</h1><p>Valor Final: ${finalData}</p></div>`,
		);
	}
}

async function main() {
	const Repository = new ReportRepository();
	const data = await Repository.getReports();

	const Processor = new ReportProcessor();
	const processedData = Processor.processReport(data);

	const Formatter = new ReportFormatter();
	const report = Formatter.formatToHTML(processedData);

	console.log('final report', report);
}

main();
