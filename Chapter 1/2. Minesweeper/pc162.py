"""
Online Judge: Problem 10189 - Minesweeper

Judge Version: PYTH3 3.5.1 - Python 3
Best Run Time: 0.010 Seconds

"""

import sys

# For local testing with a text file including sample input
# Uncomment to use local testing
"""
if sys.stdin.isatty():
    sys.stdin = open("p10189.txt", "r")
"""

# All 8 possible neighboring positions around a cell:
# top-left, top, top-right, left, right, bottom-left, bottom, bottom-right
dirs = ((-1,-1), (-1,0), (-1,1), (0,-1), (0,1), (1,-1), (1,0), (1,1))

def main():
    """
    Main execution loop.
    """

    # Read all input lines at one time and store in a list
    lines = [line.rstrip() for line in sys.stdin.read().splitlines() if line.strip() != ""]

    # Variable used to store entire final resulting output 
    final_output= []
    
    # Index used to keep track of loop through saved input
    idx = 0

    # Keep track of the field number being processed
    # Required for output
    field_cnt = 0

    # Process fields until input  dimensions "0 0" are provided
    while idx < len(lines):

        # Read the dimensions of the field
        n, m = map(int, lines[idx].split())
        idx += 1

        # Field dimensions "0 0" indicate the end of input
        # Exit the loop if this is the case
        if n == 0 and m == 0:
            break

        # Store the field from the input
        # Read the field row by row and store as a list
        field = [list(lines[idx + r]) for r in range(n)]
        idx += n

        # Create a grid with the same dimensions initialized with zeros
        # Used to store counts of mines adjacent to the cells
        counter = [[0]*m for _ in range(n)]

        # Traverse every cell in the field
        for row_num in range(n):
            row = field[row_num]
            for col_num, cell in enumerate(row):

                # If the current cell contains a mine,
                # update all valid neighboring cells
                if cell == '*':

                    # Check all 8 neighboring cells of current cell
                    for dir_row, dir_col in dirs:
                        n_row, n_col = row_num + dir_row, col_num + dir_col

                        # Ensure the neighbor cell being checked is within the field dimemsions and is not a mine
                        # Add 1 to the current value stored in the number grid
                        if 0 <= n_row < n and 0 <= n_col < m and field[n_row][n_col] != '*':
                            counter[n_row][n_col] += 1

        # Increment the field number counter
        field_cnt += 1

        # Print a blank line between consecutive fields after the first one
        if field_cnt > 1:
            final_output.append("") 

        # Add the current field number to the final output list
        final_output.append(f"Field #{field_cnt}:")

        # Build current field and add to final output list
        # Use both field and counter lists
        # Mines remain '*'
        # Empty cells become their adjacent mine count instead of '.'
        for row in range(n):
            final_output.append(''.join('*' if field[row][col] == '*' else str(counter[row][col]) for col in range(m)))

    print("\n".join(final_output))

if __name__ == "__main__":
    main()