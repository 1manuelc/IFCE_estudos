import { questionInt } from 'readline-sync';
import { Circle } from './Circle.mjs';

export class SharedVertex {
	faceList;
	vertexList;
	polygon;
	sru;

	constructor(sru, polygonName) {
		this.faceList = [];
		this.vertexList = [];
		this.sru = sru;

		this.init(polygonName);
	}

	attributeFaceToList(f) {
		this.faceList.push(f);
	}

	attributeVertexToList(v) {
		this.vertexList.push(v);
	}

	translateObject(x, y) {
		this.sru.clean();
		this.vertexList.forEach((vertex) => vertex.point.translate(x, y));
		this.polygon.draw(this.sru, this);
		this.sru.attributePoint(this.sru.centralPoint);
		console.log(`Translate (${x}, ${y}) operation done`);
	}

	flipObject(factor) {
		this.sru.clean();
		this.vertexList.forEach((vertex) => vertex.point.flip(factor));
		this.polygon.draw(this.sru, this);
		this.sru.attributePoint(this.sru.centralPoint);
		console.log(`Flip ${factor} operation done`);
	}

	init(polygonName) {
		if (polygonName.match('circle') || polygonName.match('c')) {
			console.log('\n--- CIRCLE DEFINITION ---');
			const radius = questionInt('Type the radius of the circle: ');
			const facesNumber = questionInt('Type the number of faces/segments: ');

			this.polygon = new Circle();
			this.polygon.trace(radius, facesNumber, this, this.sru);
			this.polygon.draw(this.sru, this);
			this.sru.attributePoint(this.sru.centralPoint);
		}
	}

	showMatrix() {
		this.sru.printMatrix();
	}
}
