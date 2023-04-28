import matplotlib.pyplot as plt

fig, ax = plt.subplots()
ax.set(xlabel='x', ylabel='y',
title='Gráfico do Conjunto de Pontos')

x = [-3, -2, 1, 2, 4, 7]
y = [18.1, 6, 3, 4, 19, 46]

plt.grid()
plt.scatter(x, y)
plt.show()