"""
Online Judge: Problem 10137 - The Trip

Judge Version: PYTH3 3.5.1 - Python 3
Best Run Time: 0.010 Seconds

"""

import sys

# For local testing with a text file including sample input
# Uncomment to use local testing
#if sys.stdin.isatty():
#    sys.stdin = open("pc163_inputs.txt", "r")


# Process student groups until a group count of "0" is provided
while True:

    # Number of students in the group being evaluated
    n = int(sys.stdin.readline())

    # If the number of students given is 0, break from the loop to end the program
    if n == 0:
        break

    # The amounts that each student in the group pays
    amounts = []

    # The total cents spent by all students
    total = 0

    # For each student, store each amount as cents to avoid issues with rounding floating point numbers
    for _ in range(n):
        s = sys.stdin.readline().strip()

        # Split the amount into dollars and cents
        dollars, cents = s.split('.')

        # Convert the dollar amount to cents and add the original cents value
        new_amount = int(dollars) * 100 + int(cents)

        # Append converted amount to list
        amounts.append(new_amount)

        # Add to total cents spent by all students
        total += new_amount



    # Calculate the floor average of the total cents spent per student
    low_avg = total // n 

    # If the floor average is not an integer, calculate the ceiling average (add 1 to the for average)
    # Otherwise, use the floor average
    high_avg = low_avg + (1 if total % n else 0)


    # The total amount of those whose expenses were above the ceiling average and need to give money to equalize costs
    give = 0

    # The total amount of those whose expenses were below the floor average and need to take money to equalize costs
    take = 0

    # Evaluate all student expenses
    for value in amounts:

        # If the amount paid is higher than the ceiling average,
        #   subtract the ceiling average from the amount paid and add to the give total
        if value > high_avg:
            give += value - high_avg

        # If the amount paid is lower than the floor average,
        #   subtract the amount paid from the floor average and add to the take total
        elif value < low_avg:
            take += low_avg - value

    # Print the largest of the total give and take values
    # Format as currency
    final = max(give, take)
    print(f"${final / 100:.2f}")