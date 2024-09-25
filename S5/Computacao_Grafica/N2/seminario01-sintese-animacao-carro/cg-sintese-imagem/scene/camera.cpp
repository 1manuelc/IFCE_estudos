struct CameraPosition {
	float eye_x, eye_y, eye_z;
	float center_x, center_y, center_z;
	float up_x, up_y, up_z;
};

void reshape(int, int);
void config3d(float);
void logTransfomations();

GLfloat rotateAngle = 0.0;

CameraPosition cam = {
	0.0, 6.0, 1.6,
	0.0, 0.0, 0.7,
	0.0, 0.0, 1.0
};

void config3d(const float aspect) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, aspect, 1.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cam.eye_x, cam.eye_y, cam.eye_z,
			  cam.center_x, cam.center_y, cam.center_z,
			  cam.up_x, cam.up_y, cam.up_z);

	glRotatef(rotateAngle, 0, 0, 1);
}

void reshape(int width, int height) {
	float aspect = 0.0;

	if (height == 0) {
		height = 1;
	}

	aspect = (float) width / height;
	glViewport(0, 0, width, height);

	config3d(aspect);
}
