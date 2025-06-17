declare module 'morse' {
	const morse: {
		encode: (text: string) => string;
		decode: (morseCode: string) => string;
	};

	export = morse;
}
