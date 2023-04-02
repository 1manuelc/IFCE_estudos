import math as m
from math import e
from matplotlib import pyplot

# tupla padrao de retorno (x, k, y, r)
    # x: houve erro no ciclo de iteracoes?
    # k: quantidade de iteracoes feitas
    # y: raiz x calculada
    # r: vetor de coordenadas para plotagem

def f(x):
    return m.sin(x) - (e ** x)

def fDeriv(x):
    return m.cos(x) - (e ** x)

# funcao de iteracao
def phi(x):
    return x - (f(x) / fDeriv(x))

def newton(phi, epsilon, maxIteracoes):
    x = -3
    k = 0

    coord = []
    coord.append((k, x))

    if(abs(f(x)) <= epsilon):
        return(False, k, x, coord)

    while k <= maxIteracoes:
        x = phi(x)
        k += 1

        coord.append((k, x))

        if(abs(f(x)) <= epsilon):
            return(False, k, x, coord)
    
    print("Numero maximo de interacoes alcancado")
    return(True, k, x, coord)

def imprimir_resultado(statusErro, raiz, nIteracoes):
    if(statusErro):
        print("Erro no método de Newton após %s iterações", nIteracoes)
    
    if(raiz != None):
        print("Método de Newton\nRaiz %s encontrada com %s iterações" % (raiz, nIteracoes))

def plotar(coordenadas):
    iterac = []
    valorRaiz = []

    for i in coordenadas:
        iterac.append(i[0]) #posição 0, k
        valorRaiz.append(i[1]) #posição 1, x
    
    fig, ax = pyplot.subplots()

    ax.set(xlabel='Iterações', ylabel='Raiz',
    title='Gráfico de Convergência - Método de Newton')
    ax.grid()
    pyplot.plot(iterac,valorRaiz)
    pyplot.show()

(haErro, iteracoes, raiz, coordenadas) = newton(phi, 0.0001, 50)

imprimir_resultado(haErro, raiz, iteracoes)
plotar(coordenadas)