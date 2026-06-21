# 10137 - The Trip

This folder contains a solution to the Online Judge problem number 10137: "The Trip" 

## Problem Description

A group of students goes on a trip, and each student spends a different amount of money.

The group agrees to share their individual expenses equally

The goal is to determine the minimum amount of money that must change hands so that everyone ends up having paid an equal share of the total expenses within a cent.

The challenges lie in handling monetary values correctly and accounting for rounding issues when dividing the total cost among students.

## Example

__Input:__
```
3
10.00
20.00
30.00
4
15.01
15.00
3.01
3.00
4
14.43
100.52
97.50
3.12
0
```
__Output:__
```
$10.00
$11.99
$90.23
```

Above is example input from the judge that lists the expenses of three separate trips. 

In the input, the whole numbers indicate the number of students in group on a trip. On the first trip, 3 students were in the group. On the second trip, 4 students were in the group. On the third trip, 4 students were in the group. The decimal numbers represent the total expenses for each student in that group.

The resulting output is the minumum amount of money that a student or students need to exchange so that they all pay equal or close to equal amounts down to the penny.

## Solution Approach

To successfully submit a solution to the judge, it is essential to correctly handle rounding, as not doing so will create floating-point precision errors.

Finding the correct monetary value in a group depends on the average amount of money spent per student. However, the number of students does not always divide evenly with the total money spent. This is where these errors can show up if not handled correctly

### 1. Convert spending amounts to integer cents

Avoiding floating-point values from the start is a beneficial first step.

This can be done by converting all monetary spending values into cents, turning the amounts into integers.

For example:

| Initial Amount | Integer Cents |
| :--- | :---: |
| 14.43 | 1443 |
| 100.52 | 10052 |
| 97.50 | 9750 |
| 3.12 | 312 |

### 2. Compute Average Expense

The next step is to compute the average amount spent per student. The average will be seen as the midpoint and will determine if students who spent above or below the average will owe money.

The solution would be simpler if the number of students always divides evenly with the total money spent. However, there will be situations where this is not the case, resulting in a floating-point number average. This situation has to be handled correctly, as students cannot give or take fractions of cents.

To handle this correctly, calculate and store the ceiling and floor of the average to the penny.

Let:
* total = total cents spent by all students
* n = number of students

First calculate the floor of the average, or low average:
* Low Average = total / n (floor)

Next, calculate the ceiling average, or high average:
* High Average = Low Average + 1 when there is a remainder

If the number of students divide evenly in the total amount spent, the floor and ceiling averages will be the same.

Continuing with the example: 1443 + 10052 + 9750 + 312 / 4 = 5389.25

Low Average = 5389
High average = 5390

### 3. Calculate Transfers

When determining the minimum amount of money that needs to be transferred, there is a particular process that must be followed for the solution to be accepted by the judge.

The average or averages calculated in the previous step can be seen as a midpoint.

The students can be then be catagorized into two groups: 
* Those who had expenses higher than the average, or those who need to give money to equalize costs
* Those who had expenses lower than the average, or those who need to take money to equalize costs

If any student had expenses that met the average, they are not considered.

Create two pools of money: the "give" pool and the "take" pool

For each student:
* If their spending exceeds the ceiling average, the excess contributes to the give pool.
* If their spending is below the floor average, the deficit contributes to the take pool.

Continuing to use the example above:

Low Average = 5389
High average = 5390

* Student 1 spent 1443 ->  Below floor average -> 5389 - 1443 = 3946 to take
* Student 2 spent 10052 -> Above ceiling average -> 10052 - 5390 = 4662 to give
* Student 3 spent 9750 -> Above ceiling average -> 9750 - 5390 = 4360 to give
* Student 3 spent 312 -> Below Floor average -> 5389 - 312 = 5077 to take

Give pool = 4662 + 4360 = 9022 or $90.22
Take pool = 3946 + 5077 = 9023 or $90.23

This method correctly accounts for rounding differences.

### 4. Find the maximum of the two values

The required exchange amount is: `max(give, take)`

Although we are finding the maximum between the two values, the larger of the total excess and deficit amounts represents the minimum exchange required to equalize expenses.

In the example:

max(9022, 9023) = 9023

Therefore, the correct amount and output for the example is $90.23.

## Complexity
### Time Complexity
__O(n)__ - Each student's expense is processed a constant number of times.
### Space Complexity
__O(n)__ - The individual expenses are stored in a list/array.

## Language-Specific Notes

* The C and C++ implementations read each expense as a floating-point value and convert it to cents using:
`static_cast<int>(amount * 100 + 0.5)` This rounds the value to the nearest cent before storing it as an integer.
* The Java and Python implementations avoid floating-point arithmetic entirely when reading input. Each monetary value is parsed as a string and split into a dollar portion and a cent portion. The value is then converted directly into integer cents.

## Files in the Folder
* C Solution: p10137.c
* C++ Solution: p10137.cpp
* Java Solution: p10137.java
* Python Solution: p10137.py
* Sample Input: p10137.txt

## Best Judge Run Times
* C Solution: 0.000 seconds
* C++ Solution: 0.000 seconds
* Java Solution: 0.040 seconds
* Python Solution: 0.010 seconds