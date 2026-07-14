#include "states.h"
#include "pins.h"
#include <Arduino.h>

unsigned long cycle_start_time;

state_machine::state_machine()
{
    current_state = state::idle;
    cycle_start_time = millis();
    Serial.println("State -> IDLE");
}

void state_machine::update()
{
    switch (current_state)
    {
        case state::idle:
            idle_state();
            break;

        case state::filling:
            filling_state();
            break;

        case state::testing:
            testing_state();
            break;

        case state::pass_drain:
            pass_drainstate();
            break;

        case state::fail_drain:
            fail_drainstate();
            break;
    }
}

state state_machine::getstate() const
{
    return current_state;
}

void state_machine::setstate(state new_state)
{
    //Turn off all status LEDS at cycle start
    digitalWrite(PASS_LED, LOW);
    digitalWrite(FAIL_LED, LOW);
    digitalWrite(PROCESSING_LED, LOW);

    //Turn on the appropriate LED
    switch (new_state)
    {
        case state::idle:
            break;

        case state::filling:
        case state::testing:
            digitalWrite(PROCESSING_LED, HIGH);
            break;

        case state::pass_drain:
            digitalWrite(PASS_LED, HIGH);
            break;

        case state::fail_drain:
            digitalWrite(FAIL_LED, HIGH);
            break;
    }

    current_state = new_state;
    cycle_start_time = millis();

    Serial.print("State -> ");

    switch (new_state)
    {
        case state::idle:
            Serial.println("IDLE");
            break;
        case state::filling:
            Serial.println("FILLING");
            break;
        case state::testing:
            Serial.println("TESTING");
            break;
        case state::pass_drain:
            Serial.println("PASS DRAIN");
            break;
        case state::fail_drain:
            Serial.println("FAIL DRAIN");
            break;
    }
}

void state_machine::idle_state()
{
    if (digitalRead(START_BUTTON) == LOW)
    {
        delay(20);  //Debounce avoidance

        if (digitalRead(START_BUTTON) == LOW)
        {
            setstate(state::filling);
        }
    }
}

void state_machine::filling_state()
{
    digitalWrite(FILL_PUMP, HIGH);

    if (millis() - cycle_start_time >= 2000)
    {
        digitalWrite(FILL_PUMP, LOW);
        setstate(state::testing);
    }
}

void state_machine::testing_state()
{
    for (int i = 0; i < 3; i++)
    {
        analogRead(TDS_SENSOR);
        delay(10);
    }

    int total = 0;

    for (int i = 0; i < 10; i++)
    {
        int reading = analogRead(TDS_SENSOR);

        Serial.print("Reading ");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(reading);

        total += reading;
        delay(10);
    }

    int average = total / 10;

    Serial.print("Average: ");
    Serial.println(average);

    if (average <= 100)
        setstate(state::pass_drain);
    else
        setstate(state::fail_drain);
}

void state_machine::pass_drainstate()
{
    digitalWrite(PASS_PUMP, HIGH);

    if (millis() - cycle_start_time >= 5000)
    {
        digitalWrite(PASS_PUMP, LOW);
        setstate(state::idle);
    }
}

void state_machine::fail_drainstate()
{
    digitalWrite(FAIL_PUMP, HIGH);

    if (millis() - cycle_start_time >= 5000)
    {
        digitalWrite(FAIL_PUMP, LOW);
        setstate(state::idle);
    }
}