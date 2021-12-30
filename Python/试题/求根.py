from math import sqrt


def root(a, b, c):
    delta = b * b - 4 * a * c
    if delta > 0:
        x1 = (-b + sqrt(delta)) / (2 * a)
        x2 = (-b - sqrt(delta)) / (2 * a)
        return x1, x2
    elif delta == 0:
        x1 = -b / (2 * a)
        return x1
    else:
        c1r = -b / (2 * a)
        c1i = sqrt(-delta) / (2 * a)
        c1 = complex(c1r, c1i)
        c2 = c1.conjugate()
        return c1, c2


a = 3
b = 4
c = 5
print(root(a, b, c))
