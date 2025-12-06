// this is the third menu of my project 
// a programme that helps the user calculate Ohm's Law and Electrical Power
// it also provides a fun suggestion of what kind of real life device uses that amount of power. 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcs.h"
#include "menu3_ohm_power.h" // linking this file to the rest of the project 

// only used inside this file
static void suggest_device(double P);
// main menu, when user chooses menu 3, this function runs 
void menu_item_3(void)
{
    print_header("Ohm's Law and Power Calculator");

// shows the user the 3 choices 
// 1. user gives voltage and resistance, program finds current and power
// 2. user gives current and resistance, program finds voltage and power
// 3. user gives voltage and current, program finds resistance and power
    printf("Choose what you want to calculate:\n");
    printf("1. Given V and R -> I, P\n");
    printf("2. Given I and R -> V, P\n");
    printf("3. Given V and I -> R, P\n");
    int choice;

    // makes sure the user picks 1, 2, or 3
    do {
        choice = read_int("select option (1-3): ");
        if (choice < 1 || choice > 3) {
            printf("please enter 1, 2 or 3.\n");
        }
    } while (choice < 1 || choice > 3);

    // variable to store whatever is being calculated 
    double V = 0.0, I = 0.0, R = 0.0, P = 0.0;

    // the programme uses a switch statement
    // if option 1 was chosen by the user, block 1 will run
    // if option 2 was chosen by the user, block 2 will run
    // if option 3 was chosen by the user, block 3 will run
    switch (choice) { 
        case 1:     // user entered V and R, code finds I and P
            V = read_double("Enter voltage V (volts): ");
            R = read_double("Enter resistance R (ohms): ");

            if (R == 0.0) { // avoids dividing by zero
                printf("Error: R cannot be zero.\n");
                return;
            }

            I = V / R;
            P = V * I;

            printf("\nCurrent I = %.6f A\n", I);
            printf("Power   P = %.6f W\n", P);
            suggest_device(P);
            break;

        case 2:     // user entered I and R, code finds V and P
            I = read_double("Enter current I (amps): ");
            R = read_double("Enter resistance R (ohms): ");
            V = I * R;
            P = I * I * R;
            printf("\nVoltage V = %.6f V\n", V);
            printf("Power   P = %.6f W\n", P);
            suggest_device(P);
            break;

        case 3:     // user entered V and I, code finds R and P
            V = read_double("Enter voltage V (volts): ");
            I = read_double("Enter current I (amps): ");
            if (I == 0.0) {   // avoid dividing by zero
                printf("Error: I cannot be zero.\n");
                return;
            }
            R = V / I;
            P = V * I;
            printf("\nResistance R = %.6f ohms\n", R);
            printf("Power      P = %.6f W\n", P);
            suggest_device(P);
            break;

        default:
            printf("Invalid option.\n");
            break;
    }
}

// device suggestion based on calculated power
// extra feature: once the power is calculated, the programme prints a real life device
// that uses that much wattage 
static void suggest_device(double P)
{
    //makes the suggestion text purple/pink so it stands out
    printf("\033[1;35m");
    printf("\n--------------------------------------------------\n");
    printf(" Device Suggestion Based on Power: %.2f W\n", P);
    printf("--------------------------------------------------\n");

    if (P < 0.1)
        printf("- Very tiny power: sensors, LEDs, or small logic circuits.\n");

    else if (P < 1)
        printf("- Enough for microcontrollers, LCD modules and tiny radios.\n");

    else if (P < 5)
        printf("- USB gadgets, LED strips, small cooling fans, etc.\n");

    else if (P < 20)
        printf("- Can run routers, small DC motors, or portable speakers.\n");

    else if (P < 60)
        printf("- Light bulbs, laptop chargers, or medium motors.\n");

    else if (P < 200)
        printf("- Desktop PCs, monitors, printers, strong lights.\n");

    else if (P < 1000)
        printf("- Power tools, heaters, kettles, hair dryers.\n");

    else
        printf("• Industrial territory: welders, ovens, big motors.\n");
    // resets terminal color back to normal
    printf("\033[0m");
}
// device suggestions are based on general engineering logic and prior knowledge. 