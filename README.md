# Solar PV Monitoring System

An Arduino-based embedded instrumentation project for monitoring the electrical parameters of a DC power source, with the intended application of photovoltaic (PV) system monitoring.

The system uses voltage and current sensors to acquire electrical measurements, calculates power, and displays the results through an LCD and serial interface.

**Current development stage:** Integrated hardware prototype successfully bench-tested using a 3S Li-ion battery pack and a 12 V DC fan. Testing with an actual photovoltaic panel is pending.

## Project Overview

Photovoltaic systems convert solar energy into electrical energy. Monitoring their electrical output helps evaluate operating conditions and understand the interaction between a power source and its connected load.

This project explores the development of a low-cost embedded monitoring system using an Arduino Uno, voltage and current measurement modules, and an LCD interface.

The initial development focuses on hardware interfacing, sensor data acquisition, measurement processing, and validation against reference instruments.

## Key Features

- DC voltage measurement using a B25 voltage sensor.
- DC current measurement using an INA219 sensor module.
- Electrical power calculation using measured voltage and current.
- Real-time measurement display through a 16×2 I2C LCD.
- Serial output for monitoring measurements through a computer.
- Modular hardware architecture for future PV-panel integration.

## System Architecture

```text
       DC POWER SOURCE
       (PV Panel Planned)
              |
       +------+------+
       |             |
  B25 Voltage    INA219 Current
    Sensor          Sensor
       |             |
       |         I2C Interface
       |             |
       +------+------+
              |
         ARDUINO UNO
              |
       +------+------+
       |             |
   LCD DISPLAY   SERIAL OUTPUT
                     |
                PC MONITORING
```

## Hardware Components

| Component | Purpose |
|---|---|
| Arduino Uno | Sensor data acquisition and processing |
| B25 0–25 V Voltage Sensor | DC voltage measurement |
| INA219 Module | Current measurement through I2C |
| LCD 1602A with HW-061 I2C Adapter | Measurement display |
| 3S Li-ion Battery Pack | Bench-test power source |
| 12 V DC Fan | Bench-test electrical load |
| Connecting wires | Electrical interfacing |

**Planned hardware:** A photovoltaic panel will be integrated for PV-specific testing and validation.

## Software and Tools

- Arduino IDE
- Arduino C/C++
- LiquidCrystal_I2C library
- Adafruit INA219 library
- I2C communication
- Git and GitHub for version control and documentation

## Working Principle

1. The DC power source supplies electrical energy to the connected load.
2. The B25 voltage sensor measures the source voltage through a resistive voltage divider.
3. The INA219 measures current flowing through its shunt resistor.
4. The Arduino Uno acquires the sensor measurements.
5. Electrical power is calculated using:

   \[
   P = V \times I
   \]

6. Voltage, current, and calculated power are displayed on the LCD and transmitted through serial communication.

## Preliminary Bench-Test Results

The integrated prototype was tested using a 3S Li-ion battery pack and a 12 V DC fan.

| Parameter | System Reading | Multimeter Reference |
|---|---:|---:|
| Voltage | 11.98 V | 12.24 V |
| Current | 0.52 A | 0.53 A |
| Power | 6.24 W | 6.49 W* |

*Reference power calculated from the multimeter voltage and current readings.*

The preliminary measurements showed deviations of approximately:

- Voltage: 2.12%
- Current: 1.89%
- Power: 3.82%

These results represent a single operating-point bench test, not a complete sensor calibration or PV-panel performance evaluation.

## Repository Structure

```text
## Repository Structure

```text
solar-pv-monitoring-system/
│
├── docs/
│   ├── images/
│   ├── testing/
│   │   ├── b25-calibration.md
│   │   ├── b25-voltage-test.md
│   │   ├── i2c-scanner-test.md
│   │   ├── ina219-current-test.md
│   │   └── integrated-system-test.md
│   ├── calibration.md
│   ├── circuit-connections.md
│   ├── hardware-components.md
│   ├── project-overview.md
│   └── working-principle.md
│
├── firmware/
│   ├── reference/
│   └── solar-pv-monitor/
│       └── solar-pv-monitor.ino
│
├── media/
├── .gitignore
├── LICENSE
└── README.md
```

## Project Status

| Development Stage | Status |
|---|---|
| Arduino Uno setup | Completed |
| I2C communication | Tested |
| LCD interfacing | Completed |
| B25 voltage measurement | Tested |
| INA219 current measurement | Tested |
| Integrated firmware | Completed |
| LCD and serial output | Tested |
| Preliminary multimeter validation | Completed |
| Multi-point sensor calibration | Pending |
| PV-panel integration | Pending |
| PV-specific performance evaluation | Pending |
| Extended data logging | Future improvement |

## Future Improvements

- Integrate an actual photovoltaic panel.
- Perform multi-point voltage and current calibration.
- Evaluate measurement accuracy under different operating conditions.
- Implement PC-based data logging.
- Analyse PV output under varying environmental conditions.
- Improve data visualisation and performance analysis.

## Safety

- Verify sensor voltage and current ratings before connecting a power source.
- Observe correct polarity and common-ground requirements.
- Ensure the INA219 is connected in series with the load.
- Avoid short circuits when working with Li-ion battery packs.
- Check the PV panel's maximum open-circuit voltage before connecting it to the measurement circuit.

## License

This project is intended for educational and engineering development purposes. Refer to the [LICENSE](LICENSE) file for licensing information.