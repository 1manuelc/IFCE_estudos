void renderSun() {
	glPushMatrix();

	glColor3f(1.0, 1.0, 0.0);  // Amarelo
	glTranslatef(0, -90, 4.0);  // Posição no céu ao fundo
	glutSolidSphere(5, 20, 20);

	glPopMatrix();
}