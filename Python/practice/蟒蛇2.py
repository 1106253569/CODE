import turtle


def drawSnake(rad, angle, len, neckrad):
    for i in range(len):
        turtle.circle(rad, angle)
        turtle.circle(-rad, angle)
    turtle.circle(rad, angle / 2)
    turtle.fd(rad)
    turtle.circle(neckrad + 1, 180)
    turtle.fd(rad * 2 / 3)


def main():
    turtle.setup(1300, 600, 200, 200)
    pythonSize = 30
    turtle.pensize(pythonSize)
    turtle.pencolor("black")
    turtle.seth(-40)
    drawSnake(40, 80, 5, pythonSize / 2)


main()
