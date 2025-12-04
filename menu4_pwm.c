// this is the fourth menu of my project
// the following code is the standalone and quick mode version of the PWM duty cycle calculator.
// helps the user calculate the duty cycle for three types of DC DC converters.
// 1. Buck (step down)
// 2. Boost (step down)
// 3. Inverting buck boost
// in simple terms, the duty cycle is how long the switch is on in each cycle
// and is a key part of these power circuits.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcs.h"
#include "menu4_pwm.h"

// menu function, runs when the user chooses menu item 4 in the main programme
void menu_item_4(void)
{
    print_header("PWM Duty Cycle Calculator");

    // asks the user to pick a converter
    printf("Select converter type:\n");
    printf("1. Buck (step-down)\n");
    printf("2. Boost (step-up)\n");
    printf("3. Inverting buck-boost\n");
    int type;

    // the loop keep repeating until the user enters 1,2 or 3 
    do {
        type = read_int("Select option (1-3): ");
        if (type < 1 || type > 3) {
            printf("Please enter 1, 2 or 3.\n");
        }
    } while (type < 1 || type > 3);

    // reads input and output voltages
    double Vin  = read_double("Enter input voltage Vin (V): ");
    double Vout = read_double("Enter desired output voltage Vout (V): ");
    double D = 0.0; // duty cycle result 

    // doing the math based on the chosen converter
    switch (type)
    {
        // buck converter formula: D=Vout/Vin
        case 1:
            if (Vin == 0.0) {
                printf("Error: Vin cannot be zero.\n"); // Vin should not be 0, as you can't divide by 0
                return;
            }
            D = Vout / Vin;
            break;

        // boost converter formula: D= 1 - Vin/Vout 
        case 2:
            if (Vout == 0.0) {
                printf("Error: Vout cannot be zero.\n");
                return;
            }
            D = 1.0 - (Vin / Vout);
            break;

        // inverting buck boost formula: D = |Vout| / (|Vout| + Vin)
        case 3:
        {
            double absVout = fabs(Vout);

            if (Vin <= 0.0 || absVout == 0.0) {
                printf("Error: Vin and |Vout| must be > 0.\n");
                return;
            }
            D = absVout / (absVout + Vin);
            break;
        }

        default:
            printf("Invalid converter type.\n");
            return;
    }

    // prints final duty cycle calculation
    printf("\nCalculated duty cycle D = %.4f  (%.2f%%)\n",
           D, D * 100.0);

    // warn if duty cycle result is physically impossible
    // duty cycle must be between 0 and 1
    // if its not, it means the chosen converter cannot achieve that voltage
    // Vin and Vout are unrealistic
    if (D < 0.0 || D > 1.0) {
        printf("Warning: This D value is outside the valid 0-1 range.\n");
        printf("Check your Vin and Vout — they may not match this converter.\n");
    }
}