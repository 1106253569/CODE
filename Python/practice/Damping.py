import matplotlib
import matplotlib.pyplot as pyplot
import numpy

matplotlib.rcParams['font.family'] = 'SimHei'
matplotlib.rcParams['font.sans-serif'] = ['SimHei']


def Draw(pcolor, nt_point, nt_text, nt_size):
    pyplot.plot(x,
                y,
                'k',
                label="$exp_decay$",
                color=pcolor,
                linewidth=3,
                linestyle="-")
    pyplot.plot(x, z, "b--", label="$cos(x^2)$", linewidth=1)
    pyplot.xlabel('时间(s)')
    pyplot.ylabel('幅度(mV)')
    pyplot.title("阻尼衰减曲线绘制")
    pyplot.annotate('$\cos(2 \pi t) \exp(-t)$', xy=nt_point, xytext=nt_text, fontsize=nt_size, \
                    arrowprops=dict(arrowstyle='->', connectionstyle="arc3,rad=.1"))


def Shadow(a, b):
    ix = (x > a) & (x < b)
    pyplot.fill_between(x, y, 0, where=ix, facecolor='grey', alpha=0.25)
    pyplot.text(0.5 * (a + b), 0.2, "$\int_a^b f(x)\mathrm{d}x$", \
                horizontalalignment='center')


def XY_Axis(x_start, x_end, y_start, y_end):
    pyplot.xlim(x_start, x_end)
    pyplot.ylim(y_start, y_end)
    pyplot.xticks([numpy.pi / 3, 2 * numpy.pi / 3, 1 * numpy.pi, 4 * numpy.pi / 3, 5 * numpy.pi / 3], \
                  ['$\pi/3$', '$2\pi/3$', '$\pi$', '$4\pi/3$', '$5\pi/3$'])


x = numpy.linspace(0.0, 6.0, 100)
y = numpy.cos(2 * numpy.pi * x) * numpy.exp(-x) + 0.8
z = 0.5 * numpy.cos(x ** 2) + 0.8
note_point, note_text, note_size = (1,
                                    numpy.cos(2 * numpy.pi) * numpy.exp(-1) +
                                    0.8), (1, 1.4), 14
fig = pyplot.figure(figsize=(8, 6), facecolor="white")
pyplot.subplot(111)
Draw("red", note_point, note_text, note_size)
XY_Axis(0, 5, 0, 1.8)
Shadow(0.8, 3)
pyplot.legend()
pyplot.savefig('sample.JPG')
pyplot.show()
