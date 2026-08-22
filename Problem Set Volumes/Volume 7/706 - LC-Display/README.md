# UVa 706 — LC-Display

This folder contains a solution to the Online Judge problem number 706: "LC-Display" 


## Problem Description

The objective of this problem is to simulate the appearance of a digital LCD display using a seven-segment representation. This is similar to how numbers are represented on a digital clock.

### Analysing Input

Each row of input given by the judge will contain the following:

* `s` — the size of the display segments.
* `n` — the number to display.

A single input row would look like `s n`.

For every row of input, the judge expects a corresponding output.

Each digit in `n` is drawn using seven possible segments made up of dashes (`-`), vertical bars (`|`) or blank spaces for segments that certain digits don't have. The number of dashes, vertical bars and blank spaces used depends on the value of `s`.

### Output Structure

To demostrate the seven segments, below is the expected result if a line of input is `3 8`:


```text
 ---     - Top
|   |
|   |    - Upper-Middle (Upper-Left and Upper-Right)
|   |
 ---     - Middle
|   |
|   |    - Lower-Middle (Lower-Left and Lower-Right)
|   |
 ---     - Bottom
```
This will output a single digit 8. The 8 is broken down as follows:

* Top - the top of the digit made up of `s` dashes.
* Upper-Left - the left of the upper-middle section. Made up of `s` vertical lines.
* Upper-Right - the right of the upper-middle section. Made up of `s` vertical lines.
* Middle - the middle of the digit made up of `s` dashes.
* Lower-Left - the left of the lower-middle section. Made up of `s` vertical lines.
* Lower-Right - the right of the lower-middle section. Made up of `s` vertical lines.
* Bottom - the bottom of the digit made up of `s` dashes.


The top, middle and bottom segments can be viewed as horizontal segments and the upper-middle and lower-middle segments can be viewed as vertical segments.

The digit 8 happens to be a case where each segment is filled with the appropriate dashes or vertical bars. Other digits will have blank segments. How each digit will be printed needs considered in the output.  The example below will demonstrate which of the segments in each digit from 0 to 9 should be printed.  

Spaces and blank rows are also important to consider. Digits in the same output row are separated by one column of blank characters and a blank row is required between each row of input. 

Input processing continues until the terminating pair `0 0` is encountered.


### Example

The example below demostrates how the segments should be structured for all digits from 0 to 9:

__Input:__  
```text
2 12345
3 67890
0 0
```

__Output:__  
```text
      --   --        --
   |    |    | |  | |
   |    |    | |  | |
      --   --   --   --
   | |       |    |    |
   | |       |    |    |
      --   --        --

 ---   ---   ---   ---   ---
|         | |   | |   | |   |
|         | |   | |   | |   |
|         | |   | |   | |   |
 ---         ---   ---
|   |     | |   |     | |   |
|   |     | |   |     | |   |
|   |     | |   |     | |   |
 ---         ---   ---   ---
``` 
This first row indicates that the program should print 12345 and that each segment should contain 2 dashes or vertical bars.

The second row indicates that the program should print 67890 and that each  segment should contain 3 dashes or vertical bars.



## Solution Approach

This problem is primarily an exercise in **output formatting and simulation** rather than algorithmic complexity.

The important considerations are:

* Represent each digit using its seven segments
* Determine the structure of the display from the segment size
* Generate the display row by row
* Keep the rendering logic independent of input/output handling
* Carefully preserve spaces, separators, and blank lines


A solution does not necessarily need to construct each digit independently and then attempt to combine them. Instead, it can construct the output **one row at a time**.

This makes the solution layout straightforward:

1. Determine what type of row is being rendered
2. Render that row for every digit
3. Join the digit portions with one space
4. Add the completed row to the output

### Create the Digit Segment Map

First, create models of each digit using its respective seven-segment configuration.

Instead of continuously using a large `if` chain for every digit, a digit map provides a direct lookup from the digit value to its seven-segment configuration.

The seven segments are stored in their own array in the following order:

`[top, upper-left, upper-right, middle, lower-left, lower-right, bottom]`


For example:

```C++
// 0
[1, 1, 1, 0, 1, 1, 1]

// 1
[0, 0, 1, 0, 0, 1, 0]

// 8
[1, 1, 1, 1, 1, 1, 1]
```

A `1` means that the corresponding segment should be displayed, while a `0` means it should be replaced with spaces.

Create a two dimensional array containing these mappings for each digit from 0 to 9.

### Rendering


Any digit of size `s` always contains `2 * s + 3` rows. Regardless of the digit or digits in the output, they will all be structured as follows:

* 1 row for the top horizontal segment
* `s` rows for the upper vertical segments
* 1 row for the middle horizontal segment
* `s` rows for the lower vertical segments
* 1 row for the bottom horizontal segment

The challenge is to generate each of the `2 * s + 3` rows one at a time for each digit.

This can be accomplished by using a nested loop.

- For each row `r` in the range of 0 to `(2 * s + 3) - 1`, loop through all digits in the input.
- For each digit in the input, use the digit segment map and generate the appropriate segment characters.

How the row is structured depends on which segment it is a part of. Tha character that should be printed is determined by the value of `r` relative to `s`.

The five types of rows are:

```text
Top (dashes)                  r == 0
Upper-Middle (vertical bars)  1 <= r <= s
Middle (dashes)               r == s + 1
Lower-Middle (vertical bars)  s + 2 <= r <= 2*s + 1
Bottom (dashes)               r == 2*s + 2
```

Each rendered digit is joined with a single space to produce the complete row.


After the loop exits, each row of each digit in the input row will be printed. If there is another input row, a blank line will be printed and the same process will begin for the next row.

This repeats until `0 0` is the value of an input row.


## Complexity

Let:

* `s` be the segment size.
* `d` be the number of digits in the input number.

A rendered digit has `2s + 3` rows. For each row, the solution processes every digit, so the amount of output generated is proportional to:

```text
O(d * s)
```

Therefore, for one test case:

* **Time:** `O(d * s)`
* **Space:** `O(d * s)`

The space complexity includes the rendered output stored before printing.

This is essentially optimal because the solution must generate every character that appears in the LCD display.



## Language-Specific Notes

* Java uses a custom `FastScanner` for efficient input.

## Files in the Folder
* C Solution: p706.c
* C++ Solution: p706.cpp
* Java Solution: p706.java
* Python Solution: p706.py
* Sample Input: p706.txt

## Best Judge Run Times
* C Solution: 0.000 seconds
* C++ Solution: 0.010 seconds
* Java Solution: 0.180 seconds
* Python Solution: 0.040 seconds