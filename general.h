/*
    Smart Water Filter and Refrigeration 
    Board: ESP8266 Mod
    author: Edward "Toy" Facundo <toymak3r@gmail.com>
    all rights reserved 2020
*/

int detectionDistance 6; // Detecion distance for object before the sensor
int trigPin = 10;        // Trigger
int echoPin = 11;        // Echo
long duration, cm, inches;

