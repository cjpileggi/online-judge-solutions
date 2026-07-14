# 10033 - Interpreter

This folder contains a solution to the Online Judge problem number 10033: "Interpreter" 

## Problem Description

The objective of this problem is to simulate a basic computer that has the ability to read instructions and properly utilize limited memory based on those instructions. 

The computer should be built to have:

- **10 registers** (`0` to `9`)
- **1000 RAM cells** (`0` to `999`)

Using those resources, the Online Judge expects the simulated computer to be able to read instructions from the input, which are encoded as **3-digit numbers**:

Each instruction is interpreted as:

- first digit = opcode
- second digit = register / operand 1
- third digit = register / operand 2 or immediate value


The opcode determines one of 10 operations that the Judge describes in the program description:

| Instruction | Meaning |
|------------|---------|
| `100` | Halt |
| `2dn` | Set register `d` to `n` |
| `3dn` | Add `n` to register `d` |
| `4dn` | Multiply register `d` by `n` |
| `5ds` | Copy register `s` into register `d` |
| `6ds` | Add register `s` to register `d` |
| `7ds` | Multiply register `d` by register `s` |
| `8da` | Load RAM value at address in register `a` into register `d` |
| `9sa` | Store register `s` into RAM address in register `a` |
| `0ds` | Jump to instruction in register `d` if register `s` is not zero |

All register values are kept modulo `1000`.

The Judge will provide one or more sets of instructions. One set of instructions is considered to be one program. The number of programs the Judge provides is given at the start of the input.

These sets are separated by blank lines in the input and program runs until it executes the Halt instruction. Even if there are more instructions in a program after Halt is reached, they should be ignored.

The goal is to count how many instructions are executed for each program provided in the input before reaching and while including the halt instruction. 


## Example

__Input:__
```
2

299
492
495
399
492
495
399
283
279
689
078
100
000
000
000

221
422
425
000
311
712
712
913
031
```
__Output:__
```
16

10
```

The starting digit 2 tells us that the Judge is going to provide two programs, which means we are required to provide 2 outputs. If the solution reads the instructions correctly, it should execute 16 instructions in the first program and 10 in the second. The outputs must be on their own lines.

Take note that the second set of instructions does not have a Halt instruction. That's because instructions are not limited to what is provided in the input. Some instruction may create additional instructions in RAM, including `100`. 

## Solution Approach

The approach to solving this problem is straightforward:

1. Read the number of programs/sets of instructions.
2. For each program:
   1. reset all registers and RAM
   2. read the program into RAM starting from address `0`. Blank lines and return characters must be handled correctly or the final output may be incorrect.
   3. execute instructions using an instruction pointer
   4. Decode each instruction into:
        - opcode
        - operand 1
        - operand 2
   5. Apply the instruction logic.
   6. Stop when opcode `1` (`100`) is encountered.
3. Count and print all executed instructions.


## Complexity

### Time Complexity

__O(n)__ - `n` being the number of executed instructions

### Space Complexity
__O(1)__ 

The memory usage is constant because the problem always uses:

- 10 registers
- 1000 RAM cells


## Language-Specific Notes

* Python does not use a strip() function to remove trailing newline ('\n') and carriage return ('\r') characters. 

## Files in the Folder
* C Solution: p10033.c
* C++ Solution: p10033.cpp
* Java Solution: p10033.java
* Python Solution: p10033.py
* Sample Input: p10033.txt

## Best Judge Run Times
* C Solution: 0.000 seconds
* C++ Solution: 0.000 seconds
* Java Solution: 0.040 seconds
* Python Solution: 0.000 seconds