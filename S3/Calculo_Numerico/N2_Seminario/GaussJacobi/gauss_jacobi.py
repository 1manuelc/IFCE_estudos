import matplotlib.pyplot as plt
import numpy as np


def imprimirResultado(vetorArbitrario, matrizSolucao, numIteracoes):
	print('Método de Gauss-Jacobi:')
	print('Aproximação inicial:', vetorArbitrario)
	print('\nSolução: \n', '\tx1 =', matrizSolucao[0], '\n'
	      '\tx2 =', matrizSolucao[1], '\n'
	      '\tx3 =', matrizSolucao[2], '\n'
	      '\tx4 =', matrizSolucao[3])
	print('k =', numIteracoes)

def plotarResultados(coordenadas, vetorResultado):
	valoresX1 = []
	valoresX2 = []
	valoresX3 = []
	valoresX4 = []
	iteracoes = []

	valoresX1.append(coordenadas[0])
	valoresX2.append(coordenadas[1])
	valoresX3.append(coordenadas[2])
	valoresX4.append(coordenadas[3])
	iteracoes.append(coordenadas[4])

	fig, ax = plt.subplots()
	ax.grid()
	ax.set(xlabel='Iterações',
	       ylabel='Raízes',
	       title='Gráfico de Convergência - Método de Gauss Jacobi')

	for k in range(len(iteracoes)):
		plt.plot(valoresX1[k])
		plt.plot(valoresX2[k])
		plt.plot(valoresX3[k])
		plt.plot(valoresX4[k])

	legend_labels = [
	 'x1 = ~ {:.4f}'.format(vetorResultado[0]),
	 'x2 = ~ {:.4f}'.format(vetorResultado[1]),
	 'x3 = ~ {:.4f}'.format(vetorResultado[2]),
	 'x4 = ~ {:.4f}'.format(vetorResultado[3])
	]
	if len(legend_labels) == 4:
		plt.legend(legend_labels, loc='best')

	plt.show()

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
			else:
				novaMatrizA[i].append(-matrizA[i][j])

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

def gaussJacobi(a, b, vetorArbitrario, maxIteracoes, epsilon):
	vetorSolucao = []
	vetorSolucao.append(vetorArbitrario)
	coordenadas = [[], [], [], [], []]
	k = 0

	while (k < maxIteracoes):
		if (k == 0): xAtual = produtoMatricial(a, vetorSolucao[0])
		else: xAtual = produtoMatricial(a, vetorSolucao[k])

		for j in range(len(b)):
			xAtual[j] = xAtual[j] + b[j]

		vetorSolucao.append(xAtual)

		coordenadas[4].append(k)
		for c in range(0, 4):
			coordenadas[c].append(vetorSolucao[k][c])

		if (normaVetorial(vetorSolucao[k], vetorSolucao[k - 1]) < epsilon):
			return (vetorSolucao[k], k, coordenadas)

		k += 1

	if (k == maxIteracoes):
		print('Limite de iterações excedido, retornando os resultados obtidos...')
		return (vetorSolucao[k], k, coordenadas)


a = np.array([[10.0, 1.0, -0.3, -0.4], [0.2, 4.7, -0.1, -0.6],
              [-0.4, -0.2, 9.0, 0.3], [1.0, -1.8, 0.4, 8.7]])
b = np.array([[0.5], [-6.0], [7.0], [9.0]])

(matrizA, matrizB) = isolarMatrizes(a, b)
vetorArbitrario = [1, 1, 1, 1]

vetorSolucao, numIteracoes, coordenadas = gaussJacobi(matrizA, matrizB,
                                                      vetorArbitrario, 50,
                                                      0.001)

imprimirResultado(vetorArbitrario, vetorSolucao, numIteracoes)
plotarResultados(coordenadas, vetorSolucao)