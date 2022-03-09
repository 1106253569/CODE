import numpy as np


#梯度指向各点处函数值减少最多的方向
def numerical_gradient(f, x):
    h = 1e-4
    grad = np.zeros_like(x)

    for idx in range(x.size):
        tmp_val = x[idx]
        #f(x+h)
        x[idx] = tmp_val + h
        fxh1 = f(x)

        #f(x-h)
        x[idx] = tmp_val - h
        fxh2 = f(x)

        grad[idx] = (fxh1 - fxh2) / (2 * h)
        x[idx] = tmp_val

    return grad


def gradient_descent(f, init_x, lr=0.01, step_num=100):
    x = init_x

    for i in range(step_num):
        grad = numerical_gradient(f, x)
        x -= lr * grad
        
    return x

def fun(x):
    return x[0]**2 + x[1]**2  #np.sum(x**2)


init_x=np.array([-3.0,4.0])
print(gradient_descent(fun,init_x=init_x,lr=0.1,step_num=100))

