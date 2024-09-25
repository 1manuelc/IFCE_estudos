#include "objects/car.cpp"
#include "objects/sky.cpp"
#include "objects/sun.cpp"
#include "objects/moon.cpp"
#include "objects/world.cpp"

#define HIGHWAY_LENGTH 100

void render();

void render() {
	if (actualDaytime < 3)
		renderSun();
	else renderMoon();
	renderSky(64, 4);

	renderWorld(HIGHWAY_LENGTH);
	renderCar();
}
