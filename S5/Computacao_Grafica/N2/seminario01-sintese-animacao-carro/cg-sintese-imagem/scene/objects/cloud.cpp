void renderCloud(float x, float y, float z, float scale) {
	glPushMatrix();
	glColor4f(1.0, 1.0, 1.0, 1);

	glTranslatef(x, y, z);
	glScalef(scale, scale, scale);

	glutSolidSphere(1, 20, 20);
	glTranslatef(0.8, 0.0, -0.2);

	glutSolidSphere(0.8, 20, 20);
	glTranslatef(-1.8, 0.0, -0.1);

	glutSolidSphere(0.7, 20, 20);
	glPopMatrix();
}