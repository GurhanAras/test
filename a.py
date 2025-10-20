
# COMPOUND INTEREST CALCULATOR

import math

initial_principal = 0 
interest_rate = 0 
time_elapsed = 0 

while initial_principal <= 0:
    initial_principal = float(input("Enter the initial principal amount: "))
    if initial_principal <= 0:
        print("Initial principal amount cannot be less than or equal to zero.")

while interest_rate <= 0:
    interest_rate = float(input("Enter the interest rate (in percent): "))
    if interest_rate <= 0:
        print("Interest rate cannot be less than or equal to zero.") 

while time_elapsed <= 0:
    time_elapsed = int(input("Enter the time in years: "))
    if time_elapsed <=0:
        print("The elapsed time cannot be less than or equal to zero.")

total = initial_principal * math.pow((1 + (interest_rate / 100)), time_elapsed)

print(f"Balance after {time_elapsed} year/s is ${total:.3f}.")

