"""
Online Judge: Problem 100 - The 3n + 1 Problem

Judge Version: PYTH3 3.5.1 - Python 3
Best Run Time: 0.370 Seconds

"""


import sys

# Local Test vs. Judge toggle
# Set False when submitting to judge
# Set True when testing locally
if sys.stdin.isatty():
    sys.stdin = open("p100.txt", "r")


# Upper bound for caching cycle lengths
MAX = 1_000_000

# Cache to store already computed cycle lengths.
# cache[n] = cycle length of n (only stored if n <= MAX)
cache = [0] * (MAX + 1)
cache[1] = 1  # Store base case: cycle length of 1 is 1


def cycle_length(n: int) -> int:
    """
    Compute the Collatz cycle length for integer n using:
    - Memoization (cache)
    - Iterative approach
    - Bitwise calculations

    Args:
        n (int): the number for which we want to determine the cycle length

    Returns:
        int: cycle length of n
    """

    original_n = n  # Save original input for caching
    length = 0

    while n != 1:
        
        # If we've already computed this value, reuse it and break the loop
        # This avoids recomputing large parts of the sequence
        if n <= MAX and cache[n] != 0:
            length += cache[n]
            break

        if n & 1:
            # If n is Odd: 
            # Calculate n = 3*n + 1 
            # Then Immediately divide the result by 2 since the result is always even
            # Final result: n = (3*n + 1)/2 (bitwise)
            # Increase cycle length by 2
            n = (3 * n + 1) >> 1
            length += 2
        else:
            # If n is Even:
            # Calculate: n = n/2 (bitwise) 
            n >>= 1
            length += 1
        
    # If we reached 1 directly (not via cache), count the final step
    if n == 1:
        length += 1

    # Store result for reuse if less than the maximum 
    if original_n <= MAX:
        cache[original_n] = length

    return length


def main():
    """
    Main execution loop.
    """

    # Evaluate each line in local or judge's test file
    for line in sys.stdin:
        # Skip empty lines
        if not line.strip():
            continue

        # Read values
        i, j = map(int, line.split())

        # Maintain numerical order of values (judge examples are sometimes not in numerical order)
        start, end = min(i, j), max(i, j)

        # Remember the largest cycle within the current range
        max_cycle_len = 0

        # Compute cycle lengths for all numbers in range [i, j]
        # Store the highest
        for n in range(start, end + 1):
            c = cycle_length(n)
            if c > max_cycle_len:
                max_cycle_len = c

        # Output format to match judge's desired output (original input order)
        sys.stdout.write(f"{i} {j} {max_cycle_len}\n")


if __name__ == "__main__":
    main()