import numpy as np


def fun(x):
    return x[0]**2 + x[1]**2  #np.sum(x**2)

#对x0的偏导
def fun_tmp1(x0):
    return x0*x0+4.0**2.0

#对x1的偏导
def fun_tmp2(x1):
    return 3.0**2.0+x1*x1


