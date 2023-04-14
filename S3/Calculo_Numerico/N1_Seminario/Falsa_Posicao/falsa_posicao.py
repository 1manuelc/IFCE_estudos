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

def falsa_posicao(f, a, b, epsilon, maxIteracoes):
    fa = f(a)
    fb = f(b)

    coord = []

    # checando se a funcao muda de sinal no intervalo
    if(fa * fb > 0):
        return(True, 0, None, coord)
    
    intervaloAtual = abs(b - a)

    coord.append((0, 0))

    # checando se a diferenca do intervalo ja nao 
    # esta proxima o suficiente da tolerancia
    if(intervaloAtual <= epsilon):
        return(False, 0, a, coord)

    # checando se a raiz nao esta nas extremidades a e b
    if(abs(fa) <= epsilon):
        return(True, 0, a, coord)
    
    if(abs(fb) <= epsilon):
        return(True, 0, b, coord)
    
    for k in range(1, maxIteracoes):
        # calculando xk como secante
        x = ((a * fb) - (b * fa)) / (fb - fa)
        fx = f(x)

        print(k, x)
        coord.append((k, x))

        # checando se o valor de fx ja nao esta proximo
        # o suficiente da tolerancia
        if(abs(fx) <= epsilon):
            return(False, k, x, coord)
        
        if (fa * fx > 0):
            a = x
            fa = fx
        else:
            b = x
            fb = fx

        intervaloAtual = abs(b - a)

        # checando se a diferenca do intervalo ja nao 
        # esta proxima o suficiente da tolerancia
        if(intervaloAtual <= epsilon):
            return(False, k, x, coord)
    
    print("Número máximo de interações alcancado")
    return(True, k, x, coord)

def imprimir_resultado(statusErro, raiz, nIteracoes):
    if(statusErro):
        print("Erro no método da falsa posição após %s iterações", nIteracoes)
    if(raiz != None):
        print("Método da Falsa Posição\nRaiz %s encontrada com %s iterações" % (raiz, nIteracoes))

def plotar(coordenadas):
    iterac = []
    valorRaiz = []

    for i in coordenadas:
        iterac.append(i[0]) #posição 0, k
        valorRaiz.append(i[1]) #posição 1, x
    
    fig, ax = pyplot.subplots()
    ax.set(xlabel='Iterações', ylabel='Raiz',
    title='Gráfico de Convergência - Método da Falsa Posição')
    ax.grid()
    pyplot.plot(iterac,valorRaiz)
    pyplot.show()

(haErro, iteracoes, raiz, coordenadas) = falsa_posicao(f, -4, -2, 0.0001, 50)

imprimir_resultado(haErro, raiz, iteracoes)
plotar(coordenadas)