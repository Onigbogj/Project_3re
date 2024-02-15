#include "mbed.h"
#include "arm_book_lib.h"

#include "display.h"
#include "wiper.h"
#include "userInterface.h"

#define DISPLAY_REFRESH_TIME_MS         1000
#define SYSTEM_TIME_INCREMENT_MS        10


void userInterfaceDisplayInit()
{
    displayInit();
     
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "Mode:" );

    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "INTDelay:" );
}

void userInterfaceDisplayUpdate()
{
    static int accumulatedDisplayTime = 0;
    
    if( accumulatedDisplayTime >=
        DISPLAY_REFRESH_TIME_MS ) {
        accumulatedDisplayTime = 0;

        displayCharPositionWrite ( 7, 0);
        int mode = 1000;
        if (mode == 0) {
            displayStringWrite( "HI  " );
        }
        else if(mode == 1){
            displayStringWrite( "LO  " );
        }
        else if(mode == 2){
            displayStringWrite( "INT  " );
        }
        else if(mode == 3){
            displayStringWrite( "OFF " );
        }
        else{
            displayStringWrite( "OFF " );
        }
    

        
    } 
    else {
        accumulatedDisplayTime =
            accumulatedDisplayTime + SYSTEM_TIME_INCREMENT_MS;        
    } 
}