"""
Online Judge: Problem 10033 - Interpreter

Judge Version: PYTH3 3.5.1 - Python 3
Best Run Time: 0.000 Seconds

"""

import sys

def main():

    # For local testing with a text file including sample input
    # Uncomment to use local testing
    # if sys.stdin.isatty():
    #    sys.stdin = open("p10033.txt", "r")



    # Read all input as raw bytes; we treat each program as a block of non-empty lines
    # separated by one or more blank lines.
    lines = sys.stdin.buffer.read().splitlines()

    # Number of programs
    t = int(lines[0])

    # Cursor keep track of position in file
    cursor = 1 

    # For output
    results = []

    # For each program
    while t:

        # Initialize registry
        # 10 registers, values always reduced modulo 1000
        reg = [0] * 10

        # Initialize RAM for this program
        # 1000 RAM cells
        # The input program text is loaded starting at RAM index 0.
        ram = [0] * 1000
        ram_index = 0

        # Skip any blank lines before the program starts
        while cursor < len(lines) and lines[cursor].strip() == b'':
            cursor += 1

        # Read instruction lines until the next blank line or EOF
        while cursor < len(lines) and lines[cursor].strip() != b'':
            line = lines[cursor]

            # Convert the three ASCII digits into a single integer XYZ.
            # Each digit is '0'..'9' so subtracting 48 converts ASCII to a numeric digit.
            ram[ram_index] = (line[0] - 48) * 100 + (line[1] - 48) * 10 + (line[2] - 48)

            ram_index += 1
            cursor += 1

        # Move cursor past blank lines after the program block
        while cursor < len(lines) and lines[cursor].strip() == b'':
            cursor += 1

        # Instruction pointer
        # Index into RAM
        pointer = 0

        # Count of instructions executed (for output)
        executed = 0
        
        while True:
            # Fetch instruction
            inst = ram[pointer]

            # Move to next instruction
            pointer += 1

            # Count instruction (include HALT)
            executed += 1

            # Get instruction parts
            # Encoded Opcode
            opcode = inst // 100
            # Values
            r1 = (inst // 10) % 10
            r0 = inst % 10

            
            # HALT: End program
            if opcode == 1:
                break

            # SET: Set r1 to value r0
            elif opcode == 2:
                reg[r1] = r0

            # ADD: Add value r0 to register r1. Reduce result modulo 1000
            elif opcode == 3:
                reg[r1] = (reg[r1] + r0) % 1000

            # MUL: Multiply value r0 with register r1. Assign to register r1. Reduce result modulo 1000
            elif opcode == 4:
                reg[r1] = (reg[r1] * r0) % 1000

            # MOV: Move register r1 to register r0
            elif opcode == 5:
                reg[r1] = reg[r0]

            # ADDR: Add register r1 to register r0. Assign to register r1. Reduce result modulo 1000
            elif opcode == 6:
                reg[r1] = (reg[r1] + reg[r0]) % 1000

            # MULR: Multiply register r1 with register r0. Assign to register r1. Reduce result modulo 1000
            elif opcode == 7:
                reg[r1] = (reg[r1] * reg[r0]) % 1000

            # LD: Retrieve the value in RAM located at the address stored in register r0. Assign value to register r1
            elif opcode == 8:
                reg[r1] = ram[reg[r0]]

            # ST: Set the value in RAM whose address is in register r0 to the value of register r1
            elif opcode == 9:
                ram[reg[r0]] = reg[r1]

            # GOTO: assign the pointer to the value in register op1 unless register r0 contains 0
            elif opcode == 0 and reg[r0] != 0:
                pointer = reg[r1]

        results.append(str(executed))

        t -= 1

    # Print each output on its own line
    sys.stdout.write("\n\n".join(results) + "\n")

if __name__ == "__main__":
    main()