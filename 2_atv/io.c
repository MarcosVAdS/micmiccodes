#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
//describing macros to use digital ports
//|= ou validator
//set value 1 to bit x in Y variable
//activate bit x on variable Y (set to 1)
//Y are register to turn off or turn on and bit_x is port for sample PB5
//will get Y value and deslocate the value of PB5
//bit a bit operation
#define set_bit(Y, bit_x) (Y|=(1<<bit_x))
//clear value 0 to bit x in Y variable
#define clr_bit(Y, bit_x) (Y&=~(1<<bit_x))
//change state from bit x in Y variable
#define tst_bit(Y, bit_x) (Y&(1<<bit_x))
#define LED PB5 
#define BUTTON_INCREMENT PB2 
#define BUTTON_DECREMENT PB3
//the actual objective is just initiate a button
//when a button is pressed turn on
//when another is pressed turn off
//aways verify bit
//https://www.arduino.cc/reference/en/language/variables/utilities/progmem/
//Store data in flash (program) memory instead of SRAM. There’s a description of the various types of memory available on an Arduino board.
const unsigned char Tabela[] PROGMEM = {0x40, 0x79, 0x24, 0x30, 
                                        0x19, 0x12, 0x02, 0x78, 
                                        0x00, 0x18, 0x08, 0x03, 
                                        0x46, 0x21, 0x06, 0x0E};
int main(void){
    UCSR0B = 0x00; // set pd0 and pd1 to i/o generic input mode 

    //initiate counter variable 
    unsigned char counter = 0;//variable setting between 0 and 255

    while(true) {
        //check if increment button has been clicked
        if(!tst_bit(PINB, BUTTON_INCREMENT)){ //checks button state 
            //that button should turn on the led
            if(!tst_bit(PORTB, LED)){ //checks if led is turned off
                set_bit(PORTB,LED); //turn on led
                counter++;
            }
        }

        //verify if decrement button has been clicked
        if(!tst_bit((PINB, BUTTON_DECREMENT)){
            if(tst_bit(PORTB, LED)){ //checks if led is turned ON
                set_bit(PORTB,LED); //turn off led
                counter--;
            }
        }

    }
}

//defining function to not use macro grr >:(
/* static inline void set_bit(long *x, int bit_value){
    *x |= (1L << bit_value);
}
 */