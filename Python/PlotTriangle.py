import numpy
import matplotlib.pyplot as pyplot
x=numpy.linspace(0,6,100)
y=numpy.cos(2*numpy.pi*x)*numpy.exp(-x)+0.8
pyplot.plot(x,y,'k',color='b',linewidth=1,linestyle="-")
pyplot.show()