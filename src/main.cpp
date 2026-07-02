#include <Arduino.h>

#include "pins.h"
#include "config.h"
#include "states.h"

void setup()
{
    pinMode(POWER_LED, OUTPUT); //Setting mode to output for power LED
    digitalWrite(POWER_LED, HIGH);  //If there is power then power LED should always be on

    pinMode(FILL_PUMP, OUTPUT); //Setting mode to output for pump fill
    digitalWrite(FILL_PUMP, LOW); //Pump off as default
}

void loop()
{
    digitalWrite(FILL_PUMP, HIGH);
    delay(2000);

    digitalWrite(FILL_PUMP, LOW);
    delay(2000);
}