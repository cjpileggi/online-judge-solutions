/*
* Online Judge: Problem 10033 - Interpreter
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

// Remove trailing '\r'
static void strip(string &s) {
    if (!s.empty() && s.back() == '\r') s.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // If the program is not compiled by the judge, run locally using a test file
    #ifndef ONLINE_JUDGE
        if (freopen("p10033.txt", "r", stdin) == nullptr) {
            cerr << "Error: could not open file\n";
            return 1;
        }
    #endif

    // Number of programs
    int T;
    string line;
    cin >> T;
    getline(cin, line);

    // For each program
    while (T--) {



        // Initialize registry
        // 10 registers, values always reduced modulo 1000
        int reg[10] = {0};
        
        // Initialize RAM for this program
        // 1000 RAM cells
        // The input program text is loaded starting at RAM index 0.
        int ram[1000] = {0};
        int ram_index = 0;

        /*
        // Read instruction lines until the next blank line or EOF
        while (getline(cin, line)) {
            if (line.empty()) break;
            
            // Convert the three ASCII digits into a single integer XYZ.
            // Each digit is '0'..'9' so subtracting '0' converts ASCII to a numeric digit.
            ram[ram_index++] = (line[0] - '0') * 100 + (line[1] - '0') * 10 + (line[2] - '0');
        }
        */

        // Skip blank lines before the program starts
        while (getline(cin, line)) {
            strip(line);
            if (!line.empty()) break;
        }

        // Read instruction lines until the next blank line
        while (!line.empty()) {
            // Each instruction is encoded in the first 3 characters as digits
            int inst = (line[0] - '0') * 100 + (line[1] - '0') * 10 + (line[2] - '0');
            ram[ram_index++] = inst;

            if (!getline(cin, line)) break;
            strip(line);
        }

        // Instruction pointer
        // Index into RAM
        int pointer = 0;
        
        // Count of instructions executed (for output)
        int executed = 0;

        while (true) {

            // Fetch instruction
            // Increase pointer to move to next instruction in the next loop iteration
            int inst = ram[pointer++];

            // Count instruction (include HALT)
            executed++;

            // Get instruction parts
            // Encoded Opcode
            int opcode = inst / 100;
            // Values
            int r1 = (inst / 10) % 10, r0 = inst % 10;

            // HALT: End program
            if (opcode == 1) break;

            // SET: Set r1 to value r0
            else if (opcode == 2) reg[r1] = r0;

            // ADD: Add value r0 to register r1. Reduce result modulo 1000
            else if (opcode == 3) reg[r1] = (reg[r1] + r0) % 1000;

            // MUL: Multiply value r0 with register r1. Assign to register r1. Reduce result modulo 1000
            else if (opcode == 4) reg[r1] = (reg[r1] * r0) % 1000;

            // MOV: Move register r1 to register r0
            else if (opcode == 5) reg[r1] = reg[r0];

            // ADDR: Add register r1 to register r0. Assign to register r1. Reduce result modulo 1000
            else if (opcode == 6) reg[r1] = (reg[r1] + reg[r0]) % 1000;

            // MULR: Multiply register r1 with register r0. Assign to register r1. Reduce result modulo 1000
            else if (opcode == 7) reg[r1] = (reg[r1] * reg[r0]) % 1000;

            // LD: Retrieve the value in RAM located at the address stored in register r0. Assign value to register r1
            else if (opcode == 8) reg[r1] = ram[reg[r0]];

            // ST: Set the value in RAM whose address is in register r0 to the value of register r1
            else if (opcode == 9) ram[reg[r0]] = reg[r1];

            // GOTO: assign the pointer to the value in register op1 unless register r0 contains 0
            else if (opcode == 0 && reg[r0] != 0) pointer = reg[r1];
        }

        // Print each output on its own line
        cout << executed << '\n';
        if (T) cout << '\n';
    }

    return 0;
}
