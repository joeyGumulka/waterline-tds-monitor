#include "states.h"

state_machine::state_machine()  //Init function, idle state by default
{
    current_state = state::idle;
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

state state_machine::getstate() const
{
    return current_state;
}