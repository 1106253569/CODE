import matplotlib
import matplotlib.pyplot as pyplot
import numpy

matplotlib.rcParams['font.family'] = 'SimHei'
matplotlib.rcParams['font.sans-serif'] = ['SimHei']
x=numpy.linspace(0,10,1000)
y=numpy.cos(2*numpy.pi*x)*numpy.exp(-x)+0.8
pyplot.plot(x,y,'k',color='r',label="$exp-decay$",linewidth=3)
pyplot.axis([0,6,0,1.8])
ix=(x>0.8)&(x<3)
pyplot.fill_between(x,y,0,where=ix,\
    facecolor='grey',alpha=0.25)
pyplot.text(0.5*(0.8+3),0.2,r"$\int_a^b f(x)\mathrm{d}x$",\
    horizontalalignment='center')
pyplot.legend()
pyplot.show()