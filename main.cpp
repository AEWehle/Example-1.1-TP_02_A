#include "mbed.h"
#include "arm_book_lib.h"

/*
@ */
/* 5.
Carpetas
- BUILD
- mbed-os
Archivos
- main.cpp
- arm_book_lib.h, declaracion de estados y funciones publicas
- mbed-os.lib, link a repositorio de arm
- compile_commands.json, java script objet notation
*/

int main()
{
    DigitalIn gasDetector(D2);

    DigitalOut alarmLed(LED1);

    gasDetector.mode(PullDown);

    alarmLed = OFF;

    while (true) {
        if ( gasDetector == ON ) {
            alarmLed = ON;
        }
        
        if ( gasDetector == OFF ) {
            alarmLed = OFF;
        }
    }
}