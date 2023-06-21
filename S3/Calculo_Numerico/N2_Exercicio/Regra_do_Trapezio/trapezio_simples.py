import math

def f(x):
    return (math.e ** (-x)) + math.cos(3 * x) - math.pow(x, 4)

def calcularErro(valor):
    erro = -47.9915748014691 - valor
    percentual = abs((erro * 100) / -47.9915748014691)
    percentual = '~ {:.2f}%'.format(percentual)
    return (erro, percentual)

def imprimirResultados(resultadoFinal, erro):
    print('\nResultado final:', resultadoFinal)
    print('Erro de', erro[0])
    print('Corresponde a', erro[1], 'do resultado-alvo (-47.9915748014691)')

def trapezioSimples(a, b):
    intervaloH = b - a
    return (intervaloH / 2) * (f(a) + f(b))

resultado = trapezioSimples(1, 3)
valorErro = calcularErro(resultado)
imprimirResultados(resultado, valorErro)