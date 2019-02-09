/**
    @author: 
    @date: 09-02-2019
    @version: 
**/
#include <DMSU.h>

// Sensor input on analog pin A0
DMSU sensor(A0);

void setup(){
    Serial.begin(9600);
    delay(100);
}

void loop(){
    Serial.print("Distance: ");
    Serial.print(sensor.read());
    Serial.println(" cm");
    delay(1000);
}
