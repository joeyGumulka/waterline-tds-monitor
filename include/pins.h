//Definition of pin usage

#pragma once    //Needed to avoid duplication of header file during compile

//libs
#include <Arduino.h>

//Pin definitions
constexpr int POWER_LED = 12;

constexpr int FAIL_LED = 13;
constexpr int PROCESSING_LED = 14;
constexpr int PASS_LED = 15;

constexpr int TDS_SENSOR = 34;