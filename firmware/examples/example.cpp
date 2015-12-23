#include "MQ135.h"

int number = 0;
int state = 0;
MQ135 gasSensor = MQ135(0);
int led = D7;
float rzero = gasSensor.getRZero();
int ppm = gasSensor.getPPM();

// SETUP
void setup() {

}

// LOOP
void loop() { 

    float rzero = gasSensor.getRZero();
    digitalWrite(led,HIGH);      // turn the ledPin on
    delay(100);                      // stop the program for some time
    digitalWrite(led, LOW);       // turn the ledPin off
    delay(100);  // stop the program for some time


    int co2_ppm = gasSensor.getPPM();
    int ppm = co2_ppm / 4;
    Spark.variable("ppm", &ppm, INT);
    //Vrl = val * ( 5.00 / 1024.0  );      // V
    //Rs = 20000 * ( 5.00 - Vrl) / Vrl ;   // Ohm 
    //ratio =  Rs/Ro;                      

    delay(10000);
}