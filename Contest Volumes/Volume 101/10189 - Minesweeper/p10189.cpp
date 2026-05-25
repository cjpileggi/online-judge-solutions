/*
* Online Judge: Problem 10189 - Minesweeper
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

// 8 neighboring directions
static constexpr short int dir_x[8] = {-1,-1,-1,0,0,1,1,1};
static constexpr short int dir_y[8] = {-1,0,1,-1,1,-1,0,1};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // If the program is not compiled by the judge, run locally using a test file
    #ifndef ONLINE_JUDGE
        if (freopen("p10189.txt", "r", stdin) == nullptr) {
            cerr << "Error: could not open file\n";
            return 1;
        }
    #endif

    // Keep track of the field number being processed
    // Required for output
    unsigned int field_cnt = 0;

    // Variables used for field dimensions
    unsigned short int n, m;

    // Variables used for neighboring cells
    unsigned short int n_row, n_col;
    

    // Process fields until input dimensions "0 0" are provided
    // or until the input ends
    while (true) {

        // Read the dimensions of the field
        cin >> n >> m; 

        // Field dimensions "0 0" indicate the end of input
        // Exit the loop if this is the case
        if (n == 0 && m == 0) {
            break;
        }

        // Initialize field vector
        // Store the field rows from the input
        vector<string> field(n);
        for (unsigned short int i = 0; i < n; ++i) {
            cin >> field[i];
        }

        // Create a grid with the same dimensions
        // Used to store counts of mines adjacent to the cells
        // Already initialized with zeros
        vector<string> result(n, string(m, '0'));

        // Traverse every cell in the field
        for (unsigned short int row_num = 0; row_num < n; row_num++) {
            for (unsigned short int col_num = 0; col_num < m; col_num++) {

                // If the current cell contains a mine,
                // update all valid neighboring cells
                if (field[row_num][col_num] == '*') {

                    // Keep mine in output
                    result[row_num][col_num] = '*';

                    // Check all 8 neighboring cells of current cell
                    for (unsigned short int d = 0; d < 8; d++) {
                        n_row = row_num + dir_x[d];
                        n_col = col_num + dir_y[d];

                        
                        // Ensure the neighbor cell being checked is within the field dimemsions and is not a mine
                        // Add 1 to the current value stored in the number grid
                        if (n_row >= 0 && n_row < n && n_col >= 0 && n_col < m && result[n_row][n_col] != '*') {
                            result[n_row][n_col]++;
                        }
                    }
                }
            }
        }

         // Print a blank line between consecutive fields after the first one
        if (field_cnt > 0) {
            cout << '\n';
        }

        // Increment the field count variable
        // Add the current field number to the final output
        cout << "Field #" << ++field_cnt << ":\n";

        // Print result by row
        for (const string& row : result) {
            cout << row << '\n';
        }
    }

    return 0;
}