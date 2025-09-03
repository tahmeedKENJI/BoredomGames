import random

print("Welcome to the Number Guessing Game!")
number = random.randint(1, 100000)
attempts = 0

while True:
    guess = input("Enter your guess (1-100000): ")
    if not guess.isdigit():
        print("Please enter a valid number.")
        continue
    guess = int(guess)
    attempts += 1
    
    # Give feedback based on closeness
    if guess == number:
        print(f"Congratulations! You guessed it in {attempts} attempts.")
        break
    elif abs(guess - number) > 10:
        if guess < number:
            print("Too low!")
        else:
            print("Too high!")
    else:
        if guess < number:
            print("Low!")
        else:
            print("High!")

