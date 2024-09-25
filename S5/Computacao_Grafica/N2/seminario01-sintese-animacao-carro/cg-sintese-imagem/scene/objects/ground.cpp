void renderGround(const float size) {
	const float step = size / 5;
	const float half = size / 2.0f;

	glColor3f(0.0, 0.3, 0.0);
	glShadeModel(GL_FLAT);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 5; ++i) {
		const float pos = i * step - half;

		// Linhas paralelas ao eixo X
		glVertex3f(pos, -half, 0.0f);
		glVertex3f(pos, half, 0.0f);

		// Linhas paralelas ao eixo Y
		glVertex3f(-half, pos, 0.0f);
		glVertex3f(half, pos, 0.0f);
	}
	glEnd();
}
