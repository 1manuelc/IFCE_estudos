export class SRU {
	x = { min: 0, max: 0 };
	y = { min: 0, max: 0 };
	sruMatrix = [];

	constructor(maxX, maxY) {
		this.x.max = maxX;
		this.y.max = maxY;
		this.sruMatrix = this.getEmptyMatrix(this.x.max, this.y.max);
	}

	/**
	 *
	 * @param {Number} lines
	 * @param {Number} cols
	 * @returns a square matrix representing the SRU
	 */
	getEmptyMatrix(lines, cols) {
		const matrix = [];
		for (let i = 0; i < lines; i++) matrix[i] = new Array(cols).fill('*');
		return matrix;
	}

	printMatrix() {
		console.log('');
		this.sruMatrix.forEach((l) => {
			console.log(`[${l.join('\t')}]`);
		});
		console.log('');
	}

	/**
	 *
	 * @param {Point} point
	 */
	attributePoint(point) {
		try {
			this.sruMatrix[point.x - 1][point.y - 1] = point.alias;
		} catch (error) {
			throw new Error('[Bad input] Point coordinates doesn\'t exist on defined SRU.');
		}
	}
}
