/* coment bloc  {{{
 *
 * Class for Workig with shift microshem
 * in pseudo multithrid evoroment
 * SN74HC165N_shift_reg
 *
 * Program to shift in the bit values from a SN74HC165N 8-bit
 * parallel-in/serial-out shift register.
 *
 *   16 digital states from a
 * pair of daisy-chained SN74HC165N shift registers while using
 * only 4 digital pins on the Arduino.
 *
 * You can daisy-chain these chips by connecting the serial-out
 * (Q7 pin) on one shift register to the serial-in (Ds pin) of
 * the other.
 * 
 * Of course you can daisy chain as many as you like while still
 * using only 4 Arduino pins (though you would have to process
 * them 4 at a time into separate unsigned long variables).
***************************************
***************************************
 *  }}}*/
/* include bloc {{{*/
#ifndef SHIFTIN_h
#define SHIFTIN_h
// the #include statment and code go here...
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
/*}}}*/
//define bloc  {{{
/* How many shift register chips are daisy-chained.
*/
#define NUMBER_OF_SHIFT_CHIPS   2

/* Width of data (how many ext lines).
*/
#define DATA_WIDTH   NUMBER_OF_SHIFT_CHIPS * 8

/* Width of pulse to trigger the shift register to read and latch.
*/
#define PULSE_WIDTH_USEC   5

/* Optional delay between shift register reads.
*/
#define POLL_DELAY_MSEC   1

/* You will need to change the "int" to "long" If the
 * NUMBER_OF_SHIFT_CHIPS is higher than 2.
*/
#define BYTES_VAL_T unsigned int
//Pins 
#define SHIFTIN_PLOADPIN        = 8;  // 1 sh\ld Connects to Parallel load pin 
#define SHIFTIN_CLOCKENABLEPIN  = 9;  // clk inh Connects to Clock Enable pin 
#define SHIFTIN_DATAPIN         = 11; // Qh serial output Connects to the Q7 pin 
#define SHIFTIN_CLOCKPIN        = 12; // clk Connects to the Clock pin 

/*}}}*/
// ShiftIn calss{{{
class ShiftIn {
 public: // {{{
	ShiftIn(int, int, int, int);
	ShiftIn();
	void set_speed(int);
	void fade_to(int);
	void set_to(int);
	void update(void );
	void runtime(void );
	bool done(void);
	void on(void );
	void off(void );
	void trige(void );
	unsigned long update_time;
	int pin;
	/*}}}*/
 private:/*{{{*/
	unsigned int value, to_value;
	unsigned long fade_speed;
	void fade_Up(void); 
	void fade_Down(void); 
	void set_on(void); 
	/*}}}*/
 };
 /*}}}*/
#endif