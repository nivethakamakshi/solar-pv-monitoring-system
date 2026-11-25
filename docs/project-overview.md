# Project Overview

## 1. Introduction

The Solar PV Monitoring System is an Arduino-based instrumentation project designed to measure and monitor the electrical parameters of a photovoltaic (PV) solar panel.

The system uses voltage and current sensors to acquire electrical measurements. An Arduino UNO processes the sensor signals and presents the measured parameters through an interfaced LCD.

## 2. Objectives

- Measure the DC output voltage of a photovoltaic panel.
- Measure the current supplied by the panel to its connected load.
- Calculate electrical power from voltage and current measurements.
- Display measurement values through an LCD.
- Enable serial communication for monitoring and potential data logging.

## 3. System Architecture

The system consists of four primary sections:

1. **Power generation:** A photovoltaic panel generates DC electrical power.
2. **Sensing:** Voltage and current sensors acquire electrical parameters.
3. **Processing:** Arduino UNO reads and processes the sensor outputs.
4. **Display and monitoring:** An LCD displays measurement values, while serial communication provides an interface for external monitoring.

## 4. Measured Parameters

| Parameter | Symbol | Unit |
|---|---|---|
| DC Voltage | V | Volt |
| DC Current | I | Ampere |
| Electrical Power | P | Watt |

Electrical power is calculated using:

P = V × I

## 5. Hardware Platform

The documented hardware configuration includes:

- Arduino UNO
- TDC-M20-36 photovoltaic panel
- B25 voltage sensor module
- Current sensing module
- I2C LCD display
- Resistive load

The exact current sensor used in the final prototype and its associated interfacing configuration require verification.

## 6. Software Platform

- Arduino IDE
- Arduino C/C++
- LiquidCrystal_I2C library
- Serial communication

## 7. Intended Applications

- Solar PV electrical parameter monitoring.
- Basic photovoltaic performance observation.
- Embedded instrumentation development.
- Sensor interfacing and data acquisition.
- Educational exploration of renewable energy systems.

## 8. Development Scope

Further development and validation may include:

- Sensor calibration.
- Measurement accuracy analysis.
- Real-time data logging.
- Graphical visualization of PV output.
- Performance evaluation under different operating conditions.

## 9. Current Limitations

The measurement accuracy depends on sensor calibration, ADC resolution, electrical connections and measurement conditions.

The system's performance and measurement accuracy must be experimentally validated before quantitative performance claims are made.