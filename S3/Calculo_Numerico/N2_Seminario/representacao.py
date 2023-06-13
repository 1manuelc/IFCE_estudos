import numpy as np


a = [[10.0, 1.0, -0.3, -0.4], [0.2, 4.7, -0.1, -0.6], [-0.4, -0.2, 9.0, 0.3],
     [1.0, -1.8, 0.4, 8.7]]

b = [[0.5], [-6.0], [7.0], [9.0]]


def normaVetorial(v, x):
	n = len(v)
	numMax = 0
	denMax = 0

	for i in range(0, n):
		num = abs(v[i] - x[i])
		den = abs(v[i])
		if (num > numMax): numMax = num
		if (den > denMax): denMax = den

	return (numMax / denMax)

def isolarMatrizes(matrizA, matrizB):
	novaMatrizA = [[], [], [], []]
	novaMatrizB = [[], [], [], []]
	divisores = []

	for i in range(0, 4):
		for j in range(0, 4):
			if (i == j):
				novaMatrizA[i].append(0)
				divisores.append(matrizA[i][j])
			else: novaMatrizA[i].append(-matrizA[i][j])

	for i in range(0, 4):
		for j in range(0, 4):
			novaMatrizA[i][j] /= divisores[i]

	for i in range(0, 4):
		novaMatrizB[i].append(matrizB[i][0] / divisores[i])

	return (novaMatrizA, novaMatrizB)

def produtoMatricial(matrizA, matrizB):
	matrizX = []
	for i in range(len(matrizA)):
		xAtual = 0
		for j in range(len(matrizB)):
			xAtual += matrizA[i][j] * matrizB[j]

		matrizX.append(xAtual)

	matrizResultado = np.array([matrizX[0], matrizX[1], matrizX[2],
	                            matrizX[3]])

	return matrizResultado

def produtoMatricialSeidel(matrizA, matrizB):
	matrizX = []

	for i in range(len(matrizA)):
		xAtual = 0
		for j in range(len(matrizA)):
			if (j < len(matrizX)): xAtual += matrizA[i][j] * matrizX[j]
			else: xAtual += matrizA[i][j] * matrizB[j]
		matrizX.append(xAtual)

	matrizResultado = np.array([matrizX[0], matrizX[1], matrizX[2],
	                            matrizX[3]])

	return matrizResultado


matrizANova = []
matrizBNova = []

(matrizANova, matrizBNova) = isolarMatrizes(a, b)

print(matrizANova)
print(matrizBNova)
