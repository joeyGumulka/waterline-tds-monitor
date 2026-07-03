//State definitions to be used in state machine

#pragma once

enum class state
{
    idle,
    filling,
    testing,
    pass_drain,
    fail_drain
};

class state_machine
{
public:
    state_machine();

    void update();

    state getstate() const;
    void setstate(state new_state);

private:
    state current_state;

    void idle_state();
    void filling_state();
    void testing_state();
    void pass_drainstate();
    void fail_drainstate();
};