import numpy as np
import matplotlib.pyplot as plt

def exp_interpolation(x, y, xp):
    y_ln = np.log(y)
    yp_ln = np.interp(xp, x, y_ln)
    n = len(x)
    p_ln = 0
    for i in range(n):
        li = 1
        for j in range(n):
            if j != i:
                li *= (xp - x[j]) / (x[i] - x[j])
        p_ln += y_ln[i] * li

    yp = np.exp(p_ln)
    return yp

x = [1, 2, 3, 4, 5]
y = [0.5, 0.8, 0.1, 0.12, 0.16]
xp = [1.5, 2.5, 3.5, 4.5]

yp = [exp_interpolation(x, y, xi) for xi in xp]

t = np.arange(x[0], x[-1]+0.1, 0.1)
yt = [exp_interpolation(x, y, xi) for xi in t]
plt.plot(t, yt, 'b-', label="Interpolação")
plt.plot(x, y, 'ro')
plt.plot(xp, yp, 'g*', label="Pontos desejados")
plt.legend()
plt.show()