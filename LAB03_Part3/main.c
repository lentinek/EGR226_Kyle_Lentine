#include "msp.h"


void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

    // Configure GPIO for output on P1.0 LED1 on MSP432 LaunchPad
    P1->DIR = BIT0;

    //Temporary variable for loop-maintenance
    int i;
    int j;

    while(1){
        P1->OUT ^= BIT0;    // Toggle LED status
        for(i=j; i>0; i--); //Delay
    }
}
