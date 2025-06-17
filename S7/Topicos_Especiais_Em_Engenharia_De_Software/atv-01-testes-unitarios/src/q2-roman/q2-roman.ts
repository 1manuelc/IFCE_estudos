import { toArabic, toRoman } from 'roman-numerals';

export class Roman {
	romanize(num: number) {
		if (num === 0) throw new Error('Error: cannot romanize zero');
		if (num < 0) throw new Error('Error: cannont romanize negative number');
        if (num > 3999) throw new Error('Error: cannot romanize numbers above 3999');

		return toRoman(num);
	}

	unromanize(roman: string) {
		return toArabic(roman);
	}
}
