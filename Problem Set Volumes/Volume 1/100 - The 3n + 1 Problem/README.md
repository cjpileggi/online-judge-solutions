# 100 - The 3n + 1 Problem

This folder contains a solution to the Online Judge problem number 100: "The 3n + 1 Problem" 

## Problem Description
The 3n + 1 problem (also known as the Collatz Conjecture) states that:
* For a given integer n, if n is even, divide it by 2.
* If n is odd, multiply it by 3 and add 1.
* Repeat the process for the resulting number until the value becomes 1.

The conjecure is that, starting with any integer n, applying this concept will always result in 1. Thus, a program running this will always successfully terminate.

It is unknown if the conjecture is true. However, the problem asks for you to work within a range of integers that has been verified to always result in 1.

The Online Judge asks for you to return the largest cycle length between all numbers within number ranges that the judge provides. The cycle length is the number of steps it takes for an integer n to reach 1 when applying the Collatz Conjecture to that number. For the judge, a cycle length also includes the original number.

### Example
For the input i = 1, j = 10, the output will show the largest cycle length for any number in that range.

__Input:__  
`1 10`  
__Output:__  
`1 10 20`  

In this example, the largest cycle length between 1 and 10 is 20.

The solution is obtained by finding the Collatz Conjecture cycle length of all numbers between 1 and 10, and finding which one has the largest cycle.

In this case, 9 has the largest cycle. Below are the the integers that the solution would process and count when appying the Collatz Conjecture to 9:

9-28-14-7-22-11-34-17-52-26-13-40-20-10-5-16-8-4-2-1

There are 20 integers in this cycle, and therefore should output 20.

## Solution Approach
* Memoization: The cycle length of a number is cached to avoid redundant calculations, which speeds up the computation for large inputs.
* Bitwise Calculations: Efficient calculations are performed using bitwise operators (&, >>), reducing time complexity for even numbers.
* Iterative Approach: The cycle length is computed iteratively to minimize function call overhead.

## Code Overview
* Memoization Cache: A static array cache[MAX + 1] stores the cycle lengths of numbers, avoiding redundant calculations.
* Iterative Process: The number is processed iteratively. For even numbers, the number is halved using the bitwise right shift operator. For odd numbers, the number is processed using the formula (3 * n + 1) >> 1 (which calculates 3n + 1 and then divides by 2 in one step).

## Key Functions
* cycle_length(unsigned int n): Computes the cycle length for a given integer n using memoization and bitwise operations.
* main(): Reads input pairs, computes the maximum cycle length in the given range, and prints the result.

## Files in the Folder
* C Solution: p100.c
* C++ Solution: p100.cpp
* Java Solution: p100.java
* Python Solution: p100.py
* Sample Input: p100.txt

## Best Judge Run Times
* C Solution: 0.000 seconds
* C++ Solution: 0.000 seconds
* Java Solution: 0.070 seconds
* Python Solution: 0.370 seconds

## License
This project is open source and available under the MIT License.

