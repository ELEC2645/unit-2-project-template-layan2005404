//the following code is responsible for showing the pink ASCII screen everytime the programme starts. 
//it does not do any calculations, its purpose is to display a cool intro screen. 
#include <stdio.h>
#include "startup_screen.h"
//clear screen function
// moves cursor to the top left corner 
static void clear_screen(void)
{
    printf("\033[2J\033[H");
}
void startup_screen(void)
{
    clear_screen();
   //changes text color to pink
    printf("\033[1;35m");
    // custom ASCII art
    // used a website: Text to ASCII Art Generator to create ASCII art from text
    printf("\n");
    printf("   ██╗      █████╗ ██╗   ██╗ █████╗ ███╗   ██╗    ███████╗███╗   ██╗ ██████╗     ██╗      █████╗ ██████╗ \n");
    printf("   ██║     ██╔══██╗╚██╗ ██╔╝██╔══██╗████╗  ██║    ██╔════╝████╗  ██║██╔════╝     ██║     ██╔══██╗██╔══██╗\n");
    printf("   ██║     ███████║ ╚████╔╝ ███████║██╔██╗ ██║    █████╗  ██╔██╗ ██║██║  ███╗    ██║     ███████║██████╔╝\n");
    printf("   ██║     ██╔══██║  ╚██╔╝  ██╔══██║██║╚██╗██║    ██╔══╝  ██║╚██╗██║██║   ██║    ██║     ██╔══██║██╔══██╗\n");
    printf("   ███████╗██║  ██║   ██║   ██║  ██║██║ ╚████║    ███████╗██║ ╚████║╚██████╔╝    ███████╗██║  ██║██████╔╝\n");
    printf("   ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝    ╚══════╝╚═╝  ╚═══╝ ╚═════╝     ╚══════╝╚═╝  ╚═╝╚═════╝ \n");
    printf("\n");
    // subtitle
    printf("                            L A Y A N ' S  E N G I N E E R I N G   L A B\n");
    printf("                     ------------------------------------------------------------\n");
    printf("                    | Signal Generation | ASCII Oscilloscope | Power Electronics |\n");
    printf("                     ------------------------------------------------------------\n\n");

    // switched color to a lighter pink 
    printf("\033[38;5;213m");
    printf("   Developed for ELEC2645: Unit 2 Project (2025)\n");
    printf("   Featuring: Waveform Generator, DC DC Design Tools,\n");
    printf("              Resistor Calculators, Power Analysis and more.\n\n");

    //reset colors so it turns back to normal 
    printf("\033[0m");

    //to continue with the calculations 
    printf("press ENTER to continue...");
    getchar();
}