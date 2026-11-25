# Integrated System Test

## 1. Test Objective

To verify the integrated operation of the Arduino-based monitoring system, including voltage measurement, current measurement, power calculation, LCD display, and serial output.

## 2. Test Setup

| Component | Description |
|---|---|
| Microcontroller | Arduino Uno |
| Voltage sensor | B25 0–25 V |
| Current and power sensor | INA219 |
| Display | LCD 1602A with I2C adapter |
| Power source | 3-cell Li-ion battery pack (11.1–12.6 V) |
| Load | 12 V DC fan |

**Test configuration:** The battery pack powered the DC fan. The B25 sensor measured the supply voltage, while the INA219 measured current in series with the load. The Arduino processed the measurements and displayed the results on the LCD and Serial Monitor.

## 3. Test Results

| Parameter | Arduino System | Multimeter Reference |
|---|---:|---:|
| Voltage | 11.98 V | 12.24 V |
| Current | 0.52 A | 0.53 A |
| Power | 6.24 W | 6.49 W (calculated) |

## 4. Measurement Deviation

| Parameter | Absolute Difference | Percentage Difference |
|---|---:|---:|
| Voltage | 0.26 V | 2.12% |
| Current | 0.01 A | 1.89% |
| Power | 0.25 W | 3.82% |

Percentage differences are calculated relative to the multimeter reference values.

Reference power is calculated using:

\[
P = V \times I = 12.24 \times 0.53 \approx 6.49\,W
\]

## 5. Observations

- The Arduino successfully acquired voltage measurements from the B25 sensor.
- The INA219 successfully measured load current.
- The system calculated electrical power from the measured voltage and current.
- The LCD displayed the measured parameters.
- Serial output was successfully generated.
- The readings were reasonably close to the multimeter reference measurements.

## 6. Test Outcome

**Result: PASS — Integrated bench test completed.**

The integrated monitoring system operated successfully with the battery-powered DC fan load.

The recorded measurements represent a preliminary validation at one operating point. Further multi-point calibration has not been performed.

## 7. Limitations

- Testing was performed using a Li-ion battery pack rather than a photovoltaic panel.
- Actual PV-panel monitoring and outdoor testing remain pending.
- The voltage and current measurements have not undergone multi-point calibration.
- The calculated power value is based on the measured voltage and current.

## 8. Conclusion

The integrated Arduino-based monitoring system successfully measured voltage and current, calculated power, and displayed the results through the LCD and Serial Monitor.

The bench test establishes the basic functionality of the hardware and firmware. Validation with an actual photovoltaic panel will be required before claiming complete PV monitoring system performance.