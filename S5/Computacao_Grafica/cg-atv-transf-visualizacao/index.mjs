import { questionInt } from 'readline-sync';
import { SRU } from './modules/SRU.mjs';
import { SharedVertex } from './modules/SharedVertex/SharedVertex.mjs';

(function main() {
	console.log('--- SRU DEFINITION ---');
	const matrixLines = questionInt('Type your matrix width: ');
	const matrixColumns = questionInt('Type your matrix height: ');
	const sru = new SRU(matrixLines, matrixColumns);

	let sharedVertex = new SharedVertex(sru, 'circle');
	sharedVertex.showMatrix();

	// Translação do círculo (x, y)
	sharedVertex.moveObject(1, -2);
	sharedVertex.showMatrix();

	// Espelhamento do círculo ('h', 'v' ou '*')
	sharedVertex.flipObject('h');
	sharedVertex.showMatrix();
})();
