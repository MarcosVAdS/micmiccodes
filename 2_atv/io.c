#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#define set_bit(Y, bit_x) (Y|=(1<<bit_x))
#define clr_bit(Y, bit_x) (Y&=~(1<<bit_x))
#define tst_bit(Y, bit_x) (Y&(1<<bit_x))
#define LED PB5 
#define BUTTON_INCREMENT PB2 
#define BUTTON_DECREMENT PB3

const unsigned char Tabela[] = {0x40, 0x79, 0x24, 0x30, 
                                0x19, 0x12, 0x02, 0x78, 
                                0x00, 0x18, 0x08, 0x03, 
                                0x46, 0x21, 0x06, 0x0E}; 

int main(void){

    UCSR0B = 0x00;

    unsigned char counter = 0;

    while(true){
        if(!tst_bit(PINB, BUTTON_INCREMENT)){ 
            counter++;
            PORTD = pgm_read_byte(&Tabela[counter]);
            _delay_ms(10); 
            while(!tst_bit(PINB,BUTTON_INCREMENT));
        }

        if(!tst_bit((PINB, BUTTON_DECREMENT)){
            counter--;
            _delay_ms(10); 
            PORTD = pgm_read_byte(&Tabela[counter]);
            while(!tst_bit(PINB,BUTTON_DECREMENT));
        }
    }
}