# Hardware Components

## 1. Overview

The Solar PV Monitoring System uses an Arduino-based data acquisition arrangement to monitor the electrical output of a photovoltaic (PV) panel.

The physical prototype includes an Arduino UNO, INA219 current and power monitoring module, a separate voltage sensor, and a 16×2 LCD with an I2C interface.

The PV panel is currently unavailable. Its integration and experimental validation will be performed separately.

## 2. Component Inventory

| Component | Model / Specification | Function | Status |
|---|---|---|---|
| Microcontroller | Arduino UNO | Data acquisition and processing | Available |
| Current Sensor | INA219 | DC current, bus voltage and power monitoring | Available |
| Voltage Sensor | DCT Electronics module | Independent voltage measurement | Available; exact model to verify |
| LCD Display | 1602A V5.5 | Displays measurement values | Available |
| LCD Interface | HW-061 I2C module | I2C communication with LCD | Available |
| PV Panel | TDC-M20-36 (documented) | DC power generation | Not available |
| Resistive Load | 330 Ω rheostat (documented) | Variable electrical load | To confirm |

## 3. Microcontroller

### Arduino UNO

The Arduino UNO acts as the central data acquisition and processing unit.

Its functions include:

- Reading sensor measurements.
- Processing electrical parameters.
- Calculating electrical power.
- Updating the LCD display.
- Transmitting measurement data through serial communication.

## 4. Current and Power Measurement

### INA219 Module

The INA219 is a bidirectional DC current and power monitoring module.

Its measurement capabilities include:

- Bus voltage measurement.
- Current measurement through an external shunt resistor.
- Power calculation.

The module communicates with the Arduino using I2C.

The INA219 will be used to monitor the electrical current flowing between the PV source and its connected load.

## 5. Voltage Measurement

### DCT Electronics Voltage Sensor

A separate voltage sensor module is available for measuring DC voltage.

Its exact model, input range, output range and voltage-divider configuration must be identified before firmware implementation.

The sensor's output will be interfaced with an Arduino analog input if its output is analog.

## 6. Display Interface

### LCD 1602A V5.5 with HW-061 I2C Module

The display is a 16-column, 2-row character LCD.

The HW-061 module provides an I2C interface, reducing the number of Arduino connections required.

The display is intended to show real-time electrical measurements.

The actual I2C address must be confirmed using an I2C scanner.

## 7. Photovoltaic Panel

The documented PV panel is identified as TDC-M20-36.

It acts as the DC electrical energy source.

The panel is currently unavailable. Sensor interface testing and display development can proceed independently using appropriately rated test equipment.

## 8. Resistive Load

The project documentation lists a 330 Ω rheostat.

Its purpose is to provide a variable resistive load.

Its availability and power rating must be confirmed before testing.

## 9. Hardware Verification Checklist

- [x] Arduino UNO identified.
- [x] INA219 current sensor identified.
- [x] DCT Electronics voltage sensor identified by manufacturer.
- [x] 1602A LCD identified.
- [x] HW-061 I2C module identified.
- [ ] Confirm voltage sensor model and specifications.
- [ ] Scan and confirm I2C addresses.
- [ ] Confirm INA219 module configuration.
- [ ] Confirm rheostat availability and power rating.
- [ ] Document actual circuit connections.
- [ ] Integrate photovoltaic panel.
- [ ] Calibrate measurements against reference instruments.

## 10. Notes

The actual hardware inventory takes precedence over component lists in earlier project documentation.

Unverified component specifications and circuit configurations will be documented only after physical inspection and testing.