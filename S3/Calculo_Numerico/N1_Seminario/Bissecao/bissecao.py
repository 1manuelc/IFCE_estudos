import math as m
from math import e
from matplotlib import pyplot

# tupla padrao de retorno (x, k, y, r)
    # x: houve erro no ciclo de iteracoes?
    # k: quantidade de iteracoes feitas
    # y: raiz x calculada
    # r: vetor de coordenadas para plotagem

def f(x):
    return m.sin(x) - e ** x

def bissecao(f, a, b, epsilon, maxIteracoes):
    fa = f(a)
    fb = f(b)

    coord = []

    # checando se a funcao muda de sinal no intervalo
    if(fa * fb > 0):
        return(True, k, None, coord)
    
    intervaloAtual = abs(b - a)
    x = (a + b) / 2
    fx = f(x)

    # checando se a diferenca do intervalo ja nao 
    # esta proxima o suficiente da tolerancia
    if(intervaloAtual <= epsilon):
        return(False, k, x, coord)
    
    coord.append((0, a, fa, b, fb, x, fx, intervaloAtual))

    k = 0

    while(k <= maxIteracoes):
        if (fa * fx > 0):
            a = x
            fa = fx
        else:
            b = x
            fb = fx
        
        intervaloAtual = abs(b - a)
        x = (a + b) / 2
        fx = f(x)

        coord.append((k, a, fa, b, fb, x, fx, intervaloAtual))

        # checando se a diferenca do intervalo ja nao 
        # esta proxima o suficiente da tolerancia
        if(intervaloAtual <= epsilon):
            return(False, k, x, coord)
        
        k += 1
    
    print("Numero maximo de interacoes alcancado")
    return(True, k, x, coord)

def imprimir_resultado(statusErro, raiz, nIteracoes):
    if(statusErro):
        print("Erro no metodo da bissecao apos %s iteracoes", nIteracoes)
    if(raiz != None):
        print("Metodo da Bissecao\nRaiz %s encontrada com %s iteracoes" % (raiz, nIteracoes))

def plotar(coordenadas):
    iterac = []
    valorRaiz = []

    for i in coordenadas:
        iterac.append(i[0]) #posição 0, k
        valorRaiz.append(i[5]) #posição 7, x

    pyplot.plot(iterac,valorRaiz)
    pyplot.title('Gráfico de Convergência - Método da Bisseção')
    pyplot.show()

(haErro, iteracoes, raiz, coordenadas) = bissecao(f, -4, -2, 0.0001, 50)

imprimir_resultado(haErro, raiz, iteracoes)
plotar(coordenadas)