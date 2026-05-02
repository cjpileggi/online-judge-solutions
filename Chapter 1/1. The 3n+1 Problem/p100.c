/*
* UVa Online Judge: Problem 100 - The 3n + 1 Problem 
*
* Origin: Programming Challenges (Skiena & Revilla): 1.6.1 The 3n + 1 Problem
*
* Judge Version: ANSI C 5.3.0 - GNU C Compiler with options: -lm -lcrypt -O2 -pipe -ansi -DONLINE_JUDGE
* Best Run Time: 0.000 Seconds
*
*/

#include <stdio.h>

/* Upper bound for caching cycle lengths */
#define MAX 1000000  

/* Cache to store already computed cycle lengths. */
/* cache[n] = cycle length of n (only stored if n <= MAX) */
static int cache[MAX + 1] = {0};

/*
 *  Compute the Collatz cycle length for integer n using:
 *   - Memoization (cache)
 *   - Iterative approach
 *   - Bitwise calculations
 */
int cycle_length(unsigned int n) {
    unsigned int original_n = n;  /* Save original input for caching */
    int length = 0;

    /* Continue until we reach 1 (end of Collatz sequence) */
    while (n != 1) {

        /* If we've already computed this value, reuse it and break the loop */
        /* This avoids recomputing large parts of the sequence */
        if (n <= MAX && cache[n]) {
            length += cache[n];
            break;
        }

        if (n & 1) {
            /* If n is Odd: */
            /* Calculate n = 3*n + 1 */
            /* Then Immediately divide the result by 2 since the result is always even */
            /* Final calulation: n = (3*n + 1)/2 (bitwise) */
            /* Increase cycle length by 2 */
            n = (3 * n + 1) >> 1;
            length += 2;
        } else {
            /* If n is Even: */
            /* Calculate: n = n/2 (bitwise) */
            n >>= 1;
            length++;
        }
    }

    /* If we reached 1 directly (not via cache), count the final step */
    if (n == 1)
        length++;

    /* Store result for reuse if less than the maximum  */
    if (original_n <= MAX)
        cache[original_n] = length;

    return length;
}

int main() {


    /* Local Test vs. Judge toggle */
    #ifndef ONLINE_JUDGE
        if (freopen("p100.txt", "r", stdin) == NULL) {
            fprintf(stderr, "Error: could not open file\n");
            return 1;
        }
    #endif

    int i, j;

    /* Store base case: cycle length of 1 is 1 */
    cache[1] = 1;

    /* Read input pairs until EOF (as required by UVA) */
    while (scanf("%d %d", &i, &j) == 2) {

        int start = i, end = j;

        /* Maintain numerical order of values (judge examples are sometimes not in numerical order) */
        if (start > end) {
            int tmp = start;
            start = end;
            end = tmp;
        }

        /* Remember the largest cycle within the current range */
        int max_cycle_len = 0;

        /* Compute cycle lengths for all numbers in range [i, j] */
        /* Store the highest */
        int k;
        for (k = start; k <= end; k++) {
            int len = cycle_length(k);
            if (len > max_cycle_len)
                max_cycle_len = len;
        }

        /* Output format to match judge's desired output (original input order) */
        printf("%d %d %d\n", i, j, max_cycle_len);
    }

    return 0;
}