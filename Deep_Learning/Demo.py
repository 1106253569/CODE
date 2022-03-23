import numpy as np


def sigmoid(x):
    return 1 / (1 + np.exp(-x))


def softmax(a):
    c = np.max(a)
    exp_a = np.exp(a - c)
    sum_exp_a = np.sum(exp_a)
    y = exp_a / sum_exp_a
    return y


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
    return np.exp(-x)*(1 / (1 + np.exp(-x)))**2


def mean_squared_error(y, t):
    return 0.5 * np.sum((y - t)**2)


def init_network():
    network = {}
    network['W1'] = np.array([[0.1, 0.15, 0.2], [0.15, 0.25, 0.35]])
    network['b1'] = np.array([0.35, 0.35, 0.35])
    network['W2'] = np.array([[0.4, 0.45], [0.5, 0.55], [0.6, 0.65]])
    network['b2'] = np.array([0.65, 0.65, 0.65])
    network['o']=np.array([5,10])
    return network


def forward(network, x):
    W1, W2 = network['W1'], network['W2']
    b1, b2 = 0.35, 0.65
    
    a1 = np.dot(x, W1) + b1
    print(a1)
    z1 = sigmoid(a1)
    print(z1)
    a2 = np.dot(z1.T, W2) + b2
    print(a2)
    y = sigmoid(a2)
    dw1=(y[0]-0.01)*fun()
    return y


def numerical_diff(f, x):
    h = 1e-4
    return (f(x + h) - f(x - h)) / 2 * h


network = init_network()
x = np.array([5, 10])

W1, W2 = network['W1'], network['W2']
b1, b2 = 0.35, 0.65
w=np.array([0.1,0.15,0.2,0.25,0.3,0.35,0.4,0.45,0.5,0.55,0.6,0.65])
a1 = np.dot(x, W1) + b1
print(a1)
z1 = sigmoid(a1)
print(z1)
a2 = np.dot(z1.T, W2) + b2
print(a2)
y = sigmoid(a2)
print(y)
dw1=(y[1]-0.99)*fun(a2[1])*z1[2]
print(w[11]-0.5*dw1)
dw2=fun(a2[0])*w[10]*fun(a1[2])*x[0]
dw3=fun(a2[1])*w[11]*fun(a1[2])*x[0]
dw4=(y[0]-0.01)*dw2+(y[1]-0.99)*dw3
print(w[5]-0.5*dw4)