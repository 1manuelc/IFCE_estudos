export class SharedVertex {
	faceList;
	vertexList;

	constructor() {
		this.faceList = [];
		this.vertexList = [];
	}

	attributeFaceToList(f) {
		this.faceList.push(f);
	}

	attributeVertexToList(v) {
		this.vertexList.push(v);
	}
}
