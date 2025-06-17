import morse from 'morse';

export class Morse {
	morse(text: string) {
		return morse.encode(text);
	}

	unmorse(code: string) {
		return morse.decode(code);
	}
}
