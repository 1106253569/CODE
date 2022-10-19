import numpy as np

from Deep_Learning.神经网络.实现 import forward

class Relu:
    def __init__(self) -> None:
        self.mask=None
        
    def forword(self,x):
        #True/False
        self.mask=( x <=0)
        out=x.copy()
        out[self.mask]=0
        
        return out

    def backward(self,dout):
        dout[self.mask]=0
        dx=dout

        return dx
        
class Sigmoid:
    def __init__(self) -> None:
        self.out=None

    def forward(self,x):
        out=1/(1+np.exp(-x))
        self.out=out

        return out
    
    def backward(self,dout):
        dx=dout*(1.0-self.out)*self.out

        return dx

        
        