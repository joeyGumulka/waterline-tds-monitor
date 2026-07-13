#include <Arduino.h>;

#include "pins.h";
#include "config.h";
#include "states.h";

state_machine machine;

void setup()
{
    Serial.begin(115200);

    pinMode(POWER_LED, OUTPUT); //Setting mode to output for power LED
    digitalWrite(POWER_LED, HIGH);  //If there is power then power LED should always be on

    pinMode(PASS_LED, OUTPUT);
    pinMode(FAIL_LED, OUTPUT);
    pinMode(PROCESSING_LED, OUTPUT);

    pinMode(FILL_PUMP, OUTPUT); //Pump pin set to output mode
    pinMode(PASS_PUMP, OUTPUT);
    pinMode(FAIL_PUMP, OUTPUT);
    digitalWrite(PASS_LED, LOW);
    digitalWrite(FAIL_LED, LOW);
    digitalWrite(PROCESSING_LED, LOW);

    pinMode(START_BUTTON, INPUT_PULLUP);
}

void loop()
{
   machine.update();
}