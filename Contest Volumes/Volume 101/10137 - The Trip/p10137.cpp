/*
* Online Judge: Problem 10137 - The Trip
*
* Judge Version:
* - C++ 5.3.0 - GNU C++ Compiler with options: -lm -lcrypt -O2 -pipe -DONLINE_JUDGE
* - Best Run Time: 0.000 Seconds
*
* - C++11 5.3.0 - GNU C++ Compiler with options: -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE
* - Best Run Time: 0.000 Seconds
*
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // If the program is not compiled by the judge, run locally using a test file
    #ifndef ONLINE_JUDGE
        if (freopen("p10137.txt", "r", stdin) == nullptr) {
            cerr << "Error: could not open file\n";
            return 1;
        }
    #endif

    // Number of students in the group being evaluated
    int n;
 
    // Process student groups until a group count of "0" is provided
    while (true) {

        cin >> n;

        // If the number of students given is 0, break from the loop to end the program
        if (n == 0) {
            break;
        }

        // The amounts that each student in the group pays
        vector<int> amounts(n);

        // The total cents spent by all students
        int total = 0;

        // For each student, store each amount as cents to avoid issues with rounding floating-point numbers
        for (int i = 0; i < n; ++i) {
            double x;
            cin >> x;

            // Convert the dollar amount to cents
            // Add 0.5 to correctly round to the nearest integer
            amounts[i] = static_cast<int>(x * 100 + 0.5);

            // Add to total cents spent by all students
            total += amounts[i];
        }

        // Calculate the floor average of the total cents spent per student
        int low_avg = total / n;

        // If the floor average is not an integer, calculate the ceiling average (add 1 to the floor average)
        // Otherwise, use the floor average
        int high_avg = low_avg + (total % n ? 1 : 0);

        // The total amount of those whose expenses were above the ceiling average and need to give money to equalize costs
        int give = 0;

        // The total amount of those whose expenses were below the floor average and need to take money to equalize costs
        int take = 0;

        // Evaluate all student expenses
        for (int x : amounts) {

            // If the amount paid is higher than the ceiling average,
            //   subtract the ceiling average from the amount paid and add to the give total
            if (x > high_avg)
                give += x - high_avg;

            // If the amount paid is lower than the floor average,
            //   subtract the amount paid from the floor average and add to the take total
            else if (x < low_avg)
                take += low_avg - x;
        }

        // Print the largest of the total give and take values
        // Format as currency
        cout << "$"
             << fixed << setprecision(2)
             << max(give, take) / 100.0
             << '\n';
    }
}