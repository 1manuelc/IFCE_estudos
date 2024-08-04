import { Point } from './Point.mjs';

export class SRU {
	x = { min: 0, max: 0 };
	y = { min: 0, max: 0 };
	sruMatrix = [];
	centralPoint;

	constructor(maxX, maxY) {
		this.x.max = maxX;
		this.y.max = maxY;
		this.sruMatrix = this.getEmptyMatrix(this.x.max, this.y.max);
		this.centralPoint = new Point(
			'\x1b[32m' + '(0)' + '\x1b[0m',
			Math.ceil(maxX / 2),
			Math.ceil(maxY / 2),
			this,
		);
	}

	/**
	 *
	 * @param {Number} lines
	 * @param {Number} cols
	 * @returns a square matrix representing the SRU
	 */
	getEmptyMatrix(lines, cols) {
		const matrix = [];
		for (let i = 0; i < lines; i++)
			matrix[i] = new Array(cols).fill('\x1b[30m.\x1b[0m');
		return matrix;
	}

	printMatrix() {
		console.log('');
		this.sruMatrix.forEach((l) => {
			console.log(`${l.join('\t')}`);
		});
		console.log('');
	}

	/**
	 *
	 * @param {Point} point
	 */
	attributePoint(point) {
		let newPoint =
			point != this.centralPoint
				? this.convertCartesianToMatrix(point)
				: this.centralPoint;

		let pointX = newPoint.x - 1;
		let pointY = newPoint.y - 1;

		if (pointX < 0) pointX = 0;
		if (pointY < 0) pointY = 0;

		this.sruMatrix[pointY][pointX] = point.alias;
	}

	convertCartesianToMatrix(point) {
		const newX = point.x + this.centralPoint.x;
		const newY = this.centralPoint.y - point.y;
		return new Point('p1\'', newX, newY, this);
	}

	clean() {
		this.sruMatrix = this.getEmptyMatrix(this.x.max, this.y.max);
	}
}
