/*
* Online Judge: Problem 706 - LC-Display
*
* Judge Version: JAVA 1.8.0 - OpenJDK Java
* Best Run Time: 0.180 Seconds
*
*/


import java.io.*;
import java.util.*;

/* Seven-segment representation for digits 0-9.
 Order of segments: top, upper-left, upper-right,
 middle, lower-left, lower-right, bottom */
public class Main {
    static final int[][] DIGIT_MAP = {
        {1,1,1,0,1,1,1}, // 0
        {0,0,1,0,0,1,0}, // 1
        {1,0,1,1,1,0,1}, // 2
        {1,0,1,1,0,1,1}, // 3
        {0,1,1,1,0,1,0}, // 4
        {1,1,0,1,0,1,1}, // 5
        {1,1,0,1,1,1,1}, // 6
        {1,0,1,0,0,1,0}, // 7
        {1,1,1,1,1,1,1}, // 8
        {1,1,1,1,0,1,1} // 9
    };

    public static void main(String[] args) throws Exception {

        // For local testing with a text file including sample input
        // Uncomment to use local testing
        // File testFile = new File("p706.txt");
        //if (testFile.exists()) {
        //    System.setIn(new FileInputStream(testFile));
        //}

        FastScanner fs = new FastScanner(System.in);
        StringBuilder out = new StringBuilder();


        while (true) {
            Integer sObj = fs.nextInt();
            //if (sObj == null) break;

            // Display size
            int s = sObj;

            // Number to render
            String n = fs.next();
            
            // End of input
            if (s == 0 && "0".equals(n)) break;

            // Total number of rows in a digit of size s
            int rows = 2 * s + 3;

            // Generate the display one row at a time
            for (int r = 0; r < rows; r++) {

                // Render each digit in the input number
                for (int num = 0; num < n.length(); num++) {

                    // Retrieve the seven-segment pattern for this digit
                    int d = n.charAt(num) - '0';

                    // Top horizontal segment
                    if (r == 0) {
                        out.append(' ');
                        for (int k = 0; k < s; k++) out.append(DIGIT_MAP[d][0] == 1 ? '-' : ' ');
                        out.append(' ');
                    // Upper vertical segments
                    } else if (r <= s) {
                        out.append(DIGIT_MAP[d][1] == 1 ? '|' : ' ');
                        for (int k = 0; k < s; k++) out.append(' ');
                        out.append(DIGIT_MAP[d][2] == 1 ? '|' : ' ');
                    // Middle horizontal segment
                    } else if (r == s + 1) {
                        out.append(' ');
                        for (int k = 0; k < s; k++) out.append(DIGIT_MAP[d][3] == 1 ? '-' : ' ');
                        out.append(' ');
                    // Lower vertical segments 
                    } else if (r < rows - 1) {
                        out.append(DIGIT_MAP[d][4] == 1 ? '|' : ' ');
                        for (int k = 0; k < s; k++) out.append(' ');
                        out.append(DIGIT_MAP[d][5] == 1 ? '|' : ' ');
                    // Bottom horizontal segment
                    } else {
                        out.append(' ');
                        for (int k = 0; k < s; k++) out.append(DIGIT_MAP[d][6] == 1 ? '-' : ' ');
                        out.append(' ');
                    }
                    // Space between digits
                    if (num + 1 < n.length()) out.append(' ');
                }
                out.append('\n');
            }
            out.append('\n');
        }

        System.out.print(out.toString());
    }

    // Implement fast scanner for input
    static class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;

        FastScanner(InputStream is) {
            this.in = is;
        }

        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }

        Integer nextInt() throws IOException {
            int c;
            do {
                c = read();
            } while (c <= ' ' && c != -1);
            if (c == -1) return null;

            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }

            int val = 0;
            while (c > ' ') {
                val = val * 10 + (c - '0');
                c = read();
            }
            return val * sign;
        }

        String next() throws IOException {
            int c;
            do {
                c = read();
            } while (c <= ' ' && c != -1);
            if (c == -1) return null;

            StringBuilder sb = new StringBuilder();
            while (c > ' ') {
                sb.append((char)c);
                c = read();
            }
            return sb.toString();
        }
    }
}
