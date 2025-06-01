# Path Following Car 

This project demonstrates an automatic car parking system using infrared (IR) sensors for path detection and slot monitoring, integrated with an LCD display for real-time parking status. The system is developed as part of a semester project for LINEAR CIRCUIT ANALYSIS as an Electrical Engineering student.

## Overview

The project focuses on building a robotic car capable of following a predefined path and autonomously parking itself when it reaches a designated area. Infrared sensors are used to detect path lines and vacant parking spots, while a 16x2 LCD, interfaced via an I2C module, displays parking availability.

---

## Hardware Components

- **Arduino UNO** – Microcontroller to control the entire system.
- **L293D Motor Driver** – Drives the motors based on input from the Arduino.
- **IR Sensors** – Used to detect black/white path lines and sense occupied or vacant parking spaces.
- **16x2 LCD with I2C Module** – Displays parking slot availability and system messages.
- **DC Motors & Chassis Kit** – Forms the base of the robotic car.
- **Li-ion Batteries (3.7V)** – Power source for the system.

---

## Working Principle

- **Path Following:**  
  IR sensors mounted underneath the car detect a black path on a white surface. Based on which sensor (left or right) detects the path, the Arduino adjusts motor speeds using the L293D driver to navigate accordingly.

- **Parking Detection:**  
  When the car reaches the parking zone, additional IR sensors detect the presence or absence of a vehicle in the slot.

- **LCD Display:**  
  The parking status ("Available" or "Parked") is shown on a 16x2 LCD. It updates in real-time based on IR sensor readings.

---

## Software & Programming

- **IDE Used:** Arduino IDE  
  All code is written and uploaded using the Arduino IDE. It includes libraries such as `AFMotor.h` for motor control and `Wire.h` for I2C communication.

- **Key Features of Code:**
  - Reads analog values from IR sensors.
  - Uses conditional logic to control direction and speed of motors.
  - Displays real-time parking status on LCD.
  - Stops the car when the parking slot is reached.

---

## Conclusion

This project provides a practical demonstration of integrating hardware components and sensor-based automation to develop a low-cost smart parking prototype.
