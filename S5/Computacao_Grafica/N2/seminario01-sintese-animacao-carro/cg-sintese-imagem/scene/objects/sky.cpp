#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include "cloud.cpp"

struct Cloud {
	float x, y, z, scale;
};

// Vetor para armazenar as nuvens geradas
std::vector<Cloud> clouds;

// Povoa o céu com nuvens apenas uma vez
void renderSky(int numClouds, float z) {
	if (clouds.empty()) {
		srand(static_cast<unsigned int>(time(0))); // Inicializa o gerador de números aleatórios

		for (int i = 0; i < numClouds; ++i) {
			// Gera posição aleatória para a nuvem
			float angle = static_cast<float>(rand()) / RAND_MAX * 2 * M_PI; // Ângulo aleatório
			float radius = 25.0f + static_cast<float>(rand()) / RAND_MAX * 50.0f;
			float x = cos(angle) * radius;
			float y = sin(angle) * radius;

			// Gera um tamanho aleatório para a nuvem
			float scale = 0.4f + float(rand()) / RAND_MAX * 5.6f;

			// Armazena a nuvem gerada
			clouds.push_back({x, y, z + scale, scale});
		}
	}

	// Renderiza as nuvens armazenadas
	for (const auto& cloud : clouds) {
		renderCloud(cloud.x, cloud.y, cloud.z, cloud.scale);
	}
}