/*
* UVa Online Judge: Problem 100 - The 3n + 1 Problem 
*
* Origin: Programming Challenges (Skiena & Revilla): 1.6.1 The 3n + 1 Problem
*
* Judge Version: JAVA 1.8.0 - OpenJDK Java
* Best Run Time: 0.070 Seconds
*
*/

import java.io.*;
import java.util.*;

public class Main {

    // Upper bound for caching cycle lengths
    static final int MAX = 1000000;

    // Cache to store already computed cycle lengths.
    // cache[n] = cycle length of n (only stored if n <= MAX)
    static int[] cache = new int[MAX + 1];

    public static void main(String[] args) throws Exception {

        // Local Test vs. Judge toggle
        File testFile = new File("p100.txt");
        if (testFile.exists()) {
            System.setIn(new FileInputStream(testFile));
        }

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        // Store base case: cycle length of 1 is 1
        cache[1] = 1;

        String line;
        while ((line = br.readLine()) != null && !line.trim().isEmpty()) {

            // Read values
            StringTokenizer st = new StringTokenizer(line);
            int i = Integer.parseInt(st.nextToken());
            int j = Integer.parseInt(st.nextToken());

            // Maintain numerical order of values (judge examples are sometimes not in numerical order)
            int start = Math.min(i, j);
            int end = Math.max(i, j);

            // Remember the largest cycle within the current range
            int max_cycle_len = 0;

            // Compute cycle lengths for all numbers in range [i, j]
            // Store the highest
            for (int a = start; a <= end; a++) {
                max_cycle_len = Math.max(max_cycle_len, cycle_length(a));
            }

            // Output format to match judge's desired output (original input order)
            sb.append(i).append(" ").append(j)
              .append(" ").append(max_cycle_len).append("\n");
        }

        System.out.print(sb);
    }

    /*
    *  Compute the Collatz cycle length for integer n using:
    *   - Memoization (cache)
    *   - Iterative approach
    *   - Bitwise calculations
    */
    static int cycle_length(long n) {
        long original_n = n; // Save original input for caching
        int length = 0;


        while (n != 1) {

            // If we've already computed this value, reuse it and break the loop
            // This avoids recomputing large parts of the sequence
            if (n <= MAX && cache[(int) n] != 0) {
                length += cache[(int) n];
                break;
            }


            // Apply Collatz rule
            if ((n & 1) == 1) {
                // If n is Odd:
                // Calculate n = 3*n + 1
                // Then Immediately divide the result by 2 since the result is always even
                // Final calulation: n = (3*n + 1)/2 (bitwise)
                // Increase cycle length by 2
                n = (3 * n + 1) >> 1;
                length += 2;
            } 
            else {
                // If n is Even:
                // Calculate: n = n/2 (bitwise)
                n = n >> 1;
                length++;
            }
        }

        // If we reached 1 directly (not via cache), count the final step
        if (n == 1) {
            length++;
        }

        // Store result for reuse if less than the maximum 
        if (original_n <= MAX) {
            cache[(int) original_n] = length;
        }

        return length;
    }


}