main.out:
	gcc main.c funcs.c \
	    startup_screen.c \
	    menu1_resistor.c \
	    menu2_series_parallel.c \
	    menu3_ohm_power.c \
	    menu4_pwm.c \
		menu5_dcdc.c \
		menu6_signalgen.c \
	    -o main.out -lm

clean:
	-rm main.out

test: clean main.out
	bash test.sh
