# Circuit Connections

## 1. System Overview

The system uses an Arduino Uno to monitor DC voltage and current. An INA219 module measures current, while a B25 voltage sensor measures the voltage across the DC source.

An I2C LCD displays the measurements.

**Current hardware:**
- Arduino Uno
- INA219 current and power monitoring module
- B25 0–25 V DC voltage sensor
- LCD 1602A with HW-061 I2C adapter

A PV panel and suitable load are planned for the complete system but are not currently available.

## 2. Arduino Uno and INA219

The INA219 communicates with the Arduino Uno over I2C.

| INA219 pin | Arduino Uno pin |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

### Current measurement terminals

| INA219 terminal | Function |
|---|---|
| VIN+ | Input side of the current-sensing path |
| VIN- | Output side of the current-sensing path |

The INA219 must be connected in series with the load current path.

Intended arrangement:

`DC Source (+) → INA219 VIN+ → INA219 VIN- → Load (+)`

The load negative terminal returns to the DC source negative terminal.

## 3. Arduino Uno and B25 Voltage Sensor

The B25 is a 0–25 V DC voltage sensor module using a resistor divider.

### B25 connections

| B25 pin / terminal | Connection |
|---|---|
| Screw terminal VCC | Positive terminal of the voltage source being measured |
| Screw terminal GND | Negative terminal of the voltage source being measured |
| Signal S | Arduino A0 |
| Three-pin connector - | Arduino GND |
| Three-pin connector + | Not connected (NC) |

### Operating principle

The B25 uses a resistor divider to scale its input voltage to a range suitable for the Arduino Uno's analogue input.

The divider ratio is approximately 5:1.

\[
V_{\text{input}} \approx 5 \times V_{\text{ADC}}
\]

The module's maximum specified input is 25 V DC. The Arduino analogue input must never exceed 5 V.

**Important:** Confirm the module's pin labels and common-ground arrangement before powering the circuit.

## 4. Arduino Uno and LCD 1602A

The LCD uses an HW-061 I2C adapter.

| LCD pin | Arduino Uno pin |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

The LCD and INA219 share the Arduino's I2C bus.

The LCD's I2C address must be identified using an I2C scanner before configuring the display library.

## 5. Shared I2C Connections

| Arduino Uno | INA219 | LCD HW-061 |
|---|---|---|
| 5V | VCC | VCC |
| GND | GND | GND |
| A4 / SDA | SDA | SDA |
| A5 / SCL | SCL | SCL |

Both devices share the same SDA and SCL lines.

Their I2C addresses must be different.

## 6. Measurement Architecture

The intended measurement arrangement is:

- B25 measures the DC voltage across the source terminals.
- INA219 measures current flowing through its shunt in series with the load.
- Arduino Uno reads the B25 analogue signal and communicates with the INA219 over I2C.
- LCD displays the measured electrical parameters.

DC power is calculated using:

\[
P=V\times I
\]

Where:

- \(P\) = DC power in watts
- \(V\) = DC voltage in volts
- \(I\) = DC current in amperes

## 7. Hardware and Verification Status

| Component | Availability | Verification status |
|---|---|---|
| Arduino Uno | Available | Model and board operation to verify |
| INA219 | Available | Chip identified; I2C operation pending |
| B25 0–25 V sensor | Available | Model identified; calibration pending |
| LCD 1602A + HW-061 | Available | I2C address and operation pending |
| PV panel | Not available | Planned |
| DC load | Not confirmed | To be selected |

## 8. Safety Notes

- Do not exceed the B25's 25 V DC input rating.
- Ensure the Arduino analogue input never exceeds 5 V.
- Check the PV panel's maximum open-circuit voltage before connecting it.
- Connect the INA219 in series with the load current path.
- Observe the INA219 module's voltage and current ratings.
- Verify wiring before applying power.
- Begin testing with a suitable low-voltage DC source and a current-limited supply where possible.

## 9. Current Project Status

The sensor modules and display have been identified. The next stage is to verify I2C communication, test the LCD, test INA219 measurements, and calibrate the B25 voltage readings before integrating the monitoring firmware.