import random
secret = int(random.uniform(0,10))
print("secret number is",secret)
print("i'm thinking of a number between zero and ten ","can you guess it is? ")

guess=11

while guess!=secret:
    guess=int(input("take a guess: "))

print("Well done")
