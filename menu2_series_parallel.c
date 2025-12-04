// this is the second menu of my project 
// this code is a tool that helps the user calculate the equivalent resistance of several resistors 
// that are connected in either parallel or series
// the user chooses which type of circuit they have, enters the resistor's values 
// the programme calculates the total resistance 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcs.h"
#include "menu2_series_parallel.h"

// main menu, runs when the user picks menu option 2
void menu_item_2(void)
{
    // title at the top so that the user knows what tool they have opened
    print_header("Series / Parallel Resistor Calculator");

    // let the user pick which type of circuit they want, series or parallel 
    printf("1. Series connection\n");
    printf("2. Parallel connection\n");
    int mode;
    // asks until the user enters 1 or 2
    // 1 for for series, 2 for parallel connection 
    do {
        mode = read_int("choose connection type (1 or 2): ");
        if (mode != 1 && mode != 2) {
            printf("please enter 1 or 2.\n");
        }
    } while (mode != 1 && mode != 2);
    int n;

    // number of resistors in the circuit (between 2 and 10)
    do {
        n = read_int("how many resistors (2-10)? ");
        if (n < 2 || n > 10) {
            printf("please enter a number between 2 and 10.\n");
        }
    } while (n < 2 || n > 10);
    double req = 0.0;   // will hold the final answer

    // if series was chosen
    if (mode == 1) {
        // in series, we just add everything: Req=R1 + R2 + ...
        for (int i = 0; i < n; ++i) {
            char prompt[64];

            // the code asks for each resistor value and adds it
            snprintf(prompt, sizeof(prompt), "R%d (ohms): ", i + 1);
            double r = read_double(prompt);  
            req += r;                         
        }
        printf("\nequivalent series resistance: %.3f ohms\n", req);
    }

    // if parallel was chosen 
    else {
        // in parallel, it's easier to sum the reciprocals: (1/Req)=(1/R1)+(1/R2)+...
        double inv_sum = 0.0;
        for (int i = 0; i < n; ++i) {
            char prompt[64];
            snprintf(prompt, sizeof(prompt), "R%d (ohms): ", i + 1);
            double r = read_double(prompt);

            // if the user enters 0 ohms, skip it because 1/0 equals to undefined
            if (r == 0.0) {
                printf("Warning: R%d = 0 ohms, skipping.\n", i + 1);
                continue;
            }
            inv_sum += 1.0 / r;
        }
        // if the user entered all zeros or everything skipped
        if (inv_sum == 0.0) {
            printf("\nCannot compute equivalent resistance (no valid resistors).\n");
        }
        else {
            req = 1.0 / inv_sum;
            printf("\nEquivalent parallel resistance: %.3f ohms\n", req);
        }
    }
}