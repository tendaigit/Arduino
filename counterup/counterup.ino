#include<SevSeg.h>
SevSeg sevseg; 

void setup(){
    byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};
    bool resistorsOnSegments = true;

    byte hardwareConfig = COMMON_CATHODE; 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
}

void loop(){
    for(int i = 0; i < 10; i++){    //loop to count from 0 to 9
        sevseg.setNumber(i, i%2);   //prints the value of i.The i%2 argument divides i by 2 and returns the remainder,
//                                   which causes the decimal point to turn on every other number 

        delay(1000);
        sevseg.refreshDisplay(); 
        }
}
