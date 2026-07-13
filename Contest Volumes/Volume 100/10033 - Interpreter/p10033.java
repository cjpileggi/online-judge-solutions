/*
* Online Judge: Problem 10033 - Interpreter
*
* Judge Version: JAVA 1.8.0 - OpenJDK Java
* Best Run Time: 0.040 Seconds
*
*/

import java.io.*;
import java.util.*;

public class Main {

    // Removes trailing newline ('\n') and carriage return ('\r') characters from a string in place
    static String strip(String s) {

        // Get the current length of the string 
        int n = s.length();

        // Replace any trailing newline or carriage return characters with the null terminator
        // Work backwards until a non-newline character is found or the string
        while (n > 0) {
            char c = s.charAt(n - 1);
            if (c == '\n' || c == '\r') n--;
            else break;
        }
        return s.substring(0, n);
    }

    public static void main(String[] args) throws Exception {

        
        // For local testing with a text file including sample input
        // Uncomment to use local testing
        /*File testFile = new File("p10033.txt");
        if (testFile.exists()) {
            System.setIn(new FileInputStream(testFile));
        }*/

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String first = br.readLine();

        // Reached EOF
        if (first == null) return;

        // Number of programs
        int T = Integer.parseInt(first.trim());

        // Output string
        StringBuilder out = new StringBuilder();

        // For each program
        for (int tc = 0; tc < T; tc++) {

            // Initialize registry
            // 10 registers, values always reduced modulo 1000
            int[] reg = new int[10];

                    
            // Initialize RAM for this program
            // 1000 RAM cells
            // The input program text is loaded starting at RAM index 0.
            int[] ram = new int[1000];
            int ram_index = 0;

            // Skip any blank lines before the program starts
            String line;
            do {
                line = br.readLine();
                if (line == null) break;
                line = strip(line);
            } while (line.isEmpty());

            // Convert the three ASCII digits into a single integer XYZ.
            // Each digit is '0'..'9' so subtracting '0' converts ASCII to a numeric digit.
            while (line != null && !line.isEmpty()) {
                ram[ram_index++] = (line.charAt(0) - '0') * 100 +
                           (line.charAt(1) - '0') * 10 +
                           (line.charAt(2) - '0');
                line = br.readLine();
                if (line != null) line = strip(line);
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
            out.append(executed).append('\n');
            if (tc + 1 < T) out.append('\n');
        }

        System.out.print(out.toString());
    }
}
