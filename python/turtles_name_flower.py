import turtle
# create window and turtle
window =turtle.Screen()
babbage=turtle.Turtle()

#draw stem
babbage.color("green","black")
babbage.left(90)
babbage.forward(100)
babbage.right(90)

# draw center
babbage.color("black","black")
babbage.begin_fill()
babbage.circle(10)
babbage.end_fill()

#draw all petals
for i in range(1,24):
    if babbage.color()==("red","black"):
        babbage.color("orange","black")
    elif babbage.color()==("orange","black"):
        babbage.color("yellow","black")
    else:
        babbage.color("red","black")

    babbage.left(15)
    babbage.forward(50)
    babbage.left(157)
    babbage.forward(50)

babbage.color("orange","black")
babbage.left(15)
babbage.forward(50)
babbage.left(80)

babbage.color("blue","black")
babbage.circle(50)

babbage.color("white","black")
babbage.right(180)
babbage.forward(150)
babbage.right(90)
babbage.forward(300)
babbage.right(90)

# write Thanks
#T
babbage.color("green","black")
babbage.forward(50)
babbage.left(90)
babbage.forward(40)
babbage.left(180)
babbage.forward(80)

#H

babbage.color("white","black")
babbage.forward(5)
babbage.color("green","black")
babbage.right(90)
babbage.forward(50)
babbage.left(180)
babbage.forward(25)
babbage.right(90)
babbage.forward(25)
babbage.left(90)
babbage.forward(25)
babbage.left(180)
babbage.forward(50)

#A

babbage.color("white","black")
babbage.left(90)
babbage.forward(5)
babbage.color("green","black")
babbage.left(75)
babbage.forward(60)
babbage.right(135)
babbage.forward(60)
babbage.right(180)
babbage.forward(20)
babbage.left(45)
babbage.forward(30)
babbage.right(180)
babbage.forward(30)
babbage.right(45)
babbage.forward(20)



#N

babbage.color("white","black")
babbage.left(60)
babbage.forward(5)
babbage.color("green","black")

babbage.left(90)
babbage.forward(40)
babbage.right(142)
babbage.forward(50)
babbage.left(142)
babbage.forward(40)


babbage.pendown()


#babbage.hideturtle()

#draw center
window.exitonclick()

