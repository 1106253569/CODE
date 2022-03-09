import numpy as np
import matplotlib.pyplot as plt


def numerical_diff(f, x):
    h = 1e-4
    return (f(x + h) - f(x - h)) / 2 * h


def fun1(x):
    return 0.01 * x**2 + 0.1 * x


x = np.arange(0.0, 20.0, 0.1)
y = fun1(x)
plt.xlabel("x")
plt.ylabel("y")
plt.plot(x, y)
plt.show()

#在x=5的微分
print(numerical_diff(fun1, 5))
