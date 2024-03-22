export class Point {
	alias;
	x;
	y;
	ndcx;
	ndcy;

	constructor(alias, x, y, sru) {
		this.alias = alias;
		this.x = x;
		this.y = y;

		this.ndcx = parseFloat(
			((this.x - sru.x.min) / (sru.x.max - sru.x.min)).toFixed(2),
		);
		this.ndcy = parseFloat(
			((this.y - sru.y.min) / (sru.y.max - sru.y.min)).toFixed(2),
		);
	}

	getCoordinates() {
		return `${this.alias} = (${this.x}, ${this.y})`;
	}

	getNormalizedCoordinates() {
		return `${this.alias} = (${this.ndcx}, ${this.ndcy})`;
	}

	getAllCoordinates() {
		return `${this.alias} = (x: ${this.x}, y: ${this.y})
     (ndcx: ${this.ndcx}, ndcy: ${this.ndcy})`;
	}

	convertToCartesian(sru) {
		const newX = sru.centralPoint.x - this.x;
		const newY = sru.centralPoint.y - this.y;
		return new Point(`${this.alias}'m`, newX, newY, sru);
	}

	move(xFactor, yFactor) {
		this.x += xFactor;
		this.y += yFactor;
		return this;
	}

	flip(factor) {
		if (factor.match('h')) this.x *= -1;
		else if (factor.match('v')) this.y *= -1;
		else if (factor.match('/*')) {
			this.x *= -1;
			this.y *= -1;
		}

		this.alias += '\x1b[30mf\x1b[0m';
	}
}
