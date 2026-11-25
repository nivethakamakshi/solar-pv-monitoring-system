# INA219 Current Measurement Validation

## Objective

Evaluate the INA219 current measurement against an independent multimeter reference.

## Test Setup

- Microcontroller: Arduino Uno
- Current sensor: INA219
- Power source: 3-cell Li-ion battery pack
- Load: 12 V DC fan

## Measurements

| Parameter | Reading |
|---|---:|
| Multimeter reference current | 0.53 A |
| INA219 measured current | 0.52 A |
| Absolute error | 0.01 A |
| Percentage error | 1.89% |

## Calculation

\[
\text{Percentage Error}=
\frac{|I_{\text{reference}}-I_{\text{INA219}}|}
{I_{\text{reference}}}\times100
\]

\[
=\frac{|0.53-0.52|}{0.53}\times100
\]

\[
=1.89\%
\]

## Preliminary Calibration Factor

\[
K_I=\frac{0.53}{0.52}=1.0192
\]

This is a preliminary single-point correction factor. It has not been applied to the firmware.

## Status

**Initial current measurement validation completed.**

Further testing at different current levels is required before final calibration.

## Next Steps

- Repeat current measurements under different load conditions.
- Compare INA219 and multimeter readings.
- Determine whether a correction factor is necessary.
- Validate power calculations after sensor calibration.
