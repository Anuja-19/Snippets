import random
print("\n\n********** NUMBER GUESSING GAME **********\n\n")
name = input("Hello! What is your name?\n")
sec_num = random.randint(1,20)
print(f"Well {name}, I am thinking of a number between 1 and 20.\n")

# print("The number I was thinking was : ", sec_num)

for i in range(1,7):
    print("Take a guess : ")
    guess = int(input())
    if guess < sec_num:
        print("Your guess is too low!\n")
    elif guess > sec_num:
        print("Your guess is too high!\n")
    else:
        break;

if guess == sec_num:
    print(f"Congrats! You guessed the number in {i} times!\n")
else:
    print(f"Nope, the number I was thinking of was {sec_num}\n") '''
