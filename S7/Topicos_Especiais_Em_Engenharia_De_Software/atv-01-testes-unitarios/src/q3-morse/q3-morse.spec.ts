import { Morse } from './q3-morse';

describe('Morse class', () => {
	const m = new Morse();

	describe('morse()', () => {
		it('should convert basic text to morse', () => {
			expect(m.morse('SOS')).toBe('... --- ...');
		});

		it('should convert mixed text and numbers', () => {
			expect(m.morse('HELLO 123')).toBe(
				'.... . .-.. .-.. --- ....... .---- ..--- ...--'
			);
		});

		it('should handle lowercase input (should convert to uppercase implicitly)', () => {
			expect(m.morse('hello')).toBe('.... . .-.. .-.. ---');
		});
	});

	describe('unmorse()', () => {
		it('should convert morse to text', () => {
			expect(m.unmorse('... --- ...')).toBe('SOS');
		});

		it('should decode morse with numbers', () => {
			expect(m.unmorse('.... . .-.. .-.. --- / .---- ..--- ...--')).toBe(
				'HELLO 123'
			);
		});
	});

	describe('full validation', () => {
		it('should encode and decode to the same result (case insensitive)', () => {
			const original = 'Example 42';
			const encoded = m.morse(original);
			const decoded = m.unmorse(encoded);
			expect(decoded).toBe(original.toUpperCase());
		});
	});
});
