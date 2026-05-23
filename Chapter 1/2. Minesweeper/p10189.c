/*
* Online Judge: Problem 10189 - Minesweeper
*
* Judge Version: ANSI C 5.3.0 - GNU C Compiler with options: -lm -lcrypt -O2 -pipe -ansi -DONLINE_JUDGE
* Best Run Time: 0.000 Seconds
*
*/


#include <stdio.h>

#define MAX 100

/*  8 neighboring directions */
static short int dir_x[8] = {-1,-1,-1,0,0,1,1,1};
static short int dir_y[8] = {-1,0,1,-1,1,-1,0,1};

int main() {

    /* If the program is not compiled by the judge, run locally using a test file */
    #ifndef ONLINE_JUDGE
        if (freopen("p10189.txt", "r", stdin) == NULL) {
            fprintf(stderr, "Error: could not open file\n");
            return 1;
        }
    #endif

    /* Keep track of the field number being processed */
    /* Required for output */
    unsigned int field_cnt = 0;
    
    /* Variables used for field dimensions */
    int n, m;

    /* Variables used for neighboring cells */
    unsigned short int n_row, n_col;
    
    /* Loop variables */
    int i, j, d;


    /* Initialize global field array */
    char field[MAX][MAX];

    /* Create a grid with the same dimensions */
    /* Used to store counts of mines adjacent to the cells */
    int counter[MAX][MAX];


    /* Process fields until input dimensions "0 0" are provided */
    while (1) {

        /* Scan dimensions from input */
        scanf("%d %d", &n, &m);

        /* Field dimensions "0 0" indicate the end of input */
        /* Exit the loop if this is the case */
        if (n == 0 && m == 0) {
            break;
        }

        /* Store the field from the input */
        for (i = 0; i < n; i++) {
            scanf("%s", field[i]);
        }

        /* Initialize count array */
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                counter[i][j] = 0;


        /* Traverse every cell in the field */
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {

                /* If the current cell contains a mine, */
                /* update all valid neighboring cells*/
                if (field[i][j] == '*') {

                    /* Check all 8 neighboring cells of current cell */
                    for (d = 0; d < 8; d++) {
                        n_row = i + dir_x[d];
                        n_col = j + dir_y[d];

                        
                        /* Ensure the neighbor cell being checked is within the field dimemsions and is not a mine */
                        /* Add 1 to the current value stored in the number grid */
                        if (n_row  >= 0 && n_row < n && n_col >= 0 && n_col < m && field[n_row][n_col] != '*') {
                            counter[n_row][n_col]++;
                        }
                    }
                }
            }
        }

        /* Print a blank line between consecutive fields after the first one */
        if (field_cnt > 0) {
            printf("\n");
        }

        /* Increment the field count variable */
        /* Add the current field number to the final output */
        printf("Field #%d:\n", ++field_cnt);

        /* Build final field */
        /* Use both field and counter arrays */
        /* Mines remain '*' */
        /* Empty cells become their adjacent mine count instead of '.' */
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (field[i][j] == '*')
                    printf("*");
                else
                    printf("%d", counter[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}