import random

print("Welcome to the Number Guessing Game!")
number = random.randint(1, 100000000)
attempts = 0
invalid_attempt = 0

debug_mode = 0

while True:
	# input options
    guess = input("Enter your guess (1-100000000): ")
    if guess == 'debug_cheat_hack':
        debug_mode = 1
    elif not guess.isdigit():
        print("Please enter a valid number.")
        invalid_attempt = 1
    else: 
        guess = int(guess)
        attempts+=1
    
	# spare invalid attempts
    if (invalid_attempt):
        invalid_attempt = 0
        continue
   
	# debugger
    if (debug_mode):
        print(f"The answer is {number}")
        debug_mode = 0
        continue
	
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

