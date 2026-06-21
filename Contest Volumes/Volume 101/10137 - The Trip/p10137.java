/*
* Online Judge: Problem 10137 - The Trip
*
* Judge Version: JAVA 1.8.0 - OpenJDK Java
* Best Run Time: 0.070 Seconds
*
*/


import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {

        // For local testing with a text file including sample input
        // Uncomment to use local testing
        /*File testFile = new File("p10137.txt");
        if (testFile.exists()) {
            System.setIn(new FileInputStream(testFile));
        } */


        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Number of students in the group being evaluated
        int n;

        // Process student groups until a group count of "0" is provided
        while (true) {

            
            n = Integer.parseInt(br.readLine());

            // If the number of students given is 0, break from the loop to end the program
            if (n == 0)
                break;

            // The amounts that each student in the group pays
            int[] amounts = new int[n];

            // The total cents spent by all students
            int total = 0;

            // For each student, store each amount as cents to avoid issues with rounding floating-point numbers
            for (int i = 0; i < n; i++) {
                String s = br.readLine();

                // Split the amount into dollars and cents
                String[] p = s.split("\\.");

                // Convert the dollar amount to cents and add the original cents value
                int new_amount = Integer.parseInt(p[0]) * 100 + Integer.parseInt(p[1]);
                
                // Add converted amount to array
                amounts[i] = new_amount;

                // Add to total cents spent by all students
                total += new_amount;
            }

            // Calculate the floor average of the total cents spent per student
            int low_avg = total / n;

            // If the floor average is not an integer, calculate the ceiling average (add 1 to the floor average)
            // Otherwise, use the floor average
            int high_avg = low_avg + (total % n == 0 ? 0 : 1);

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
            int ans = Math.max(give, take);
            System.out.printf("$%.2f%n", ans / 100.0);
        }
    }
}