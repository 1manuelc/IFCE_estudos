export class Point {
	alias;
	x;
	y;
	ndcx;
	ndcy;

	constructor(alias, x, y, sru) {
		this.alias = alias.substring(0, 2);
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
}
