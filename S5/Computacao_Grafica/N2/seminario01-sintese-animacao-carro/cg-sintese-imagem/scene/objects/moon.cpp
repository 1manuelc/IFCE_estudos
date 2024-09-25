void renderMoon() {
	glPushMatrix();

	glColor3f(0.75, 0.75, 0.75);  // branco
	glTranslatef(0, -96, 2.0);  // Posição no céu ao fundo
	glutSolidSphere(5, 20, 20);

	glPopMatrix();
}
