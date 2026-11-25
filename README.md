\# Solar PV Monitoring System



An Arduino-based instrumentation system designed to monitor the electrical output of a photovoltaic (PV) solar panel.



The system measures voltage and current at the PV panel output, calculates electrical power, and displays measurement data through an LCD interface.



\## Project Overview



Photovoltaic systems convert solar energy into electrical energy. Monitoring their electrical parameters helps evaluate panel performance and understand the behaviour of the connected electrical load.



This project explores a low-cost embedded monitoring system using an Arduino microcontroller and interfaced measurement sensors.



\## Key Features



\- Solar PV output voltage measurement.

\- PV output current measurement.

\- Electrical power calculation.

\- Real-time LCD display.

\- Serial communication for measurement monitoring.

\- Potential integration with PC-based data logging.



\## System Architecture



```text

&#x20;      SOLAR PV PANEL

&#x20;             |

&#x20;      +------+------+

&#x20;      |             |

&#x20; Voltage Sensor  Current Sensor

&#x20;      |             |

&#x20;      +------+------+

&#x20;             |

&#x20;        ARDUINO UNO

&#x20;             |

&#x20;      +------+------+

&#x20;      |             |

&#x20;  LCD DISPLAY   SERIAL OUTPUT

&#x20;                    |

&#x20;               PC MONITORING

```



\## Hardware Components



| Component | Purpose |

|---|---|

| Arduino UNO | Data acquisition and processing |

| PV Solar Panel | DC electrical power source |

| B25 Voltage Sensor | PV voltage measurement |

| Current Sensor | PV output current measurement |

| I2C LCD | Real-time measurement display |

| Connecting wires | Electrical interfacing |



\*The exact current-sensor model and final wiring configuration are subject to hardware verification.\*



\## Software and Tools



\- Arduino IDE

\- Embedded C/C++ (Arduino framework)

\- LiquidCrystal\_I2C library

\- Serial Monitor



\## Working Principle



1\. The photovoltaic panel generates DC electrical power.

2\. Voltage and current sensors acquire the corresponding electrical parameters.

3\. The Arduino reads and processes the sensor outputs.

4\. Electrical power is calculated using:



&#x20;  \\\[

&#x20;  P = V \\times I

&#x20;  \\]



5\. Measurement values are displayed on the LCD.

6\. Serial communication can be used to transmit measurement data to a computer for monitoring and logging.



\## Repository Structure



```text

solar-pv-monitoring-system/

├── docs/

├── firmware/

├── media/

├── README.md

├── LICENSE

└── .gitignore

```



\## Project Status



Hardware interfacing and measurement functionality are being documented and organized.



Further work includes:

\- Verification of sensor configurations.

\- Voltage and current sensor calibration.

\- Validation against reference instruments.

\- Measurement accuracy and error analysis.

\- Improved data acquisition and logging.



\## Safety



Use appropriate precautions when working with photovoltaic systems and electrical loads. Verify sensor ratings, polarity, voltage limits, and current paths before connecting the system.



\## License



This project is intended for educational and engineering development purposes. See the LICENSE file for licensing information.

