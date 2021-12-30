def GYS(a, b):
    if a < b:
        a, b = b, a
    while b != 0:
        a, b = b, a % b
    return a


def GBS(a, b):
    return a * b // GYS(a, b)


print(GYS(35, 65), GBS(35, 65))
