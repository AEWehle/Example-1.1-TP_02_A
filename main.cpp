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
/*
entrando a los archivos de bajo nivel durante la ejecucion encontramos
 los archivos gpio_api.c y pinmap.c que ocntienen las ubicicaciones de
 registros y sus definiciones
 en punmap, incluye pinnames el cual indica que 
    D2          = PF_15,
    LED1        = PB_0,  // LD1 = GREEN
*/
/*
static functions that are restricted to the same file in which they are defined
inline reemplaza lo que declara a donde se llama
*/
int main()
{
    DigitalIn gasDetector(D2); // digitalin.h -> mbed_gpio.c -> gpio_api.c -> pinmap.c -> cmsis_armclang.h -> stm32f4xx_ll_gpio.h
// la clase es digital in y el objeto gasdetector, pin d2
// se llama al constructor
// digitalin y digitalout los hizo mbed
// 
 
    DigitalOut alarmLed(LED1); // digitalout.h -> mbed_gpio.c -> gpio_api.c -> pinmap.c -> cmsis_armclang.h -> stm32f4xx_ll_gpio.h

    gasDetector.mode(PullDown); // deifne el modo del objeto gas detector a pulldown
 // se llama al metodo mode de digitalout

    alarmLed = OFF; // apaga led, pone el value off del pin del led, clase digitalout obeto alarmled
    // esto es una sobrecarga del = definido en digitalout
 
    while (true) {
        if ( gasDetector == ON ) { // esto es una sobrecarga del ==
            printf("%s\n", "se detecta gas, alarma sonando");
            alarmLed = ON;
        }
        
        if ( gasDetector == OFF ) {
            printf("%s\n", "no se detecta gas, alarma apagada");
            alarmLed = OFF;
        }
    }
}
