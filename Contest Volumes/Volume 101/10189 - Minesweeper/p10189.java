/*
* Online Judge: Problem 10189 - Minesweeper
*
* Judge Version: JAVA 1.8.0 - OpenJDK Java
* Best Run Time: 0.040 Seconds
*
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
//import java.io.FileInputStream;
//import java.io.File;

public class Main {

    // All 8 possible neighboring positions around a cell:
    // top-left, top, top-right, left, right, bottom-left, bottom, bottom-right
    static final int[] dir_x = {-1,-1,-1,0,0,1,1,1};
    static final int[] dir_y = {-1,0,1,-1,1,-1,0,1};

    public static void main(String[] args) throws Exception {

        // For local testing with a text file including sample input
        // Uncomment to use local testing
        /*File testFile = new File("p10189.txt");
        if (testFile.exists()) {
            System.setIn(new FileInputStream(testFile));
        } */
        

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();

        
        // Keep track of the field number being processed
        // Required for output
        int field_cnt = 0;

        // Variables used for field dimensions
        int n, m;

        // Variables used for neighboring cells
        int n_row, n_col;
        
        // Variable for input line
        String line;

        // Process fields until input dimensions "0 0" are provided
        while (true) {
            line = br.readLine().trim();

            // Read the dimensions of the field
            String[] parts = line.split("\\s+");
            n = Integer.parseInt(parts[0]);
            m = Integer.parseInt(parts[1]);

            // Field dimensions "0 0" indicate the end of input
            // Exit the loop if this is the case
            if (n == 0 && m == 0) {
                break;
            }

            // Initialize field array
            char[][] field = new char[n][m];

            // Create a grid with the same dimensions
            // Used to store counts of mines adjacent to the cells
            // Already initialized with zeros
            int[][] counter = new int[n][m];

           
            // Store the field from the input
            for (int i = 0; i < n; i++) {
                
                char[] row = br.readLine().toCharArray();
               
                for (int j = 0; j < m; j++) {
                    field[i][j] = row[j];
                }
            }


            // Traverse every cell in the field
            for (int row_num = 0; row_num < n; row_num++) {

                for (int col_num = 0; col_num < m; col_num++) {

                    // If the current cell contains a mine,
                    // update all valid neighboring cells
                    if (field[row_num][col_num] == '*') {

                        // Check all 8 neighboring cells of current cell
                        for (int d = 0; d < 8; d++) {
                            n_row = row_num + dir_x[d];
                            n_col = col_num + dir_y[d];

                            // Ensure the neighbor cell being checked is within the field dimemsions and is not a mine
                            // Add 1 to the current value stored in the number grid
                            if (0 <= n_row && n_row < n && 0 <= n_col && n_col < m && field[n_row][n_col] != '*') {
                                counter[n_row][n_col]++;
                            }
                        }
                    }                
                }
            }

            // Print a blank line between consecutive fields after the first one
            if (field_cnt > 0) {
                out.append('\n');
            }   

            // Increment the field count variable
            // Add the current field number to the final output
            out.append("Field #").append(++field_cnt).append(":\n");


            // Build final field
            // Use both field and counter arrays
            // Mines remain '*'
            // Empty cells become their adjacent mine count instead of '.'
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (field[i][j] == '*') {
                        out.append('*');
                    } else {
                        out.append(counter[i][j]);
                    }
                }
                out.append('\n');
            }
        }
        System.out.print(out.toString());
    }
}