// Questão 5: Princípio da Inversão de Dependência (DIP)

// Contexto: A classe de alto nível ServicoDeNotificacao depende diretamente da
// classe de baixo nível NotificadorDeEmail. Isso acopla o serviço de notificação a
// uma implementação específica (email).

// Desafio: Refatore o código para que ServicoDeNotificacao dependa de uma abstração
// (uma interface ou classe base) em vez de uma implementação concreta. Use injeção
// de dependência para fornecer a implementação do notificador.

// exemplo previo
/* 
class NotificadorDeEmail {
	enviar(mensagem) {
		console.log(`Enviando email: ${mensagem}`);
	}
}
class ServicoDeNotificacao {
	constructor() {
		this.notificador = new NotificadorDeEmail(); // Dependência direta!
	}
	notificar(mensagem) {
		this.notificador.enviar(mensagem);
	}
} 
*/

// base strategy contract
class INotificationStrategy {
	send() {
		throw new Error('send function must be implemented');
	}
}

// concrete strategies
class EmailNotificationStrategy extends INotificationStrategy {
	send(message, destinyEmail) {
		console.log(`Sending email to ${destinyEmail}: ${message}`);
	}
}
class SmsNotificationStrategy extends INotificationStrategy {
	send(message, destinyPhoneNumber) {
		console.log(`Sending sms to ${destinyPhoneNumber}: ${message}`);
	}
}

// high level service that injects concrete strategies
class NotificationService {
	constructor(notifyStrategy) {
		// notifyStrategy can be any concrete strategy passed via arg
		this.notifier = notifyStrategy;
	}

	send(message, destination) {
		console.log('initializing notification service...');
		this.notifier.send(message, destination);
	}
}

function main() {
	const phoneNumber = '88 9 0000-0000';
	const email = 'johndoe@acme.com';
	const message = 'pay your bill';

	const SmsService = new NotificationService(new SmsNotificationStrategy());
	SmsService.send(message, phoneNumber);
	console.log('---');

	const EmailService = new NotificationService(
		new EmailNotificationStrategy(),
	);
	EmailService.send(message, email);
}

main();
