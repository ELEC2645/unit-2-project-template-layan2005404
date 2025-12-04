// fifth menu of my project
// the following code adds a dc dc converter to the menu 
// user chooses between designing a Buck Converter or Boost Converter and check ripple & CCM/DCM mode.
// includes ASCII drawings of the circuits
#include <stdio.h>
#include <math.h>
#include "funcs.h"
#include "menu5_dcdc.h"

// helper functions, only exist in this file 
static void buck_design_helper(void);
static void boost_design_helper(void);
static void ripple_and_ccm_check(void);
static void draw_buck_diagram(void);
static void draw_boost_diagram(void);

// main menu function 
void menu_item_5(void)
{
    int choice = 0;
    print_header("DC-DC Converter Design Assistant");
    printf("1. Buck Converter Design Helper\n");
    printf("2. Boost Converter Design Helper\n");
    printf("3. Inductor Ripple & CCM Check\n");
    printf("4. Back to Main Menu\n");

    // this loop keeps asking until the user enters a number from 1-4
    do {
        choice = read_int("Select option (1-4): ");
    } while (choice < 1 || choice > 4);
    // calling the correct helper
    // switch chooses the correct "sub programme"
    switch (choice)
    {
        case 1:  buck_design_helper(); break;
        case 2:  boost_design_helper(); break;
        case 3:  ripple_and_ccm_check(); break;
        case 4:  return;   
    }
}

// ASCII DIAGRAM for BUCK CONVERTER 
// helps the user visualize what they are designing 
static void draw_buck_diagram(void)
{
    printf("\n");
    printf("          Buck Converter (Step-Down)\n");
    printf("          ---------------------------\n\n");
    printf("        Vin -----(SW)----+------ Vout\n");
    printf("                         |\n");
    printf("                         L\n");
    printf("                         |\n");
    printf("                        --- C\n");
    printf("                        ---\n");
    printf("                         |\n");
    printf("                        GND\n\n");
}
// ASCII DIAGRAM for BOOST CONVERTER 
static void draw_boost_diagram(void)
{
    printf("\n");
    printf("          Boost Converter (Step-Up)\n");
    printf("          ---------------------------\n\n");
    printf("        Vin ----L-----+-----(SW)----- Vout\n");
    printf("                      |\n");
    printf("                     --- C\n");
    printf("                     ---\n");
    printf("                      |\n");
    printf("                     GND\n\n");
}

// BUCK CONVERTER CALCULATION 
static void buck_design_helper(void)
{
    print_header("Buck Converter Design Helper");
    draw_buck_diagram();
    // User inputs for the design 
    double Vin  = read_double("Enter Vin (V): ");
    double Vout = read_double("Enter Vout (V): ");
    double Iout = read_double("Enter output current (A): ");
    double fs   = read_double("Enter switching freq fs (Hz): ");
    double ripple_pct = read_double("Desired inductor ripple (percent): ");
    // buck rule: output must always be lower 
    // checks if Vout makes sense 
    if (Vout > Vin) {
        printf("Error: Buck converter requires Vout <= Vin.\n");
        return;
    }

    // duty cycle formula for buck converter 
    double D = Vout / Vin;

    // convert ripple percentage into a current ripple value 
    double ripple = (ripple_pct / 100.0) * Iout;

    // solve L from dIL equation 
    double L = (Vin * (1.0 - D)) / (ripple * fs);

    // basic capacitor estimate, assuming 1% output voltage ripple
    double dv = 0.01 * Vout;
    double C = (Iout * D) / (dv * fs);

    // output results
    printf("\nResults:\n");
    printf("Duty cycle D = %.4f (%.2f%%)\n", D, D * 100);
    printf("Inductor L   = %.6e H\n", L);
    printf("Capacitor C  = %.6e F  (assumes ~1%% ripple)\n", C);
}

// BOOST CONVERTER CALCULATIONS
static void boost_design_helper(void)
{
    print_header("Boost Converter Design Helper");
    draw_boost_diagram();
    // user inputs 
    double Vin  = read_double("Enter Vin (V): ");
    double Vout = read_double("Enter Vout (V): ");
    double Iout = read_double("Enter output current (A): ");
    double fs   = read_double("Enter switching freq fs (Hz): ");
    double ripple_pct = read_double("Desired inductor ripple (percent): ");

    // a boost converter must have Vout greater than Vin 
    if (Vout <= Vin) {
        printf("Error: Boost converter requires Vout > Vin.\n");
        return;
    }
    // Duty cycle formula for boost 
    double D = 1.0 - (Vin / Vout);

    // convert ripple percent into amps 
    double ripple = (ripple_pct / 100.0) * Iout;

    // Solve L 
    double L = (Vin * D) / (ripple * fs);

    // estimate output capacitor, 1% output voltage ripple assumption
    double dv = 0.01 * Vout;
    double C = (Iout * D) / (dv * fs);
    //results 
    printf("\nResults:\n");
    printf("Duty cycle D = %.4f (%.2f%%)\n", D, D * 100);
    printf("Inductor L   = %.6e H\n", L);
    printf("Capacitor C  = %.6e F  (assumes ~1%% ripple)\n", C);
}
// ripple calculations & CCM Check
static void ripple_and_ccm_check(void)
{
    print_header("Inductor Ripple & CCM Check");

    // user selects converter type 
    printf("Select converter type:\n");
    printf("1. Buck\n");
    printf("2. Boost\n");
    printf("3. Buck-Boost\n");
    int type = 0;
    do {
        type = read_int("Enter choice (1-3): ");
    } while (type < 1 || type > 3);

    // user inputs 
    double Vin  = read_double("Enter Vin (V): ");
    double Vout = read_double("Enter Vout (V): ");
    double fs   = read_double("Enter fs (Hz): ");
    double L    = read_double("Enter L (H): ");
    double Iout = read_double("Enter output current (A): ");
    double D = 0.0;
    double dIL = 0.0;

    // each converter has its own appropriate physics equations 
    if (type == 1) {
        // buck: D=Vout/Vin
        D = Vout / Vin;
        dIL = Vin * (1.0 - D) / (L * fs);
    }
    else if (type == 2) {
        // boost: D=1 - Vin/Vout 
        D = 1.0 - (Vin / Vout);
        dIL = Vin * D / (L * fs);
    }
    else {
        // inverting buck boost
        D = fabs(Vout) / (fabs(Vout) + Vin); // absolute values 
        dIL = Vin * D / (L * fs);
    }
    // critical current boundary
    double I_crit = dIL / 2.0;

    // output the results
    printf("\nduty cycle D = %.4f\n", D);
    printf("Inductor ripple ΔIL = %.6f A\n", dIL);

    // CCM or DCM?
    // Iout>Icrit then CCM
    // Iout<Icrit then DCM
    if (Iout > I_crit)
        printf("converter is operating in CCM (continuous current)\n");
    else
        printf("converter is operating in DCM (discontinuous current)\n");

    printf("critical current boundary = %.6f A\n", I_crit);
}