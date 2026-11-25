# I2C Scanner Test

## Test Objective

Verify communication between the Arduino Uno and connected I2C devices using the Arduino Wire library.

## Hardware Used

- Arduino Uno
- INA219 current and power monitoring module
- LCD 1602A with HW-061 I2C adapter

## Connections

| Arduino Uno | Connected modules |
|---|---|
| 5V | INA219 VCC, LCD VCC |
| GND | INA219 GND, LCD GND |
| A4 / SDA | INA219 SDA, LCD SDA |
| A5 / SCL | INA219 SCL, LCD SCL |

## Test Procedure

1. Connected the INA219 and LCD to the Arduino Uno's I2C bus.
2. Uploaded the I2C scanner sketch.
3. Opened the Serial Monitor at 9600 baud.
4. Checked for responding I2C devices.

## Result

**Status: PASSED**

- Arduino sketch compiled successfully.
- Upload completed successfully.
- I2C devices were detected.
- No communication errors were reported.

## Conclusion

The Arduino Uno successfully communicates with the connected I2C devices through the shared I2C bus.

The next tests will verify LCD display operation and INA219 measurements independently.

## Pending Information

Record the detected I2C addresses from the Serial Monitor when available.