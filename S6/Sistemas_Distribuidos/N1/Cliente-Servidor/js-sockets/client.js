import { Socket } from "node:net";
import * as rl from "node:readline"

const readline = rl.createInterface({
	input: process.stdin,
	output: process.stdout,
});

const client = new Socket();

client.connect(8080, "localhost", () => {
	console.log("Conectado ao servidor");

	const readValues = () => {
		readline.question("Digite 4 valores separados por espaço: ", (input) => {
			const values = input.split(" ").map(Number);
			if (values.length === 4 && values.every(Number.isFinite)) {
				const message = { values: values };
				client.write(JSON.stringify(message));
			} else {
				console.log("Entrada inválida. Digite 4 valores numéricos.");
				readValues();
			}
		});
	};

	readValues();

	client.on("data", (data) => {
		const response = JSON.parse(data);
		if (response.error) {
			console.error(response.error);
		} else {
			console.log(
				`Cliente ${response.clientId}: Média aritmética = ${response.average}`,
			);
		}
		readValues();
	});

	client.on("close", () => {
		console.log("Conexão fechada");
		readline.close();
	});
});
