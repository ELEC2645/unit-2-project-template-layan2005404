// this is the first menu of my project
// it is a Colour Code Resistor Calculator 
// real world resistors have colour stripes on them where each colour represents 
// a number, multiple and tolerance percentage 
// the code asks the user whether the resistor have 3 or 4 bands
// following that, lets the user type the colour names 
// programme turns those colour into an actual resistance value in ohms
// resistor colour code table taken from  "Electronics Tutorials"
// example : red (2), green (5), orange (multiplier of 1000)
// answer is 25000 ohms, if resistance has tolerance it will print that too 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funcs.h"
#include "menu1_resistor.h"

// helpers only used inside this file 
static int colour_to_digit(const char *colour);
static double colour_to_multiplier(const char *colour);
static double colour_to_tolerance(const char *colour);
static void read_word(const char *prompt, char *buffer, size_t size);
// main menu function 
// this menu runs when user select resistor colour code calculator 
void menu_item_1(void)
{
    print_header("Resistor Colour code Calculator");
    int bands = 0;
    while (bands != 3 && bands != 4) {
        bands = read_int("enter number of bands (3 or 4): "); // asks the user if the resistor has 3 or 4 bands only 
        if (bands != 3 && bands != 4) {
            printf("please enter 3 or 4.\n");
        }
    }

    // buffers to hold the colour names making them thirty two chars just in case 
    char c1[32], c2[32], c3[32], c4[32];

    // asks the user for the colours 
    // forces it into lowercase
    // if user writes "RED", it will be changed to "red"
    read_word("First band colour: ", c1, sizeof(c1));
    read_word("Second band colour: ", c2, sizeof(c2));
    read_word("Multiplier band colour: ", c3, sizeof(c3));

    // convert colours into actual numbers 
    int d1 = colour_to_digit(c1);
    int d2 = colour_to_digit(c2);
    double mult = colour_to_multiplier(c3);

    // if any colour is unknown, Error 
    if (d1 < 0 || d2 < 0 || mult < 0.0) {
        printf("error: one of your colours wasn't recognised.\n");
        return;
    }
   // main resistor value calculation 
    double resistance = (d1 * 10 + d2) * mult;
    double tol_percent = 0.0;
    int has_tolerance = 0;

    // handles tolerance
    // only if user chooses 4 bands 
    if (bands == 4) {
        read_word("tolerance band colour: ", c4, sizeof(c4));
        tol_percent = colour_to_tolerance(c4);
        if (tol_percent < 0.0) {
            printf("Warning: tolerance colour not recognised. Ignoring it.\n");
        } else {
            has_tolerance = 1;
        }
    }
    // prints final result
    printf("\nCalculated resistance: %.3f ohms", resistance);

    if (has_tolerance) {
        printf("  (tolerance ±%.2f%%)", tol_percent);
    }
    printf("\n");
}
// helper, used for reading colour names
static void read_word(const char *prompt, char *buffer, size_t size)
{
    if (!buffer || size == 0) return;

    while (1) {
        if (prompt) printf("%s", prompt);
        
        // read a whole line from the user 
        if (!fgets(buffer, (int)size, stdin)) {
            printf("\nInput error. Exiting.\n");
            exit(1);
        }
        // removes any newline chaarcters 
        buffer[strcspn(buffer, "\r\n")] = '\0';
        // converts to lowercase 
        to_lowercase(buffer);
        // if blank input, it will ask again 
        if (buffer[0] == '\0') {
            printf("Please enter a value.\n");
            continue;
        }
        break;
    }
}

// colour to digits
// first and second band
// digits 0 to 9
// if colour is not included in the following list, returns (-1) invalid 
static int colour_to_digit(const char *colour)
{
    if (strcmp(colour, "black")  == 0) return 0;
    if (strcmp(colour, "brown")  == 0) return 1;
    if (strcmp(colour, "red")    == 0) return 2;
    if (strcmp(colour, "orange") == 0) return 3;
    if (strcmp(colour, "yellow") == 0) return 4;
    if (strcmp(colour, "green")  == 0) return 5;
    if (strcmp(colour, "blue")   == 0) return 6;
    if (strcmp(colour, "violet") == 0 || strcmp(colour, "purple") == 0) return 7;
    if (strcmp(colour, "grey")   == 0 || strcmp(colour, "gray")   == 0) return 8;
    if (strcmp(colour, "white")  == 0) return 9;
    return -1;  // unknown colour (invalid)
}

// colour to multiplier
// maps colour names and change them into multiply factors 
static double colour_to_multiplier(const char *colour)
{
    if (strcmp(colour, "black")  == 0) return 1.0;
    if (strcmp(colour, "brown")  == 0) return 10.0;
    if (strcmp(colour, "red")    == 0) return 100.0;
    if (strcmp(colour, "orange") == 0) return 1000.0;
    if (strcmp(colour, "yellow") == 0) return 10000.0;
    if (strcmp(colour, "green")  == 0) return 100000.0;
    if (strcmp(colour, "blue")   == 0) return 1e6;
    if (strcmp(colour, "violet") == 0 || strcmp(colour, "purple") == 0) return 1e7;
    if (strcmp(colour, "grey")   == 0 || strcmp(colour, "gray")   == 0) return 1e8;
    if (strcmp(colour, "white")  == 0) return 1e9;
    if (strcmp(colour, "gold")   == 0) return 0.1;
    if (strcmp(colour, "silver") == 0) return 0.01;
    return -1.0;  // unknown (invalid)
}

// colour to tolerance 
// maps colours to tolerance percentages
static double colour_to_tolerance(const char *colour)
{
    if (strcmp(colour, "brown")  == 0) return 1.0;
    if (strcmp(colour, "red")    == 0) return 2.0;
    if (strcmp(colour, "green")  == 0) return 0.5;
    if (strcmp(colour, "blue")   == 0) return 0.25;
    if (strcmp(colour, "violet") == 0 || strcmp(colour, "purple") == 0) return 0.1;
    if (strcmp(colour, "grey")   == 0 || strcmp(colour, "gray")   == 0) return 0.05;
    if (strcmp(colour, "gold")   == 0) return 5.0;
    if (strcmp(colour, "silver") == 0) return 10.0;
    return -1.0;  // unknown
}
