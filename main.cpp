#include "mbed.h"


InterruptIn buttn(PC_13);
//This line initializes an InterruptIn object named buttn on pin PC_13. InterruptIn
volatile int myflag = 0;
//This declares an integer variable named myflag and marks it as volatile

void buttn_fall(){
    //This defines a function named buttn_fall, which will be called when a falling edge interrupt is detected on pin PC_13.
    myflag = 1;
}

int main()
{
    printf("This is mbed os v%d \r\n", MBED_VERSION);
    //This line prints the version of the mbed OS being used.
    buttn.fall(&buttn_fall);
    while (true) {
        if(myflag == 1){
            printf("buttn pressed!!\r\n");
            //This line prints a message indicating that the button has been pressed.
            myflag = 0;
            //This resets the myflag variable to 0 after handling the interrupt, preparing it for the next button press.
        }
    }
}

