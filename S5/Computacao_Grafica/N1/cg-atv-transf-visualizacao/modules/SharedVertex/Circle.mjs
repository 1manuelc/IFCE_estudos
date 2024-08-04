import { Point } from '../Point.mjs';
import { Vertex } from './Vertex.mjs';
import { Face } from './Face.mjs';

export class Circle {
	trace(radius, segmentsNumber, sharedVertex, sru) {
		const centralVertex = new Vertex(
			new Point('\x1b[31mCc\x1b[0m', 0, 0, sru)
		);

		sharedVertex.attributeVertexToList(centralVertex);

		let pointsCounter = 1;
		for (let i = 0; i < segmentsNumber; i++) {
			const face = new Face(`f${i + 1}`);
			face.attributeVertexIndexToFace(
				sharedVertex.vertexList.indexOf(centralVertex)
			);

			for (let j = 0; j < 2; j++) {
				let angleInRads;

				if (j == 0) angleInRads = 2 * Math.PI * (i / segmentsNumber);
				else angleInRads = 2 * Math.PI * ((i + 1) / segmentsNumber);

				const x = Math.round(
					centralVertex.point.x + radius * Math.cos(angleInRads)
				);
				const y = Math.round(
					centralVertex.point.y + radius * Math.sin(angleInRads)
				);

				const vertex = new Vertex(new Point(`v${pointsCounter}`, x, y, sru));
				sharedVertex.attributeVertexToList(vertex);
				pointsCounter++;

				face.attributeVertexIndexToFace(
					sharedVertex.vertexList.indexOf(vertex)
				);
			}

			sharedVertex.attributeFaceToList(face);
		}

		return sharedVertex;
	}

	draw(sru, sharedVertex) {
		sharedVertex.faceList.forEach((face) => {
			face.vertexIndexes.forEach((index) => {
				sru.attributePoint(sharedVertex.vertexList[index].point);
			});
		});
	}
}
