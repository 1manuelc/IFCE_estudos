void renderRoad(float start, float end) {
	// Rua
	glColor3f(0.2, 0.2, 0.2);  // Cinza escuro para a rua
	glBegin(GL_QUADS);
	glVertex3f(start, -3.6, 0.01);
	glVertex3f(end, -3.6, 0.01);
	glVertex3f(end, 1.4, 0.01);
	glVertex3f(start, 1.4, 0.01);
	glEnd();

	// Faixas da rua
	glColor3f(1.0, 1.0, 1.0);  // Branco
	for (float i = start; i < end + 1; i += 1.5) {
		glBegin(GL_QUADS);
		glVertex3f(i, -1.2, 0.012);
		glVertex3f(i, -1.1, 0.012);
		glVertex3f(i + 0.8, -1.1, 0.012);
		glVertex3f(i + 0.8, -1.2, 0.012);
		glEnd();
	}
}
