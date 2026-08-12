"""
Online Judge: Problem 706 - LC-Display

Judge Version: PYTH3 3.5.1 - Python 3
Best Run Time: 0.040 Seconds

"""

import sys

# For local testing with a text file including sample input
# Uncomment to use local testing
#if sys.stdin.isatty():
#    sys.stdin = open("pc164_inputs.txt", "r")


# Seven-segment representation for digits 0-9.
# Order of segments: top, upper-left, upper-right,
# middle, lower-left, lower-right, bottom
DIGIT_MAP = [
    (1,1,1,0,1,1,1),  # 0
    (0,0,1,0,0,1,0),  # 1
    (1,0,1,1,1,0,1),  # 2
    (1,0,1,1,0,1,1),  # 3
    (0,1,1,1,0,1,0),  # 4
    (1,1,0,1,0,1,1),  # 5
    (1,1,0,1,1,1,1),  # 6
    (1,0,1,0,0,1,0),  # 7
    (1,1,1,1,1,1,1),  # 8
    (1,1,1,1,0,1,1),  # 9
]


def render(s, n):

    # Total number of rows in a digit of size s
    rows = 2 * s + 3

    # Stores every row of the final LCD display
    out = []

    # Generate the display one row at a time
    for r in range(rows):
 
        # Holds the current row for all digits
        row = []

        # Render each digit in the input number
        for num in n:
            
            # Retrieve the seven-segment pattern for this digit
            a, b, c, d, e, f, g = DIGIT_MAP[ord(num) - 48]

            # Top horizontal segment
            if r == 0:
                row.append(' ' + ('-' * s if a else ' ' * s) + ' ')

            # Upper vertical segments
            elif 1 <= r <= s:
                row.append(('|' if b else ' ') + (' ' * s) + ('|' if c else ' '))

            # Middle horizontal segment
            elif r == s + 1:
                row.append(' ' + ('-' * s if d else ' ' * s) + ' ')

            # Lower vertical segments 
            elif s + 2 <= r <= 2 * s + 1:
                row.append(('|' if e else ' ') + (' ' * s) + ('|' if f else ' '))

            # Bottom horizontal segment
            else:
                row.append(' ' + ('-' * s if g else ' ' * s) + ' ')

        # Combine all digits for this row
        out.append(' '.join(row))

    # Return the complete LCD display
    return '\n'.join(out)

# Read the entire input at once for faster processing
data = sys.stdin.buffer.read().split()
i = 0

#first = True

# Stores the rendered output for every input row
final_output = []


# Process test cases until the terminating pair "0 0" is encountered
while True:

    # Display size
    s = int(data[i])

    # Number to render
    n = data[i + 1].decode()
 
    i += 2

    # End of input
    if s == 0 and n == '0':
        break

    # Render the current input row
    final_output.append(render(s, n))

# Print the entire output
# Print a blank line between consecutive test cases
sys.stdout.write('\n\n'.join(final_output) + '\n\n')