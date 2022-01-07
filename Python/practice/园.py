from random import random
from math import math, sqrt
from time import time
Darts=1000
hits=0.0
time.clock()
for i in range(1,Darts+1):
    x,y=random(),random()
    dist=sqrt(x**2+y**2)
    if dist<=1.0:
        ++hits
pi=4*(hits/Darts)
print("pi={}",format(pi))
print("running time={:.5f}s",format(time.clock()))
