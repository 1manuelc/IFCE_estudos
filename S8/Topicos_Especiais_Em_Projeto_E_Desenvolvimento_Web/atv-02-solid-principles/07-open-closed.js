// Questão 7: Princípio Aberto/Fechado (OCP) - Prática 2

// Contexto: Uma classe ExportadorDeArquivos exporta dados para diferentes formatos.
// Adicionar um novo formato (ex: XML) exige modificar o método exportar.

// Desafio: Refatore a classe para que ela seja fechada para modificação, mas
// aberta para extensão. Crie uma estrutura que permita adicionar novos formatos de
// exportação sem alterar o código existente.

// exemplo previo:
/*
class ExportadorDeArquivos {
	exportar(dados, formato) {
		if (formato === 'CSV') {
			console.log('Exportando dados para CSV...');
			// Lógica de exportação para CSV
		} else if (formato === 'JSON') {
			console.log('Exportando dados para JSON...');
			// Lógica de exportação para JSON
		} else {
			throw new Error('Formato não suportado');
		}
	}
}
*/

// base strategy interface
class IExportFileStrategy {
	export() {
		throw new Error('export function needs to be implemented');
	}
}

// concrete strategies
class ExportFileToXmlStrategy extends IExportFileStrategy {
	export(data) {
		console.log(`sucessfully exported ${JSON.stringify(data)} to data.xml`);
	}
}
class ExportFileToCsvStrategy extends IExportFileStrategy {
	export(data) {
		console.log(`sucessfully exported ${JSON.stringify(data)} to data.csv`);
	}
}
class ExportFileToJsonStrategy extends IExportFileStrategy {
	export(data) {
		console.log(
			`sucessfully exported ${JSON.stringify(data)} to data.json`,
		);
	}
}

// higher-order service
class ExportFileService {
	constructor() {
		this.strategies = {
			csv: new ExportFileToCsvStrategy(),
			xml: new ExportFileToXmlStrategy(),
			json: new ExportFileToJsonStrategy(),
		};
	}
	/**
	 * @param {'xml' | 'csv'  | 'json'} format
	 * @param {any} data
	 */
	export(format, data) {
		const strategy = this.strategies[format];
		if (strategy) {
			strategy.export(data);
			return;
		}

		console.error('Unsupported or invalid exporting format');
		return;
	}
}

function main() {
	const data = { hello: 'javascript' };
	const ExportService = new ExportFileService();
	ExportService.export('xml', data);
	ExportService.export('csv', data);
	ExportService.export('json', data);
}

main();
