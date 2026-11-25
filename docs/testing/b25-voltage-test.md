# B25 Voltage Sensor Test

## Test Objective

Verify the operation of the B25 0–25 V DC voltage sensor with the Arduino Uno.

## Hardware Used

- Arduino Uno
- B25 0–25 V DC voltage sensor
- DC test voltage source

## Connections

| B25 connection | Arduino / circuit |
|---|---|
| Signal S | A0 |
| Three-pin connector - | GND |
| Three-pin connector + | NC |
| Screw terminal VCC | Positive test voltage |
| Screw terminal GND | Negative test voltage |

## Test Procedure

1. Connected the B25 voltage sensor to the Arduino Uno.
2. Uploaded the voltage measurement test sketch.
3. Read the analogue input using `analogRead(A0)`.
4. Converted the ADC reading into sensor voltage.
5. Applied the nominal 5:1 divider ratio to calculate input voltage.
6. Compared the calculated voltage against the expected test voltage.

## Result

**Status: PASSED**

The B25 sensor produced voltage readings close to the expected input voltage.

Minor deviations were observed and calibration is pending.

## Conclusion

The B25 voltage sensor successfully interfaces with the Arduino Uno's analogue input.

Further calibration using a multimeter reference is required before final system validation.

## Pending Work

- Record exact reference and calculated voltages.
- Calculate measurement error.
- Determine a calibration correction factor.
- Verify accuracy at multiple input voltages.
