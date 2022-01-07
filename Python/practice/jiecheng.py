import turtle
turtle.pencolor("blue")
turtle.penup()
turtle.fd(-250)
turtle.right(90)
turtle.fd(200)
turtle.left(180)
print(turtle.pos())
i=500
while i!=0:
    turtle.fd(i)
    turtle.right(90)
    turtle.fd(i)
    turtle.right(90)
    i-=25
    turtle.fd(i)
    turtle.right(90)
    turtle.fd(i)
    turtle.right(90)
    i-=25