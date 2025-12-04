// ELEC2645 Unit 2 Project Template
// Command Line Application Menu Handling Code

//MAIN CODE 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "funcs.h" //input helpers            
#include "startup_screen.h" // start up screen, first thing that shows when running the code 
#include "menu1_resistor.h" // MENU 1, calculates the resistance of a resistor by providing the colours of its bands
#include "menu2_series_parallel.h" // MENU 2, calculates the total resistance of 2-10 resistors
#include "menu3_ohm_power.h" // MENU 3, uses ohms law to calculate two missing variables when user inputs two known variables 
#include "menu4_pwm.h" // MENU 4, calculates duty cycle D
#include "menu5_dcdc.h" // MENU 5, buck and boost converters helpers
#include "menu6_signalgen.h" // MENu 6, signal generator 

// forward declaration, local functions used only inside this file
static void main_menu(void);
static void print_main_menu(void);
static int  get_user_input(void);
static void select_menu_item(int input);
static void go_back_to_main(void);
// main function: programme starts here 
int main(void)
{
    // shows pink ASCII start up screen (runs once)
    startup_screen();

    // main loop so it keeps running 
    while (1) {
        main_menu();
    }
    return 0;  
}
// main menu logic 
// prints menu on screen 
// asks user to choose one
// run the menu based on the user's choice 
static void main_menu(void)
{
    print_main_menu();
    int choice = get_user_input();
    select_menu_item(choice);
}
// getting the user's choice 
static int get_user_input(void)
{
    // there are 7 items in the main menu (the 7th is the Exit)
    const int MENU_ITEMS = 7;  
    int value = 0;
    do {
        // asks user to choose a number 
        value = read_int("\nSelect item: "); 
        if (value < 1 || value > MENU_ITEMS) {
            // if user enters numbers such as 0 or 8, it will print invalid
            printf("Invalid option, try again.\n"); 
        }
    // will repeat until a correct number is entered
    } while (value < 1 || value > MENU_ITEMS); 
    return value;
}
// jumps to the correct menu 
static void select_menu_item(int input)
{
    switch (input) // if user chooses menu 1, menu 1 will run 
    {
        case 1:
            menu_item_1(); // the function is found inside the menu's .c file
            go_back_to_main(); // prevents the menu from suddenly disappearing 
            break;

        case 2:
            menu_item_2(); // the function is found inside the menu's .c file
            go_back_to_main();
            break;

        case 3:
            menu_item_3(); // the function is found inside the menu's .c file
            go_back_to_main();
            break;

        case 4:
            menu_item_4(); // the function is found inside the menu's .c file
            go_back_to_main();
            break;

        case 5:
            menu_item_5(); // the function is found inside the menu's .c file
            go_back_to_main();
            break;

        case 6:
            menu_item_6(); // the function is found inside the menu's .c file
            go_back_to_main();
            break;

        case 7: // exit
        default:
            printf("Bye!\n");
            exit(0);
    }
}
// prints the actual menu 
static void print_main_menu(void)
{
    printf("\n----------- Main menu -----------\n\n"); // "\n" means new line
    printf("\t1. Resistor colour code\n");
    printf("\t2. Series / parallel resistors\n");
    printf("\t3. Ohm's law and power\n");
    printf("\t4. PWM duty cycle calculator\n");
    printf("\t5. DC-DC Converter Design Assistant\n");
    printf("\t6. Signal Generator\n");
    printf("\t7. Exit\n\n");
    printf("---------------------------------\n");
}
// returns to main menu 
static void go_back_to_main(void)
{
    char buf[64];
    // loop until userr enters b or B only and nothing else
    while (1) 
    {
        printf("\nEnter 'b' or 'B' to go back to main menu: ");
        if (fgets(buf, sizeof(buf), stdin)==NULL) {
            printf("input error.\n");
            exit(1);
        }
        //removes newline at the end of what the user has typed
        //replaces it with end of string character
        //cleans input and prevents newline from messing up with comparisons later 
        buf[strcspn(buf, "\r\n")] = '\0'; 
        // first character must b or B
        // second character must be nothing meaning only one letter is allowed with no spaces 
        if ((buf[0] == 'b' || buf[0] == 'B') && buf[1] == '\0') {
        // if input is invalid, it will exit the loop and go back to the main menu 
            break;
        }
    }
    pause_and_clear(); // clears the screen for the next menu 
}