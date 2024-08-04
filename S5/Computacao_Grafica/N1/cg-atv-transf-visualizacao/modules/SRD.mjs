class SRD {
	alias;
	width;
	height;

	constructor(alias, w, h) {
		this.alias = alias;
		this.width = w;
		this.height = h;
	}

	/**
	 *
	 * @param {Point} point
	 */
	getPointInSRD(point) {
		return new SRD_Point(
			`${point.alias.substring(0, 2) + '_SRD' + this.alias.toLowerCase()[0]}`,
			point,
			this,
		);
	}
}

class SRD_Point {
	alias;
	x;
	y;

	constructor(alias, point, srd) {
		this.alias = alias;
		this.x = point.ndcx * srd.width;
		this.y = point.ndcy * srd.height;
	}

	getCoordinates() {
		return `${this.alias} = (${this.x.toFixed(2)}, ${this.y.toFixed(2)})`;
	}
}

export { SRD, SRD_Point };
