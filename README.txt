# Waterline TDS Monitor

## Overview

A proof-of-concept embedded system that simulates an automated industrial water quality testing station. An ESP32 controls pumps, measures Total Dissolved Solids (TDS), and automatically routes the water sample to either a pass or fail drain.

## Features

- ESP32 firmware using PlatformIO
- Finite state machine
- Automated fill, test, and drain cycle
- Pass/fail decision based on TDS measurements
- Status LEDs
- Push-button operation
- 3D printed prototype components

## Hardware

- ESP32-WROVER development board
- TDS sensor
- 3 × DC micro submersible water pumps
- IRLZ44N N-channel MOSFETs
- LEDs
- Resistors
- Breadboard and dupont wires
- 3D printed frame and push-button enclosure
- Silicone tubing
- 5v USB for power

## Operation

1. Press the start button.
2. The fill pump transfers a water sample into the test chamber.
3. The ESP32 collects and averages multiple TDS readings.
4. The reading is compared against a configurable threshold.
5. The sample is automatically pumped to either the PASS or FAIL container.
6. The system returns to the idle state.