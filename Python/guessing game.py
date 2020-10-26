import random
import math

sec_num=random.randrange(0,100,1)

i=1
while i<=4:
    guess=input("Enter the guess number(0-100):")
    if int(guess)==sec_num:
        print("You win")
        break
    elif int(guess)!=sec_num:
        print("wrong plz try again")

    i=i+1

    if i==5:
            print("you lost")


