#include "../lib/polygl.h"

struct Daytime {
	GLfloat light_color[4];
	GLfloat clear_color[4];
};

void setupLightning(const Daytime&);
void cycleDaytime();

int actualDaytime = 0;

Daytime sunrise = { // 0
	0.8f, 0.5f, 0.3f, 1.0f,
	0.8f, 0.5f, 0.3f, 1.0f
};

Daytime noon = { // 1
	0.8f, 0.8f, 0.8f, 0.8f,
	0.6f, 0.6f, 1.0f, 1.0f,
};

Daytime sunset = { // 2
	0.7f, 0.7f, 0.5f, 0.2f,
	0.6f, 0.4f, 0.2f, 1.0f,
};

Daytime night = { // 3
	0.5f, 0.5f, 0.6f, 0.6f,
	0.0f, 0.0f, 0.15f, 1.0f,
};

Daytime dawn = { // 4
	0.1f, 0.1f, 0.3f, 0.3f,
	0.0f, 0.0f, 0.008f, 1.0f
};

Daytime nolight = { // 5
	0.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 0.0f, 0.0f
};

Daytime studio = { // 6
	1.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 0.0f, 0.0f
};

Daytime cycle[] = {sunrise, noon, sunset, night, dawn, nolight, studio};

void setupLightning(const Daytime &dt) {
	glClearColor(dt.clear_color[0], dt.clear_color[1], dt.clear_color[2], dt.clear_color[3]);

	// Configuração da posição e cores da luz
	GLfloat light_position[] = {0, -20, 4.0, 1.0}; // Luz direcional
	GLfloat light_diffuse[] = {0.2, 0.2, 0.2, 0.2};
	GLfloat light_specular[] = {0.2, 0.2, 0.2, 0.2};
	GLfloat light_ambient[] = {dt.light_color[0], dt.light_color[1], dt.light_color[2], dt.light_color[3]}; // Pequeno componente ambiente

	// Ativar a iluminação e a luz 0
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

	// Habilitar o uso de materiais para reflexão especular
	glMaterialfv(GL_FRONT, GL_SPECULAR, light_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 50.0f); // Controle de brilho da reflexão especular

	// Ativar cores de material
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}

void cycleDaytime() {
	if (actualDaytime <= 5)
		actualDaytime++;
	else actualDaytime = 0;

	setupLightning(cycle[actualDaytime]);
}