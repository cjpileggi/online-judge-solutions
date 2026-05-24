# 10189 - Minesweeper

This folder contains a solution to the Online Judge problem number 10189: "Minesweeper" 

## Problem Description

Minesweeper is a puzzle game that was included with older versions of Microsoft Windows.

The game consists of a grid, or field, of hidden squares. When a player reveals a square, one of three things appears:

* a mine
* a number, or
* an empty space 

If a mine is revealed, the player loses the game. 

If a number is revealed, it indicates how many mines are located in the adjacent squares relative to the revealed number. Each square can have up to eight neighboring squares:

* top-left
* top
* top-right
* left
* right
* bottom-left
* bottom
* bottom-right

Therefore, the numbers range from 1 to 8.

If an empty square is revealed, it means that there are no mines in any adjacent squares.

The objective of the game is to reveal every square that does not contain a mine while avoiding those that do. Players use the revealed numbers as clues to determine which squares are safe and which contain mines. 

In this problem, the Online Judge provides one or more sets of characters as input to represent Minesweeper fields.

The input begins with two integers representing the dimensions of the field. The following lines contain a representation of the field itself, where:
* `*` represents a mine 
* `.` represents an empty square

The task is to generate the completed field by replacing each empty square with a number that represents the number of mines adjacent to that square. That field is then submitted as output.

The judge will continue to provide different Minesweeper fields until the dimensions `0 0` are provided. This indicates the end of the judge's input and the program can end.


### Example

__Input:__  
```
4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0
```
__Output:__  
```
Field #1:
*100
2210
1*10
1110

Field #2:
**100
33200
1*100
``` 

The example above represents two minesweeper fields that the Online Judge can provide from input. One field has four rows and four columns and the other has three rows and five columns. 

For the output, the empty squares are replaced with numbers that represent the number of mines adjacent to them. Squares without any neighboring mines are given a 0. Squares that contain mines remain the same.

The field number that the judge provides must be above the resulting output of each field.


## Solution Approach

The solution uses a straightforward grid traversal algorithm:

1. Read the field dimensions.
2. Store the grid.
3. Traverse every square.
4. For every mine (`*`):
   * Visit all 8 neighboring positions.
   * Increment the counter for valid non-mine neighbors.
5. Build the final output grid.

The neighboring positions are represented using two direction arrays:

__Neighbor Direction Vectors__

```
(-1,-1) (-1,0) (-1,1)
( 0,-1)         ( 0,1)
( 1,-1) ( 1,0) ( 1,1)
```

This allows compact and efficient neighbor traversal.


## Key Implementation Details

### Boundary Checking

The solution must also account for squares that represent corners or are on the edges of the field. This is because these squares do not have all 8 neighboring squares and incorrectly traversing non-existing squares may cause an error.

Before updating a neighboring square, the solution verifies that the position is inside the field:

```java
if (0 <= n_row && n_row < n &&
    0 <= n_col && n_col < m &&
    field[n_row][n_col] != '*')
```

This prevents invalid memory access and avoids modifying mine square.

## Time Complexity

For a field of size `n × m`:

* Every cell is visited once.
* Each mine checks at most 8 neighbors.

Overall complexity:

```
O(n × m)
```

Space complexity:

```
O(n × m)
```

## Language-Specific Notes

### C

* Uses static arrays.
* Avoids recreating arrays between test cases to reduce memory allocations.

### C++

* Uses `vector` containers for cleaner memory management.


### Python

* Reads the entire input at once instead of line-by-line processing.
* Uses list comprehension when creating lists.
* The direction arrays are replaced with a tuple of eight tuples, each representing a direction.


## Files in the Folder
* C Solution: p10189.c
* C++ Solution: p10189.cpp
* Java Solution: p10189.java
* Python Solution: p10189.py
* Sample Input: p10189.txt

## Best Judge Run Times
* C Solution: 0.000 seconds
* C++ Solution: 0.000 seconds
* Java Solution: 0.040 seconds
* Python Solution: 0.010 seconds