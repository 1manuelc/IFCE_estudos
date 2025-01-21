import { createServer } from "node:net";

const clients = new Map();

const server = createServer((socket) => {
	const clientId = Math.random().toString(36).substring(2, 15);
	clients.set(socket, clientId);
	console.log(`Cliente ${clientId} conectado`);

	socket.on("data", (data) => {
		try {
			const message = JSON.parse(data);

			if (message.values && message.values.length === 4) {
				const average =
					message.values.reduce((sum, value) => sum + value, 0) / 4;
				const response = {
					clientId: clientId,
					average: average,
				};
				socket.write(JSON.stringify(response));
			} else {
				console.log(`Mensagem inválida do cliente ${clientId}`);
				socket.write(JSON.stringify({ error: "Mensagem inválida" }));
			}
		} catch (error) {
			console.error(
				`Erro ao processar mensagem do cliente ${clientId}: ${error}`,
			);
			socket.write(JSON.stringify({ error: "Erro ao processar mensagem" }));
		}
	});

	socket.on("end", () => {
		clients.delete(socket);
		console.log(`Cliente ${clientId} desconectado`);
	});
});

server.listen(8080, () => {
	console.log("Servidor escutando na porta 8080");
});
