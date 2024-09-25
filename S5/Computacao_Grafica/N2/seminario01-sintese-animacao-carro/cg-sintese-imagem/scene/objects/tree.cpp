// Função para desenhar uma árvore simples
void renderTree(float x, float y, float z) {
	// Tronco da árvore
	glPushMatrix();

	glColor3f(0.55, 0.27, 0.07);  // Marrom
	glTranslatef(x, y, z);
	glScalef(0.2, 0.2, 2);  // Forma do tronco
	glutSolidCube(1);

	glPopMatrix();

	// Copa da árvore
	glPushMatrix();

	glColor3f(0.0, 0.8, 0.0);  // Verde
	glTranslatef(x, y, z + 1.5);
	glScalef(2, 2, 2);
	glutSolidSphere(0.3, 20, 20);  // Copa da árvore

	glPopMatrix();
}