/*
* Online Judge: Problem 100 - The 3n + 1 Problem 
*
* Judge Version:
* - C++ 5.3.0 - GNU C++ Compiler with options: -lm -lcrypt -O2 -pipe -DONLINE_JUDGE
* - Best Run Time: 0.000 Seconds
*
* - C++11 5.3.0 - GNU C++ Compiler with options: -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE
* - Best Run Time: 0.000 Seconds
*
*/

#include <bits/stdc++.h>
using namespace std;

// Upper bound for caching cycle lengths
constexpr unsigned int MAX = 1000000u;

// Cache to store already computed cycle lengths.
// cache[n] = cycle length of n (only stored if n <= MAX)
static vector<int> cache(MAX + 1, 0);


/*
 *  Compute the Collatz cycle length for integer n using:
 *   - Memoization (cache)
 *   - Iterative approach
 *   - Bitwise calculations
 */
int cycle_length(unsigned int n) {
    unsigned int original_n = n; // Save original input for caching
    int length = 0;


    while (n != 1) {

        // If we've already computed this value, reuse it and break the loop
        // This avoids recomputing large parts of the sequence  
        if (n <= MAX && cache[n]) {
            length += cache[n];
            break;
        }

        if (n & 1u) {
            // If n is Odd:
            // Calculate n = 3*n + 1
            // Then Immediately divide the result by 2 since the result is always even
            // Final calulation: n = (3*n + 1)/2 (bitwise)
            // Increase cycle length by 2
            n = (3u * n + 1u) >> 1u;
            length += 2;
        } else {
            // If n is Even:
            // Calculate: n = n/2 (bitwise)
            n >>= 1u;
            length++;
        }
    }

    // If we reached 1 directly (not via cache), count the final step
    if (n == 1)
        length++;

    // Store result for reuse if less than the maximum 
    if (original_n <= MAX)
        cache[original_n] = length;

    return length;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Local Test vs. Judge toggle
    #ifndef ONLINE_JUDGE
        if (freopen("p100.txt", "r", stdin) == nullptr) {
            cerr << "Error: could not open file\n";
            return 1;
        }
    #endif

    int i, j;

    // Store base case: cycle length of 1 is 1
    cache[1] = 1;

    // Maintain numerical order of values (judge examples are sometimes not in numerical order)
    while (cin >> i >> j) {
        int start = i, end = j;
        if (start > end) swap(start, end);

        // Remember the largest cycle within the current range
        int max_cycle_len = 0;

        // Compute cycle lengths for all numbers in range [i, j]
        // Store the highest
        for (int k = start; k <= end; ++k) {
            int len = cycle_length(static_cast<unsigned int>(k));
            if (len > max_cycle_len) max_cycle_len = len;
        }

        // Output format to match judge's desired output (original input order)
        cout << i << ' ' << j << ' ' << max_cycle_len << '\n';
    }

    return 0;
}
