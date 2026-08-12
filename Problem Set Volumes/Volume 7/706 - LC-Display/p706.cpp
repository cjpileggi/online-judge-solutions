/*
* Online Judge: Problem 706 - LC-Display 
*
* Judge Version:
* - C++ 5.3.0 - GNU C++ Compiler with options: -lm -lcrypt -O2 -pipe -DONLINE_JUDGE
* - Best Run Time: 0.010 Seconds
*
* - C++11 5.3.0 - GNU C++ Compiler with options: -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE
* - Best Run Time: 0.010 Seconds
*
*/

#include <bits/stdc++.h>
using namespace std;

/* Seven-segment representation for digits 0-9.
 Order of segments: top, upper-left, upper-right,
 middle, lower-left, lower-right, bottom */
static const int digit_map[10][7] = {
    {1,1,1,0,1,1,1}, // 0
    {0,0,1,0,0,1,0}, // 1
    {1,0,1,1,1,0,1}, // 2
    {1,0,1,1,0,1,1}, // 3
    {0,1,1,1,0,1,0}, // 4
    {1,1,0,1,0,1,1}, // 5
    {1,1,0,1,1,1,1}, // 6
    {1,0,1,0,0,1,0}, // 7
    {1,1,1,1,1,1,1}, // 8
    {1,1,1,1,0,1,1}  // 9
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    // If the program is not compiled by the judge, run locally using a test file
    #ifndef ONLINE_JUDGE
        if (freopen("p706.txt", "r", stdin) == nullptr) {
            cerr << "Error: could not open file\n";
            return 1;
        }
    #endif


    // Display size
    int s;

    // Number to render
    string n;

    // Process test cases until the terminating pair "0 0" is encountered
    while (true) {

        cin >> s >> n;

        // End of input
        if (s == 0 && n == "0") break;

        // Total number of rows in a digit of size s
        int rows = 2 * s + 3;

        // Generate the display one row at a time
        for (int r = 0; r < rows; ++r) {

            // Render each digit in the input number
            for (int num = 0; num < (int)n.size(); ++num) {

                // Retrieve the seven-segment pattern for this digit
                int d = n[num] - '0';

                // Top horizontal segment
                if (r == 0) {
                    cout << ' ' << string(s, digit_map[d][0] ? '-' : ' ') << ' ';
                } 
                // Upper vertical segments
                else if (r <= s) {
                    cout << (digit_map[d][1] ? '|' : ' ') << string(s, ' ') << (digit_map[d][2] ? '|' : ' ');
                } 
                // Middle horizontal segment
                else if (r == s + 1) {
                    cout << ' ' << string(s, digit_map[d][3] ? '-' : ' ') << ' ';
                } 
                // Lower vertical segments 
                else if (r < rows - 1) {
                    cout << (digit_map[d][4] ? '|' : ' ') << string(s, ' ') << (digit_map[d][5] ? '|' : ' ');
                } 
                // Bottom horizontal segment
                else {
                    cout << ' ' << string(s, digit_map[d][6] ? '-' : ' ') << ' ';
                }

                // Space between digits
                if (num + 1 < (int)n.size()) cout << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}