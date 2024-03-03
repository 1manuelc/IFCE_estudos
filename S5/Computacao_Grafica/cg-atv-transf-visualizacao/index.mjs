import { questionInt } from 'readline-sync';
import { SRU } from './modules/SRU.mjs';
import { SharedVertex } from './modules/SharedVertex/SharedVertex.mjs';
import { Circle } from './modules/SharedVertex/Circle.mjs';

(function main() {
	console.log('--- SRU DEFINITION ---');
	const matrixLines = questionInt('Type your matrix width: ');
	const matrixColumns = questionInt('Type your matrix height: ');

	const sru = new SRU(matrixLines, matrixColumns);
	let sharedVertex = new SharedVertex();
	const circle = new Circle();

	console.log('\n--- CIRCLE DEFINITION ---');
	const radius = questionInt('Type the radius of the circle: ');
	const facesNumber = questionInt('Type the number of faces/segment: ');

	sharedVertex = circle.mapCircle(radius, facesNumber, sharedVertex, sru);
	circle.drawCircle(sru, sharedVertex);
	sru.printMatrix();
})();
