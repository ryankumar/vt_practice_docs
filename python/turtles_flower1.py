import turtle
##create window and turtle
window = turtle.Screen()
babbage = turtle.Turtle()

##draw stem and center
babbage.left(90)
babbage.forward(100)
babbage.right(90)
babbage.circle(10)

##draw first petal
babbage.left(15)
babbage.forward(50)
babbage.left(157)
babbage.forward(50)

##draw remaining 23 petals
for i in range(1,23):
    babbage.left(15)
    babbage.forward(50)
    babbage.left(157)
    babbage.forward(50)

#Dark center circle
for i in range(1,10):
    babbage.circle(i)


#make a circle around petals
babbage.left(15)
babbage.forward(50)
babbage.left(80)
babbage.circle(50)
##tidy up window
window.exitonclick()
