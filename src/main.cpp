#include <Arduino.h>

#include "pins.h"
#include "config.h"
#include "states.h"

void setup()
{
    pinMode(POWER_LED, OUTPUT); //Setting mode to output for power LED
    digitalWrite(POWER_LED, HIGH);  //If there is power then power LED should always be on
}

void loop()
{
   
}