// this following code contains helper functions that are needed for the whole project
// such as: 
// reading an integer safely
// reading a decimal number safely
// cleaning up text input
// waiting for the user 
// printing appropriate headers
// this makes my menu cleaner and prevent crashing 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "funcs.h"
// this function reads an integer from the user with basic validation
int read_int(const char *prompt) 
{
    // buffer for input, a place to store the user's typing
    char buf[128];      
    // temporary variable to store the number the user typed
    long value;         
    // a pointer used to detect invalid characters 
    char *endptr;       
    // infinite loop until the user gives a valid number
    while (1) { 
        if (prompt) {
            // if prompt exists, it will print it 
            printf("%s", prompt);   
        }
        if (fgets(buf, sizeof(buf), stdin)==NULL) {
            // if input fails, just exit
            puts("input error.");
            exit(1);
        }
        //removes newline at the end of what the user has typed
        //replaces it with end of string character
        //cleans input and prevents newline from messing up with comparisons later
        buf[strcspn(buf, "\r\n")] = '\0';
        // skip any spaces at the start
        char *p = buf;
        while (*p == ' ' || *p == '\t') {
            p++;   
        }
        // check for empty input and if the user typed nothing, it will ask again 
        if (*p == '\0') {
            printf("Please enter a value.\n");
            continue;
        }
        // converts text into an integer 
        value = strtol(p, &endptr, 10);
        // if extra characters exist, it's invalid and will reject it 
        if (*endptr != '\0') {
            printf("invalid integer, try again.\n");
            continue;
        }
        // returns valid integer and ends the function 
        return (int)value;
    }
}
// reads decimal numbers 
double read_double(const char *prompt)
{
    char buf[128];   
    double value;    
    char *endptr;
    while (1) {
        if (prompt) {
            printf("%s", prompt);  
        }
        if (fgets(buf, sizeof(buf), stdin)==NULL) {
            puts("input error.");
            exit(1);
        }
        // removes newline at the end 
        buf[strcspn(buf, "\r\n")] = '\0';
        // skips initial spacess
        char *p = buf;
        while (*p == ' ' || *p == '\t') {
            p++;
        }
        // checks empty entry
        if (*p == '\0') {
            printf("Please enter a value.\n");
            continue;
        }
        // converts to double
        value = strtod(p, &endptr);
        if (*endptr != '\0') {
            printf("Invalid number, try again.\n");
            continue;
        }
        return value;
    }
}

// the following function is used for resistor's colour, it takes a string and converts
// all letters to lowercase 
void to_lowercase(char *s)
{
    // loops through characters one by one
    // turns them into lowercase 
    // moves to the next character
    // stops when it hits the end of the string
    if (!s) return; 
    while (*s) {
        *s = (char)tolower((unsigned char)*s); 
        s++;                                    
    }
}

// this function waits for 'ENTER' then it will clear the screen 
void pause_and_clear(void)
{
    // temp variable to read caharacters
    int c; 
    printf("\nPress ENTER to continue...");
    // make sure text or message is printed
    fflush(stdout);    
    // reads characters until it finds the enter key
    while ((c = getchar()) != '\n' && c != EOF) {
        ; 
    }

// checks which device is being used
#ifdef _WIN32 
// window users uses cls 
    system("cls");     
#else
// mac users uses clear 
    system("clear");   
#endif
}

// prints an appropriate header bar 
void print_header(const char *title)
{
    printf("\n==================================\n");
    if (title) {
        printf("%s\n", title); 
    }
    printf("====================================\n");
}