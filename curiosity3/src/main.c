/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes


static void S1_User_Handler(GPIO_PIN pin, uintptr_t context) {
    
    SYS_DEBUG_PRINT(1,"Am apasat pe switch %d \r\n",S1_Get());
    
    if (S1_Get() == 0) {
        LED1_Toggle();
    }

}

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );

    SYS_DEBUG_PRINT(1,"Dupa init \r\n");
    GPIO_PinInterruptCallbackRegister(S1_PIN, &S1_User_Handler, 0);
    GPIO_PinIntEnable(S1_PIN, GPIO_INTERRUPT_ON_RISING_EDGE);
    
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

