import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 1, 100)
y = 1 / np.sqrt(1 + x ** 2)
plt.plot(x, y)
plt.show()
