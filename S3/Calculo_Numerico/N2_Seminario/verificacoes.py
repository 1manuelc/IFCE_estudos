import numpy as np

a = np.array([[10, 1.0, -0.3, -0.4], [0.2, 4.7, -0.1, -0.6],
              [-0.4, -0.2, 9.0, 0.3], [1.0, -1.8, 0.4, 8.7]])


def criterioDasLinhas(matriz):
	diagonalPrincipal = []
	somatorios = []
	statusCriterio = True

	for i in range(0, 4):
		soma = 0
		for j in range(0, 4):
			if (i == j): diagonalPrincipal.append(matriz[i][j])
			else: soma += matriz[i][j]
		somatorios.append(soma)

	for i in range(0, 4):
		if (diagonalPrincipal[i] < somatorios[i]):
			statusCriterio = False
			break

	return statusCriterio

def criterioDeSassenfeld(matriz):
	vetorBeta = []
	statusCriterio = True
	
	for i in range(len(matriz)):
		divisor = 0
		betaAtual = 0
		
		for j in range(len(matriz)):
			if (i != j):
				betaAtual += abs(matriz[i][j])
				if (j < len(vetorBeta)): betaAtual *= vetorBeta[j]
			else: divisor = matriz[i][j]

		betaAtual /= divisor
		vetorBeta.append(betaAtual)

	maiorBeta = max(vetorBeta)
	if (maiorBeta >= 1): statusCriterio = False

	return (statusCriterio, maiorBeta)