void renderLampPost(float x, float y, float z) {
	// Poste
	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);  // Cinza

	glTranslatef(x, y, z);
	glScalef(0.08, 0.08, 5);  // Forma do poste
	glutSolidCube(1);

	glPopMatrix();

	// Lâmpada
	glPushMatrix();

	glColor3f(1.0, 1.0, 0.0);  // Amarelo
	glTranslatef(x, y, z + 2.55);
	glutSolidSphere(0.1, 20, 20);  // Luz

	glPopMatrix();
}

