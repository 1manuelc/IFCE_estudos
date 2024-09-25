#include "../../lib/polygl.h"

struct CarColor {
	float bodywork[2][3];
	float windows[4];
	float front_lights[3];
	float rear_lights[3];
};

void changeRenderColor(float []);

void renderCarLights();

void renderCarBase();

void renderCarRearViews();

void renderCarWindows();

void renderCarColumns();

void renderCar();

void renderCarWheel(float, float, float);

void renderCarWheels();

CarColor red = {
	{{0.5, 0.0, 0.0}, {0.7, 0.0, 0.0}},
	{0.7, 0.7, 0.8, 0.5},
	{1.0, 1.0, 0.0},
	{1.0, 0.0, 0.0}
};
CarColor blue = {
	{{0.0, 0.0, 0.7}, {0.0, 0.0, 0.9}},
	{0.7, 0.7, 0.8, 0.5},
	{1.0, 1.0, 0.0},
	{1.0, 0.0, 0.0}
};
CarColor black = {
	{{0.1, 0.1, 0.1}, {0.15, 0.15, 0.15}},
	{0.7, 0.7, 0.8, 0.5},
	{1.0, 1.0, 0.0},
	{1.0, 0.0, 0.0}
};
CarColor silver = {
	{{0.3, 0.3, 0.3}, {0.5, 0.5, 0.5}},
	{0.7, 0.7, 0.8, 0.5},
	{1.0, 1.0, 0.0},
	{1.0, 0.0, 0.0}
};

CarColor car_color_cycle[] = {red, black, blue, silver};
int actual_car_color = 0;
CarColor currentCarColor = car_color_cycle[0];

void cycleCarColors() {
	if (actual_car_color == 3) actual_car_color = 0;
	else actual_car_color++;

	currentCarColor = car_color_cycle[actual_car_color];
}

void changeRenderColor(float colorArray[]) {
	glColor3f(colorArray[0], colorArray[1], colorArray[2]);
}

void renderCarLights() {
	//faróis
	glColor3f(currentCarColor.front_lights[0], currentCarColor.front_lights[1], currentCarColor.front_lights[2]);
	//farol dianteiro, direito
	glBegin(GL_POLYGON);
	glVertex3f(-6.4, 3.9, 2);
	glVertex3f(-6.4, 3.9, 3);
	glVertex3f(-6.9, 2.9, 3);
	glVertex3f(-6.9, 2.9, 2);
	glVertex3f(-6.4, 3.9, 2);
	glEnd();

	//farol dianteiro esquerdo
	glBegin(GL_POLYGON);
	glVertex3f(-6.9, -0.3, 2);
	glVertex3f(-6.9, -0.3, 3);
	glVertex3f(-6.4, -1.2, 3);
	glVertex3f(-6.3, -1.2, 2);
	glVertex3f(-6.9, -0.3, 2);
	glEnd();

	glColor3f(currentCarColor.rear_lights[0], currentCarColor.rear_lights[1], currentCarColor.rear_lights[2]);

	//farol traseiro direito
	glBegin(GL_POLYGON);
	glVertex3f(8.2, 3.3, 2);
	glVertex3f(8.2, 3.3, 3);
	glVertex3f(8, 4, 3);
	glVertex3f(8, 4, 2);
	glVertex3f(8.2, 3.3, 2);
	glEnd();

	//farol traseiro, esquerdo
	glBegin(GL_POLYGON);
	glVertex3f(8, -1.4, 3);
	glVertex3f(8.2, -0.8, 3);
	glVertex3f(8.2, -.8, 2);
	glVertex3f(8, -1.4, 2);
	glVertex3f(8, -1.4, 3);
	glEnd();
}

void renderCarBase() {
	// fundo
	glColor3f(0.0, 0.0, 0.0); // preto
	glBegin(GL_POLYGON);
	glVertex3f(8.2, -.8, 2);
	glVertex3f(8.2, 3.3, 2);
	glVertex3f(8, 4, 2);
	glVertex3f(-6.4, 3.9, 2);
	glVertex3f(-6.9, 2.9, 2);
	glVertex3f(-6.9, -0.3, 2);
	glVertex3f(-6.3, -1.2, 2);
	glVertex3f(8, -1.4, 2);
	glVertex3f(8.2, -.8, 2);
	glEnd();

	changeRenderColor(currentCarColor.bodywork[0]);
	//para-choque traseiro
	glBegin(GL_POLYGON);
	glVertex3f(8.2, -0.8, 2);
	glVertex3f(8.2, -0.8, 3);
	changeRenderColor(currentCarColor.bodywork[1]);
	glVertex3f(8.2, 3.3, 3);
	glVertex3f(8.2, 3.3, 2);
	glVertex3f(8.2, -0.8, 2);
	glEnd();


	//para-choque dianteiro
	changeRenderColor(currentCarColor.bodywork[0]);
	glBegin(GL_POLYGON);
	glVertex3f(-6.9, 2.9, 2);
	glVertex3f(-6.9, 2.9, 3);
	changeRenderColor(currentCarColor.bodywork[1]);
	glVertex3f(-6.9, -0.3, 3);
	glVertex3f(-6.9, -0.3, 2);
	glVertex3f(-6.9, 2.9, 2);
	glEnd();

	//paralelepipedo lateral direito
	changeRenderColor(currentCarColor.bodywork[0]);
	glBegin(GL_POLYGON);
	glVertex3f(8, 4, 2);
	glVertex3f(8, 4, 3);
	changeRenderColor(currentCarColor.bodywork[1]);
	glVertex3f(-6.4, 3.9, 3);
	glVertex3f(-6.4, 3.9, 2);
	glVertex3f(8, 4, 2);
	glEnd();

	//paralelepipedo lateral esquerdo
	changeRenderColor(currentCarColor.bodywork[0]);
	glBegin(GL_POLYGON);
	glVertex3f(8, -1.4, 2);
	glVertex3f(8, -1.4, 3);
	changeRenderColor(currentCarColor.bodywork[1]);
	glVertex3f(-6.4, -1.2, 3);
	glVertex3f(-6.4, -1.2, 2);
	glVertex3f(8, -1.4, 2);
	glEnd();

	//trapezio lateral, esquerdo
	changeRenderColor(currentCarColor.bodywork[0]);
	glBegin(GL_POLYGON);
	glVertex3f(8, 4, 3);
	glVertex3f(4.6, 3.7, 4);
	changeRenderColor(currentCarColor.bodywork[1]);
	glVertex3f(-2, 3.7, 4);
	glVertex3f(-6.4, 3.9, 3);
	glVertex3f(8, 4, 3);
	glEnd();

	//paralelepipedo lateral esquerdo
	changeRenderColor(currentCarColor.bodywork[1]);
	glBegin(GL_POLYGON);
	glVertex3f(-6.4, -1.2, 3);
	glVertex3f(-2, -1.1, 4);
	changeRenderColor(currentCarColor.bodywork[0]);
	glVertex3f(4.5, -1.1, 4);
	glVertex3f(8, -1.4, 3);
	glVertex3f(-6.4, -1.2, 3);
	glEnd();

	//conexões capô
	glBegin(GL_TRIANGLES);
	changeRenderColor(currentCarColor.bodywork[0]);
	glVertex3f(-6.4, 3.9, 3);
	glVertex3f(-2, 3.7, 4);
	changeRenderColor(currentCarColor.bodywork[1]);
	glVertex3f(-6.9, 2.9, 3);
	glVertex3f(-6.4, 3.9, 3);
	glEnd();

	glBegin(GL_TRIANGLES);
	changeRenderColor(currentCarColor.bodywork[1]);
	glVertex3f(-6.4, -1.2, 3);
	glVertex3f(-6.9, -0.3, 3);
	changeRenderColor(currentCarColor.bodywork[0]);
	glVertex3f(-2, -1.1, 4);
	glVertex3f(-6.4, -1.2, 3);
	glEnd();

	//conexões porta-malas
	changeRenderColor(currentCarColor.bodywork[1]);
	glBegin(GL_TRIANGLES);
	glVertex3f(8, 4, 3);
	glVertex3f(8.2, 3.3, 3);
	changeRenderColor(currentCarColor.bodywork[0]);
	glVertex3f(4.6, 3.7, 4);
	glVertex3f(8, 4, 3);
	glEnd();

	glBegin(GL_TRIANGLES);
	changeRenderColor(currentCarColor.bodywork[1]);
	glVertex3f(8, -1.4, 3);
	glVertex3f(8.2, -0.8, 3);
	changeRenderColor(currentCarColor.bodywork[0]);
	glVertex3f(4.5, -1.1, 4);
	glVertex3f(8, -1.4, 3);
	glEnd();

	//tampa capô
	changeRenderColor(currentCarColor.bodywork[0]);
	glBegin(GL_POLYGON);
	glVertex3f(-6.9, 2.9, 3);
	glVertex3f(-6.9, -0.3, 3);
	changeRenderColor(currentCarColor.bodywork[1]);
	glVertex3f(-2, -1.1, 4);
	glVertex3f(-2, 3.7, 4);
	glVertex3f(-6.9, 2.9, 3);
	glEnd();

	//tampa porta-malas
	changeRenderColor(currentCarColor.bodywork[0]);
	glBegin(GL_POLYGON);
	glVertex3f(8.2, -0.8, 3);
	glVertex3f(8.2, 3.3, 3);
	changeRenderColor(currentCarColor.bodywork[1]);
	glVertex3f(4.6, 3.7, 4);
	glVertex3f(4.5, -1.1, 4);
	glVertex3f(8.2, -0.8, 3);
	glEnd();
}

void renderCarRearViews() {
	//retrovisor esquerdo
	changeRenderColor(currentCarColor.bodywork[0]);
	glBegin(GL_POLYGON);
	glVertex3f(-2, 3.7, 4);
	glVertex3f(-1.7, 4.5, 4);
	changeRenderColor(currentCarColor.bodywork[1]);
	glVertex3f(-1.4, 4.5, 4);
	glVertex3f(-1.6, 3.7, 4);
	glVertex3f(-2, 3.7, 4);
	glEnd();

	changeRenderColor(currentCarColor.windows);
	glBegin(GL_POLYGON);
	glVertex3f(-2, 3.7, 4);
	glVertex3f(-2, 3.7, 4.3);
	changeRenderColor(currentCarColor.windows);
	glVertex3f(-1.4, 4.5, 4.3);
	glVertex3f(-1.4, 4.5, 4);
	glVertex3f(-2, 3.7, 4);
	glEnd();

	changeRenderColor(currentCarColor.bodywork[1]);
	glBegin(GL_POLYGON);
	glVertex3f(-2, 3.7, 4.3);
	glVertex3f(-1.7, 4.5, 4.3);
	changeRenderColor(currentCarColor.bodywork[0]);
	glVertex3f(-1.4, 4.5, 4.3);
	glVertex3f(-1.6, 3.7, 4.3);
	glVertex3f(-2, 3.7, 4.3);
	glEnd();

	//retrovisor direito
	changeRenderColor(currentCarColor.bodywork[1]);
	glBegin(GL_POLYGON);
	glVertex3f(-2, -1.1, 4);
	glVertex3f(-1.7, -1.9, 4);
	changeRenderColor(currentCarColor.bodywork[0]);
	glVertex3f(-1.4, -1.9, 4);
	glVertex3f(-1.6, -1.1, 4);
	glVertex3f(-2, -1.1, 4);
	glEnd();

	changeRenderColor(currentCarColor.windows);
	glBegin(GL_POLYGON);
	glVertex3f(-2, -1.1, 4);
	glVertex3f(-2, -1.1, 4.3);
	changeRenderColor(currentCarColor.windows);
	glVertex3f(-1.4, -1.9, 4.3);
	glVertex3f(-1.4, -1.9, 4);
	glVertex3f(-2, -1.1, 4);
	glEnd();

	changeRenderColor(currentCarColor.bodywork[1]);
	glBegin(GL_POLYGON);
	glVertex3f(-2, -1.1, 4.3);
	glVertex3f(-1.7, -1.9, 4.3);
	changeRenderColor(currentCarColor.bodywork[0]);
	glVertex3f(-1.4, -1.9, 4.3);
	glVertex3f(-1.6, -1.1, 4.3);
	glVertex3f(-2, -1.1, 4.3);
	glEnd();
}

void renderCarWindows() {
	glColor4f(currentCarColor.windows[0], currentCarColor.windows[1], currentCarColor.windows[2],
	          currentCarColor.windows[3]);
	//parabrisa
	glBegin(GL_POLYGON);
	glVertex3f(-2.25, 3.5, 4);
	glVertex3f(-0.30, 3.1, 6);
	glVertex3f(-0.3, -0.5, 6);
	glVertex3f(-2.3, -1, 4);
	glVertex3f(-2.25, 3.5, 4);
	glEnd();

	//janelas esquerda
	glBegin(GL_POLYGON);
	glVertex3f(-0.1, 3.4, 6);
	glVertex3f(-2, 3.7, 4);
	glVertex3f(1.5, 3.7, 4);
	glVertex3f(1.5, 3.4, 6);
	glVertex3f(-0.1, 3.4, 6);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(1.8, 3.4, 6);
	glVertex3f(1.9, 3.7, 4);
	glVertex3f(4.6, 3.7, 4);
	glVertex3f(3.7, 3.4, 6);
	glVertex3f(1.8, 3.4, 6);
	glEnd();

	//janelas direita
	glBegin(GL_POLYGON);
	glVertex3f(-0.1, -0.8, 6);
	glVertex3f(-2, -1.1, 4);
	glVertex3f(1.5, -1.1, 4);
	glVertex3f(1.5, -0.8, 6);
	glVertex3f(-0.1, -0.8, 6);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(1.8, -0.8, 6);
	glVertex3f(1.9, -1.1, 4);
	glVertex3f(4.6, -1.1, 4);
	glVertex3f(3.7, -0.8, 6);
	glVertex3f(1.8, -0.8, 6);
	glEnd();

	// //parabrisa traseiro
	glBegin(GL_POLYGON);
	glVertex3f(4.6, 3.7, 4);
	glVertex3f(3.9, 3.1, 6);
	glVertex3f(3.9, -0.5, 6);
	glVertex3f(4.6, -1.1, 4);
	glVertex3f(4.6, 3.7, 4);
	glEnd();
}

void renderCarColumns() {
	//coluna parabrisa
	changeRenderColor(currentCarColor.bodywork[0]);
	glBegin(GL_POLYGON);
	glVertex3f(-2.25, 3.5, 4);
	glVertex3f(-2, 3.7, 4);
	changeRenderColor(currentCarColor.bodywork[1]);
	glVertex3f(-0.1, 3.4, 6);
	glVertex3f(-0.3, 3.1, 6);
	glVertex3f(-2.25, 3.5, 4);
	glEnd();

	glBegin(GL_POLYGON);
	changeRenderColor(currentCarColor.bodywork[0]);
	glVertex3f(-2.25, -1, 4);
	glVertex3f(-2, -1.1, 4);
	changeRenderColor(currentCarColor.bodywork[1]);
	glVertex3f(-0.1, -0.75, 6);
	glVertex3f(-0.3, -0.5, 6);
	glVertex3f(-2.25, -1, 4);
	glEnd();

	//coluna janela esquerda
	changeRenderColor(currentCarColor.bodywork[0]);
	glBegin(GL_POLYGON);
	glVertex3f(1.9, 3.7, 4);
	glVertex3f(1.5, 3.7, 4);
	changeRenderColor(currentCarColor.bodywork[1]);
	glVertex3f(1.5, 3.4, 6);
	glVertex3f(1.9, 3.4, 6);
	glVertex3f(1.9, 3.7, 4);
	glEnd();

	//coluna janela direito
	changeRenderColor(currentCarColor.bodywork[0]);
	glBegin(GL_POLYGON);
	glVertex3f(1.9, -1.1, 4);
	glVertex3f(1.5, -1.1, 4);
	changeRenderColor(currentCarColor.bodywork[1]);
	glVertex3f(1.5, -0.8, 6);
	glVertex3f(1.9, -0.8, 6);
	glVertex3f(1.9, -1.1, 4);
	glEnd();

	//coluna parabrisa traseiro
	changeRenderColor(currentCarColor.bodywork[0]);
	glBegin(GL_POLYGON);
	glVertex3f(4.5, -1.1, 4);
	glVertex3f(3.7, -0.8, 6);
	changeRenderColor(currentCarColor.bodywork[1]);
	glVertex3f(3.8, -0.5, 6);
	glVertex3f(4.5, -1.1, 4);
	glEnd();

	changeRenderColor(currentCarColor.bodywork[0]);
	glBegin(GL_POLYGON);
	glVertex3f(4.5, 3.7, 4);
	glVertex3f(3.7, 3.4, 6);
	changeRenderColor(currentCarColor.bodywork[1]);
	glVertex3f(3.9, 3.1, 6);
	glVertex3f(4.5, 3.7, 4);
	glEnd();

	//teto
	changeRenderColor(currentCarColor.bodywork[0]);
	glBegin(GL_POLYGON);
	glVertex3f(-0.1, -0.75, 6);
	glVertex3f(-0.3, -0.5, 6);
	changeRenderColor(currentCarColor.bodywork[1]);
	glVertex3f(-0.3, 3.1, 6);
	glVertex3f(-0.1, 3.4, 6);
	glVertex3f(3.7, 3.4, 6);
	glVertex3f(3.9, 3.1, 6);
	glVertex3f(3.8, -0.5, 6);
	glVertex3f(3.7, -0.8, 6);
	glVertex3f(-0.1, -0.75, 6);
	glEnd();
}

void renderCarWheel(float x, float y, float z) {
	// Desenha o pneu
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(90, 1, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glutSolidTorus(0.25, 1, 20, 20);
	glPopMatrix();

	// Desenha o aro (disco central da roda)
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(90, 1, 0, 0);
	glColor3f(0.7, 0.7, 0.7);
	gluDisk(gluNewQuadric(), 0, 0.9, 20, 1);
	glPopMatrix();
}

void renderCarWheels() {
	// roda dianteira esquerda
	renderCarWheel(-2.9, 3.99, 2);
	// roda traseira esquerda
	renderCarWheel(4.2, 3.99, 2);
	// roda dianteira direita
	renderCarWheel(-2.9, -1.4, 2);
	// roda traseira direita
	renderCarWheel(4.2, -1.4, 2);
}

void renderCar() {
	glPushMatrix();
	glScalef(0.2, 0.2, 0.2);
	glTranslatef(-1.57, -1.07, -0.95);

	glShadeModel(GL_SMOOTH);
	renderCarBase();
	renderCarColumns();
	renderCarRearViews();
	renderCarWindows();
	renderCarLights();
	renderCarWheels();

	glPopMatrix();
}
