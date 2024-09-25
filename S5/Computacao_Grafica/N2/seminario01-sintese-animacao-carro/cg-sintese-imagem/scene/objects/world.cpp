#include "tree.cpp"
#include "ground.cpp"
#include "lamp_post.cpp"
#include "road.cpp"

void renderWorld(float);
void updateWorld(float);

float worldPosition = -20;		// Posição inicial do mundo
double worldSpeed = 0.3;		// Velocidade de translação
double worldEnd = 20.0;         // Posição final da pista (onde o loop recomeça)

void renderWorld(float highwayLength) {
	glPushMatrix();
	glTranslatef(worldPosition, 0, 0);

	renderGround(highwayLength + 100);
	renderRoad(-highwayLength, highwayLength);

	// Povoa mundo com postes e árvores
	for(int i = -highwayLength; i < highwayLength + 1; i += 5) {
		if(i % 2 == 0) {
			renderLampPost(i, 2, 0);
		} else {
			renderTree(i, -5, 0);
		}
	}

	glPopMatrix();
}

void updateWorld(int value) {
	worldPosition += worldSpeed;

	if (worldPosition >= worldEnd) {
		worldPosition = 0.0f;
	}

	glutTimerFunc(16, updateWorld, 0); // ~16ms (~60 FPS)

	glutPostRedisplay();
}
