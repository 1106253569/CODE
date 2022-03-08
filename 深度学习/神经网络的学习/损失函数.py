import numpy as np
import sys, os

sys.path.append(os.getcwd())
from dataset.mnist import load_mnist


#均方误差
def mean_squared_error(y, t):
    return 0.5 * np.sum((y - t)**2)


#交叉熵误差
def cross_entropy_error(y, t):
    if y.ndim == 1:
        t = t.reshape(1, t.size)
        y = y.reshape(1, y.size)

    batch_size = y.shape[0]
    return -np.sum(np.log(y[np.arange(batch_size),t]+1e-7)) / batch_size


(x_train,t_train),(x_test,t_test)=\
    load_mnist(normalize=True,one_hot_label=True)

#print(x_train.shape)
#print(t_train.shape)

train_size = x_train.shape[0]
batch_size = 10
batch_mask = np.random.choise(train_size, batch_size)
x_batch = x_train[batch_mask]
t_batch = t_train[batch_mask]
