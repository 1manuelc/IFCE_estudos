import { Calculator } from './q1-calculator';

describe('Calculator class', () => {
	const calc = new Calculator();

	describe('sum()', () => {
		describe('Common cases', () => {
			it('should sum positive numbers correctly', () => {
				expect(calc.sum(1, 3)).toBe(4);
			});

			it('should sum negative numbers correctly', () => {
				expect(calc.sum(-7, -14)).toBe(-21);
			});

			it('should sum positive and negative numbers correctly', () => {
				expect(calc.sum(1, -3)).toBe(-2);
			});

			it('should sum positive number and zero correctly', () => {
				expect(calc.sum(7, 0)).toBe(7);
			});

			it('should sum decimal numbes correctly', () => {
				expect(calc.sum(2.5, 3.5)).toBe(6);
			});
		});
	});

	describe('subtraction()', () => {
		describe('Common cases', () => {
			it('should subtract positive numbers correctly', () => {
				expect(calc.subtract(1, 3)).toBe(-2);
			});

			it('should subtract negative numbers correctly', () => {
				expect(calc.subtract(-7, -14)).toBe(7);
			});

			it('should subtract positive and negative numbers correctly', () => {
				expect(calc.subtract(1, -3)).toBe(4);
			});

			it('should subtract positive number and zero correctly', () => {
				expect(calc.subtract(7, 0)).toBe(7);
			});

			it('should subtract decimal numbes correctly', () => {
				expect(calc.subtract(2.5, 3.5)).toBe(-1);
			});
		});
	});

	describe('multiply()', () => {
		describe('Common cases', () => {
			it('should multiply positive numbers correctly', () => {
				expect(calc.multiply(1, 3)).toBe(3);
			});

			it('should multiply negative numbers correctly', () => {
				expect(calc.multiply(-7, -14)).toBe(98);
			});

			it('should multiply positive and negative numbers correctly', () => {
				expect(calc.multiply(1, -3)).toBe(-3);
			});

			it('should multiply positive number and zero correctly', () => {
				expect(calc.multiply(7, 0)).toBe(0);
			});

			it('should multiply decimal numbes correctly', () => {
				expect(calc.multiply(2.5, 3.5)).toBe(8.75);
			});
		});
	});

	describe('divide()', () => {
		describe('Common cases', () => {
			it('should divide positive numbers correctly', () => {
				expect(calc.divide(1, 3)).toBe(1 / 3);
			});

			it('should divide negative numbers correctly', () => {
				expect(calc.divide(-7, -14)).toBe(-7 / -14);
			});

			it('should divide positive and negative numbers correctly', () => {
				expect(calc.divide(1, -3)).toBe(1 / -3);
			});

			it('should divide positive number and zero correctly', () => {
				expect(calc.divide(7, 0)).toBe(7 / 0);
			});

			it('should divide decimal numbes correctly', () => {
				expect(calc.divide(2.5, 3.5)).toBe(2.5 / 3.5);
			});
		});

		describe('Special cases', () => {
			it('should divide zero per zero and return NaN', () => {
				expect(calc.divide(0, 0)).toBe(NaN);
			});

			it('should divide very big number per very small number correcly', () => {
				expect(calc.divide(987654321987654, 0.0000000001)).toBe(
					9.87654321987654e24
				);
			});
		});
	});

	describe('power()', () => {
		describe('Common cases', () => {
			it('should power positive base and exponent correctly', () => {
				expect(calc.power(5, 3)).toBe(125);
			});

			it('should power negative base and even exponent correctly', () => {
				expect(calc.power(-4, 2)).toBe(16);
			});

			it('should power negative base and odd exponent correctly', () => {
				expect(calc.power(-3, 3)).toBe(-27);
			});

			it('should power any number to 0 correctly', () => {
				expect(calc.power(20, 0)).toBe(1);
			});

			it('should power zero to any positive number correctly', () => {
				expect(calc.power(0, 2)).toBe(0);
			});

			it('should power zero to zero correctly', () => {
				expect(calc.power(0, 0)).toBe(1);
			});
		});

		describe('Special cases', () => {
			it('should power any number to negative exponent correctly', () => {
				expect(calc.power(2, -4)).toBe(0.0625);
			});

			it('should power with fractional exponent (square root)', () => {
				expect(calc.power(9, 0.5)).toBe(3);
			});

			it('should power with fractional exponent (cube root)', () => {
				expect(calc.power(27, 1 / 3)).toBeCloseTo(3, 5);
			});

			it('should handle very large base and small exponent', () => {
				expect(calc.power(1e10, 2)).toBe(1e20);
			});

			it('should handle very large exponent', () => {
				const result = calc.power(2, 1024);
				expect(result).toBe(Number.POSITIVE_INFINITY);
			});
		});
	});

	describe('sqrt()', () => {
		describe('Common cases', () => {
			it('should return square root of perfect square number', () => {
				expect(calc.sqrt(25)).toBe(5);
			});

			it('should return square root of zero', () => {
				expect(calc.sqrt(0)).toBe(0);
			});

			it('should return square root of a decimal number', () => {
				expect(calc.sqrt(2.25)).toBe(1.5);
			});
		});

		describe('Special cases', () => {
			it('should return NaN for negative input', () => {
				expect(calc.sqrt(-9)).toBeNaN();
			});

			it('should return very small result for very small input', () => {
				expect(calc.sqrt(1e-10)).toBeCloseTo(1e-5);
			});
		});
	});
});
