#include "SevSeg.h"
SevSeg sevseg;   //creating an object sevseg

void setup(){
    byte numDigits = 1;  // sets the number of digits on the display
    byte digitPins[] = {};//Creates an array that defines the ground pins when using a 4 digit or multi-digit display
    byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};//declares an array that defines which Arduino pins are
        // connected to each segment of the display.6 for A etc

    bool resistorsOnSegments = true;//set to true if your current limiting resistors are in series with the segment pins

    byte hardwareConfig = COMMON_CATHODE;  // sets the type of display
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);//initializing the display
    sevseg.setBrightness(90);//sets the brightness of the display from 0 to 100
}

void loop(){
  sevseg.setNumber(5, 0);//This function prints the number to the display
  sevseg.refreshDisplay();//This function is required at the end of the loop section to continue displaying the number.     
}