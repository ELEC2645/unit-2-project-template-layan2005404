#ifndef FUNCS_H
#define FUNCS_H

//helpers 
int read_int(const char *prompt);          // used in all menu items, takes a text message as input
double read_double(const char *prompt);    // used inn PWM, Ohm’s law, resistors and DC DC, take decimal no
void to_lowercase(char *s);                // used in colour code calculator, takes (an example) Red and turns it into red
void pause_and_clear(void);                // used in all menu items, waits for ENTER then clears the screen 
void print_header(const char *title);      // used in all menu items, prints a formatted title bar around a name 

#endif 
