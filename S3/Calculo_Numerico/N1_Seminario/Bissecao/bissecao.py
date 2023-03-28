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

def Bissecao(f, a, b, epsilon, maxIteracoes):
    fa = f(a)
    fb = f(b)

    coord = []

    # se o produto do inicio com o fim do intervalo na funcao
    # nao for negativo (nao houver troca de sinal) nao se deve
    # continuar o metodo, retorna-se erro
    if(fa * fb > 0):
        return(True, k, None, coord)
    
    intervaloAtual = abs(b - a)
    x = (a + b) / 2
    fx = f(x)

    # se o intervalo ja for pequeno o suficiente comparado ao
    # valor da tolerancia (epsilon), interrompe-se o metodo,
    # mas retorna-se sucesso
    if(intervaloAtual <= epsilon):
        return(False, k, x, coord)
    
    '''
        # Teste de Mesa, nao altere
        print("k = 0\na = %s\nfa = %s\nb = %s\nfb = %s\nx = %s\nfx = %s\nintervaloAtual = %s\n\n" % (a, fa, b, fb, x, fx, intervaloAtual))
    '''
    coord.append((0, a, fa, b, fb, x, fx, intervaloAtual))

    k = 1

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

        '''
        # Teste de Mesa, nao altere
        print("k = %s\na = %s\nfa = %s\nb = %s\nfb = %s\nx = %s\nfx = %s\nintervaloAtual = %s\n\n" % (k, a, fa, b, fb, x, fx, intervaloAtual))
        '''
        coord.append((k, a, fa, b, fb, x, fx, intervaloAtual))

        # se o intervalo ja for pequeno o suficiente comparado ao
        # valor da tolerancia (epsilon), interrompe-se o metodo,
        # mas retorna-se sucesso
        if(intervaloAtual <= epsilon):
            return(False, k, x, coord)
        
        k += 1
    
    print("Numero maximo de interacoes alcancado")
    return(True, k, x, coord)



(haErro, iteracoes, raiz, coordenadas) = Bissecao(f, -4, -2, 0.0001, 50)

if(haErro):
    print("Erro no metodo da bissecao apos %s iteracoes", iteracoes)
if(raiz != None):
    print("Metodo da Bissecao\nRaiz %s encontrada com %s iteracoes" % (raiz, iteracoes))

iterac = []
intervDelta = []

for i in coordenadas:
    iterac.append(i[0]) #posição 0, k
    intervDelta.append(i[7]) #posição 7, intervX

pyplot.plot(iterac,intervDelta)
pyplot.title('Gráfico de Convergência - Método da Bisseção')
pyplot.show()