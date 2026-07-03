#include "states.h"
#include <esp32-hal.h>

unsigned long cycle_start_time;

state_machine::state_machine()  //Init function, idle state by default
{
    current_state = state::idle;
    cycle_start_time = millis();    //Start counting miliseconds on board init
}

void state_machine::update() //Switch statement, seperated for ease of reading state functions
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
        default:
            current_state = state::idle;
            break;
    }
}


state state_machine::getstate() const   //Getter def.
{
    return current_state;
}

void state_machine::setstate(state new_state) //Setter def.
{
    current_state = new_state;
}


void state_machine::idle_state()
{
    if (millis() - cycle_start_time >= 5000)
    {
        current_state = state::filling;
        cycle_start_time = millis();
    }
}

void state_machine::filling_state()
{
     if (millis() - cycle_start_time >= 5000)
    {
        current_state = state::testing;
        cycle_start_time = millis();
    }
}

void state_machine::testing_state()
{
     if (millis() - cycle_start_time >= 5000)
    {
        current_state = state::pass_drain;
        cycle_start_time = millis();
    }
}

void state_machine::pass_drainstate()
{
     if (millis() - cycle_start_time >= 5000)
    {
        current_state = state::idle;
        cycle_start_time = millis();
    }
}

void state_machine::fail_drainstate()
{
    
}