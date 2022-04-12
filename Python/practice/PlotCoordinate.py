import matplotlib
import matplotlib.pyplot as pyplot
import numpy

matplotlib.rcParams['font.family'] = 'SimHei'
matplotlib.rcParams['font.sans-serif'] = ['SimHei']
pyplot.plot([1, 2, 4], [1, 2, 3])
pyplot.title("坐标系标题")
pyplot.xlabel('time(s)')
pyplot.ylabel('area(m)')
pyplot.xticks([1, 2, 3, 4, 5], [r'$\pi/3$', r'$2\pi/3$', r'$\pi$', \
                                r'$4\pi/3$', r'$5\pi/3$'])
pyplot.show()
