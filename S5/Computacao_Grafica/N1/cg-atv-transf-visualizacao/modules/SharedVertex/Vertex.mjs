export class Vertex {
	alias;
	point;

	constructor(point) {
		this.point = point;
		this.alias = point.alias;
	}
}
