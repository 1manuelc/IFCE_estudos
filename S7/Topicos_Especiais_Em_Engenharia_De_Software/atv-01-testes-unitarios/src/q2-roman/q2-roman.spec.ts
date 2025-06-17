import { Roman } from './q2-roman';

describe('Roman class', () => {
	const roman = new Roman();

	describe('romanize()', () => {
		it('should convert 1 to I', () => {
			expect(roman.romanize(1)).toBe('I');
		});

		it('should convert 3999 to MMMCMXCIX', () => {
			expect(roman.romanize(3999)).toBe('MMMCMXCIX');
		});

		it('should convert typical number like 2024 to MMXXIV', () => {
			expect(roman.romanize(2024)).toBe('MMXXIV');
		});

		it('should throw error on input 0', () => {
			expect(() => roman.romanize(0)).toThrow('Error: cannot romanize zero');
		});

		it('should throw error on negative number', () => {
			expect(() => roman.romanize(-15)).toThrow(
				'Error: cannont romanize negative number'
			);
		});

		it('should throw error on number greater than 3999', () => {
			expect(() => roman.romanize(4000)).toThrow(
				'Error: cannot romanize numbers above 3999'
			);
		});
	});

	describe('unromanize()', () => {
		it('should convert I to 1', () => {
			expect(roman.unromanize('I')).toBe(1);
		});

		it('should convert MMMCMXCIX to 3999', () => {
			expect(roman.unromanize('MMMCMXCIX')).toBe(3999);
		});

		it('should convert MMXXIV to 2024', () => {
			expect(roman.unromanize('MMXXIV')).toBe(2024);
		});
	});
});
