import math

def f(x):
    return (math.e ** (-x)) + math.cos(3 * x) - math.pow(x, 4)

def calcularErro(valor):
    erro = -47.9915748014691 - valor
    percentual = abs((erro * 100) / -47.9915748014691)
    percentual = '~ {:.2f}%'.format(percentual)
    return (erro, percentual)

def imprimirResultados(resultadoFinal, erro):
    print('\nMétodo de 1/3 de Simpson Simples\nResultado final:', resultadoFinal)
    print('Erro de', erro[0])
    print('Corresponde a', erro[1], 'do resultado-alvo (-47.9915748014691)')

def simpson13Simples(a, b):
    intervaloH = (b - a) / 2

    return (intervaloH / 3) * (f(a) + (4 * f(a + intervaloH)) + f(b))

resultado = simpson13Simples(1, 3)
erro = calcularErro(resultado)

imprimirResultados(resultado, erro)