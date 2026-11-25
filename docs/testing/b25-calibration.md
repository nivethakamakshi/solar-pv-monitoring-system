# B25 Voltage Sensor Calibration

## Objective

Determine a preliminary calibration factor for the B25 0–25 V voltage sensor using a multimeter reference.

## Test Setup

- Power source: 3-cell Li-ion battery pack (3S)
- Battery voltage range: 11.1–12.6 V
- Load: 12 V DC fan
- Measurement condition: Fan operating under load

## Initial Measurements

| Parameter | Reading |
|---|---:|
| Multimeter reference voltage | 12.24 V |
| Initial B25 voltage reading | 11.98 V |
| Absolute error | 0.26 V |
| Percentage error | 2.12% |

## Calibration Calculation

Calibration factor:

\[
K=\frac{V_{\text{reference}}}{V_{\text{sensor}}}
\]

\[
K=\frac{12.24}{11.98}=1.0217
\]

## Preliminary Calibration Result

```cpp
const float VOLTAGE_CALIBRATION = 1.0217;
```

## Status

**Preliminary single-point calibration completed.**

Further measurements at different voltage levels are required to validate the calibration factor across the operating range.

## Next Steps

- Upload firmware with the preliminary calibration factor.
- Repeat the multimeter comparison.
- Collect additional measurement pairs at different battery voltages.
- Determine whether a single-point correction is sufficient.
