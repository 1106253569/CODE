import matplotlib.pyplot as plt
import numpy as np


def XY_Axis(x_start, x_end, y_start, y_end):
    plt.xlim(x_start, x_end)
    plt.plot.ylim(y_start, y_end)
    plt.xticks([np.pi / 3, 2 * np.pi / 3, 1 * np.pi, 4 * np.pi / 3, 5 * np.pi / 3], \
               ['$\pi/3$', '$2\pi/3$', '$\pi$', '$4\pi/3$', '$5\pi/3$'])


XY_Axis(3, 3, 3, 3)
