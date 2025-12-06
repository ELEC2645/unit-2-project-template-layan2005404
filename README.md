[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=21726075)
# ELEC2645 Unit 2 Project 

# Welcome to Layan's Engineering Lab!!!
Welcome to Layan's Engineering Lab, the pinkest command line engineering toolkit ever built for ELEC2645. It's basically your mini lab. 

This project starts as a simple resistor calculator then mutated into a power electronics design assistant, a full waveform generator including ASCII oscilloscope and an Ohm's law tool, featuring a pink start up screen. 

## Menu 1 : Resistor Colour Code Calculator 
- Enter 3 or 4 colour bands
- Calculates Resistance and Tolerance 

## Menu 2 : Series / Parallel Calculator
(for when you forget how resistors add)

- Adds resistors in parallel and series
- Handles 2-10 resistors 

## Menu 3 : Ohm's Law and Power Calculator
### Choose what you want to calculate: 
-  I and P given V and R 
-  V and P given I and R
-  R and P given V and I 

- After computing power, it suggests a real world device that consumes similar wattage 

## Menu 4 : PWM Duty Cycle Calculator (Standalone and Quick Mode)
- Enter Vin and Vout
- Calculates duty cycle D
- Includes 3 converter types: buck (step down), boost (step up) and inverting buck boost converter

## Menu 5 : DC DC Converter Design Assistant
#### For Buck and Boost Converter: 
- Enter Vin, Vout, output current, switching frequency and desired ripple. 
- Check if the input is valid, if not Error
- Calculates duty cycle, inductor L and capacitor C value

#### For inductor ripple and CCM check: 
- Select buck, boost or buck boost converter
- Calculate duty cycle, ripple current and critical current boundary 
- If I(out) > I(crit), then CCM
- If I (out) < I(crit), then DCM

## Menu 6 : Wave form generator and ASCII Oscilloscope
- Generates sin, square, triangle and sawtooth

## How to build
make test

## How to run
./main.out

## Made by Layan
Powered by caffeine and deadlines. 




