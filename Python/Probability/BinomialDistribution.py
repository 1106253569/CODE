import numpy as np  #导入numpy
from scipy.stats import binom  #导入uniform

m = 19
p = 0.3

x = np.random.binomial(m, p, size=100)
a1 = x.mean()  #1阶样本原点矩
print('mu=%.4f' % a1)  #总体均值的矩估计
a2 = (x**2).mean()  #2阶样本原点矩
print('sigma^2=%.5f' % (a2 - a1**2))  #总体方差的矩估计
a = a1 - np.sqrt(3 * (a2 - a1**2))
b = a1 + np.sqrt(3 * (a2 - a1**2))
print("a=", a)
print("b=", b)
