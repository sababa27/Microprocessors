#include "blink.h"

unsigned int t = 10000;

void main(void){
    while(1){
        pin2 = 1;
        delay(t);
        pin2 = 0;
        delay(t);
    }
}

void delay(unsigned int t){
    unsigned int i;
    for(i=0; i<t; i++){

    }
}
