/*
    Smart Water Filter and Refrigeration 
    Board: ESP8266 Mod
    author: Edward "Toy" Facundo <toymak3r@gmail.com>
    all rights reserved 2020
*/

#include "general.h"

void setup()
{
    //Serial Port begin
    Serial.begin(9600);

    //Define inputs and outputs
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop()
{
    // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read the signal from the sensor: a HIGH pulse whose
    // duration is the time (in microseconds) from the sending
    // of the ping to the reception of its echo off of an object.
    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);

    // Convert the time into a distance
    cm = (duration / 2) / 29.1; // Divide by 29.1 or multiply by 0.0343
                                // inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135

    if (cm <= close_point)
    {
        Serial.println("{ \"state\" : \"open\" }");
        counter += 1;
    }
    else
    {
        Serial.println("{ \"state\" : \"closed\" }");
        if ((counter != 0) and state == false)
        {
            descarga();
        }
    }

    delay(250);
}
