import { question, questionInt } from 'readline-sync';
import { SRU } from './modules/SRU.mjs';
import { Point } from './modules/Point.mjs';
import { SRD } from './modules/SRD.mjs';

(function main() {
	console.log('--- SRU DEFINITION ---');
	const matrixLines = questionInt('Type your matrix width: ');
	const matrixColumns = questionInt('Type your matrix height: ');
	const sru = new SRU(matrixLines, matrixColumns);

	console.log('\n--- POINTS DEFINITION ---');
	const pointsAmount = questionInt('How many points you want to define?: ');
	const pointsList = [];
	for (let i = 0; i < pointsAmount; i++) {
		console.log('');
		const pointX = questionInt(`Type your x coordinate for point ${i + 1}: `);
		const pointY = questionInt(`Type your y coordinate for point ${i + 1}: `);
		pointsList.push(new Point(`P${i + 1}`, pointX, pointY, sru));
	}

	pointsList.forEach((p) => sru.attributePoint(p));

	console.log('\n--- MATRIX EXHIBITION ---');
	sru.printMatrix();

	console.log('--- SRD DEFINITION ---');
	const deviceWidth = questionInt('Type your device width: ');
	const deviceHeight = questionInt('Type your device height: ');
	const deviceName = question('Type your device name: ');

	console.log('\n--- POINTS EXHIBITION ---');
	const srd = new SRD(deviceName, deviceWidth, deviceHeight);
	pointsList.forEach((p) => console.log(p.getAllCoordinates() + '\n'));
	pointsList.forEach((p) => console.log(srd.getPointInSRD(p).getCoordinates()));
})();
