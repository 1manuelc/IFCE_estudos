export class Face {
	alias;
	vertexIndexes;

	constructor(alias) {
		this.alias = alias;
		this.vertexIndexes = [];
	}

	attributeVertexIndexToFace(vertexIndex) {
		this.vertexIndexes.push(vertexIndex);
	}
}
