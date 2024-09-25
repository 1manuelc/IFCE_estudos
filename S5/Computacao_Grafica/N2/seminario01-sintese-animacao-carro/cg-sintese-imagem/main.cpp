#include "./lib/polygl.h"
#include "scene/lightning.cpp"
#include "scene/camera.cpp"
#include "scene/render.cpp"
#include "utils/buffers.cpp"
#include "utils/log.cpp"

#define SPEED 0.5
#define ROTATION_SPEED_FACTOR 2

void display();

void keyboard(unsigned char, int, int);

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Síntese de Imagem - Tema 2 - Item 3");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(0, updateWorld, 0);
	glutMainLoop();

	return 0;
}

void display() {
	setupLightning(cycle[actualDaytime]);
	configureAndClearBuffers();
	render();
	glFlush();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		// increase rotationAngle + speed
		case 49: // 1
			rotateAngle += SPEED * ROTATION_SPEED_FACTOR;
			break;
		// decrease rotationAngle - speed
		case 51: // 3
			rotateAngle -= SPEED * ROTATION_SPEED_FACTOR;
			break;

		// Cycling daytime/light modes
		case 76: // L
		case 108: // l
			cycleDaytime();
			break;

		// Cycling car color
		case 67: // C
		case 99: // c
			cycleCarColors();
			break;

		// Backspace resets rotation transformation
		case 8:
			rotateAngle = 0;
			break;

		// Esc finishes program
		case 27:
			exit(0);
			break;

		default:
			break;
	}

	log();

	float aspect =
			glutGet(GLUT_WINDOW_WIDTH) / (float) glutGet(GLUT_WINDOW_HEIGHT);
	config3d(aspect);

	glutPostRedisplay();
}
