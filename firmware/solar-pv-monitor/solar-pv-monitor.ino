
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_INA219.h>

// ------------------------------
// HARDWARE CONFIGURATION
// ------------------------------

#define VOLTAGE_PIN A0

// Replace with your detected LCD address
#define LCD_ADDRESS 0x27

#define LCD_COLUMNS 16
#define LCD_ROWS 2

LiquidCrystal_I2C lcd(
  LCD_ADDRESS,
  LCD_COLUMNS,
  LCD_ROWS
);

Adafruit_INA219 ina219;

// ------------------------------
// B25 CALIBRATION PARAMETERS
// ------------------------------

const float ADC_REFERENCE_VOLTAGE = 5.0;
const float DIVIDER_RATIO = 5.0;
const float ADC_RESOLUTION = 1023.0;

// Temporary nominal calibration.
// We will refine this using a multimeter.
const float VOLTAGE_CALIBRATION = 1.0;

// ------------------------------
// MEASUREMENT VARIABLES
// ------------------------------

float pvVoltage = 0.0;
float pvCurrent = 0.0;
float pvPower = 0.0;

int adcValue = 0;

// ------------------------------
// SETUP
// ------------------------------

void setup() {

  Serial.begin(9600);
  Wire.begin();

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Solar PV Monitor");

  lcd.setCursor(0, 1);
  lcd.print("Initializing...");

  delay(1500);

  if (!ina219.begin()) {

    lcd.clear();
    lcd.print("INA219 Error!");

    Serial.println("ERROR: INA219 not detected!");

    while (1) {
      delay(10);
    }
  }

  lcd.clear();

  Serial.println("==============================");
  Serial.println("SOLAR PV MONITORING SYSTEM");
  Serial.println("==============================");

  Serial.println("INA219 initialized.");
  Serial.println("B25 voltage input: A0");
  Serial.println("LCD initialized.");

  delay(1000);
}

// ------------------------------
// READ B25 VOLTAGE
// ------------------------------

float readPVVoltage() {

  adcValue = analogRead(VOLTAGE_PIN);

  float sensorVoltage =
    (adcValue * ADC_REFERENCE_VOLTAGE)
    / ADC_RESOLUTION;

  float inputVoltage =
    sensorVoltage
    * DIVIDER_RATIO
    * VOLTAGE_CALIBRATION;

  return inputVoltage;
}

// ------------------------------
// READ INA219 CURRENT
// ------------------------------

float readPVCurrent() {

  float current_mA = ina219.getCurrent_mA();

  return current_mA / 1000.0;
}

// ------------------------------
// DISPLAY MEASUREMENTS
// ------------------------------

void displayMeasurements() {

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("V:");
  lcd.print(pvVoltage, 2);
  lcd.print("V");

  lcd.setCursor(0, 1);
  lcd.print("I:");
  lcd.print(pvCurrent, 2);
  lcd.print("A P:");
  lcd.print(pvPower, 2);
  lcd.print("W");
}

// ------------------------------
// SERIAL MONITOR OUTPUT
// ------------------------------

void printMeasurements() {

  Serial.println("------------------------------");

  Serial.print("PV Voltage: ");
  Serial.print(pvVoltage, 3);
  Serial.println(" V");

  Serial.print("PV Current: ");
  Serial.print(pvCurrent, 3);
  Serial.println(" A");

  Serial.print("PV Power: ");
  Serial.print(pvPower, 3);
  Serial.println(" W");

  Serial.print("B25 ADC Value: ");
  Serial.println(adcValue);

  Serial.println("------------------------------");
}

// ------------------------------
// MAIN LOOP
// ------------------------------

void loop() {

  pvVoltage = readPVVoltage();

  pvCurrent = readPVCurrent();

  pvPower = pvVoltage * pvCurrent;

  displayMeasurements();

  printMeasurements();

  delay(1000);
}