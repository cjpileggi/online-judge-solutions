/*
* Online Judge: Problem 706 - LC-Display 
*
* Judge Version: ANSI C 5.3.0 - GNU C Compiler with options: -lm -lcrypt -O2 -pipe -ansi -DONLINE_JUDGE
* Best Run Time: 0.000 Seconds
*
*/

#include <stdio.h>
#include <string.h>


/* Seven-segment representation for digits 0-9.
 Order of segments: top, upper-left, upper-right,
 middle, lower-left, lower-right, bottom */
static const int digit_map[10][7] = {
    {1,1,1,0,1,1,1}, /* 0 */
    {0,0,1,0,0,1,0}, /* 1 */
    {1,0,1,1,1,0,1}, /* 2 */
    {1,0,1,1,0,1,1}, /* 3 */
    {0,1,1,1,0,1,0}, /* 4 */
    {1,1,0,1,0,1,1}, /* 5 */
    {1,1,0,1,1,1,1}, /* 6 */
    {1,0,1,0,0,1,0}, /* 7 */
    {1,1,1,1,1,1,1}, /* 8 */
    {1,1,1,1,0,1,1}  /* 9 */
};

int main(void) {

    /* If the program is not compiled by the judge, run locally using a test file */
    #ifndef ONLINE_JUDGE
        if (freopen("p706.txt", "r", stdin) == NULL) {
            fprintf(stderr, "Error: could not open file\n");
            return 1;
        }
    #endif

    /* Display size */
    int s;

    /* Number to render */
    char n[100];

    /* Loop variables */
    int num, r, k;

    /* Read input pairs until EOF (as required by UVA) */
    while (scanf("%d %s", &s, n) == 2) {

        /* End of input */
        if (s == 0 && strcmp(n, "0") == 0) 
            break;

        /* Total number of rows in a digit of size s */
        int rows = 2 * s + 3;

        int n_len = (int)strlen(n);

        /* # Generate the display one row at a time */
        for (r = 0; r < rows; ++r) {

            /* Render each digit in the input number */
            for (num = 0; num < n_len; ++num) {

                /* Retrieve the seven-segment pattern for this digit */
                int d = n[num] - '0';

                /* Top horizontal segment */
                if (r == 0) {
                    putchar(' ');
                    for (k = 0; k < s; ++k) putchar(digit_map[d][0] ? '-' : ' ');
                    putchar(' ');

                /* Upper vertical segments */
                } else if (r > 0 && r <= s) {
                    putchar(digit_map[d][1] ? '|' : ' ');
                    for (k = 0; k < s; ++k) putchar(' ');
                    putchar(digit_map[d][2] ? '|' : ' ');

                /* Middle horizontal segment */
                } else if (r == s + 1) {
                    putchar(' ');
                    for (k = 0; k < s; ++k) putchar(digit_map[d][3] ? '-' : ' ');
                    putchar(' ');

                /* Lower vertical segments */
                } else if (r > s + 1 && r < rows - 1) {
                    putchar(digit_map[d][4] ? '|' : ' ');
                    for (k = 0; k < s; ++k) putchar(' ');
                    putchar(digit_map[d][5] ? '|' : ' ');
                
                /* Bottom horizontal segment */
                } else {
                    putchar(' ');
                    for (k = 0; k < s; ++k) putchar(digit_map[d][6] ? '-' : ' ');
                    putchar(' ');
                }

                /* Space between digits */
                if (num + 1 < n_len) putchar(' ');
            }
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}