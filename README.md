<div align="center">
  <h1>🌱 Soil Tester with ESP32</h1>
  <p><strong>NPK Sensor + 20x4 I2C LCD + Arduino IDE</strong></p>
</div>

---

## 📦 Project Description

A soil nutrient tester powered by the **ESP32**, featuring a **non-contact NPK soil sensor** and a **20x4 I2C LCD** for real-time display. This project helps analyze soil **Nitrogen (N)**, **Phosphorus (P)**, and **Potassium (K)** levels to support smarter gardening and agriculture.

---

## ⚙️ Components Used

| Component             | Description                         |
|----------------------|-------------------------------------|
| ESP32 Dev Board       | Main microcontroller (Wi-Fi capable) |
| NPK Sensor            | UART soil nutrient sensor (RS485 or TTL) |
| I2C 20x4 LCD Display  | For showing NPK readings             |
| Logic Level Converter | If required (ESP32 is 3.3V logic)   |
| Jumper Wires, Breadboard, 5V Power Supply | Connectivity and power |

---

## 🔌 Wiring Overview

### NPK Sensor to ESP32 (UART/Serial)

| NPK Sensor | ESP32 |
|------------|-------|
| VCC        | 5V    |
| GND        | GND   |
| TX         | RX (GPIO16) |
| RX         | TX (GPIO17) |

### I2C LCD to ESP32

| LCD Pin | ESP32 |
|---------|-------|
| VCC     | 5V    |
| GND     | GND   |
| SDA     | GPIO21 |
| SCL     | GPIO22 |

> 💡 Use `Wire.begin(21, 22);` to define SDA and SCL pins in your Arduino code.

---

## 💻 Arduino Setup

1. **Install Required Libraries**:
   - `LiquidCrystal_I2C`
   - `ModbusMaster` *(if using RS485 NPK sensors)*
   - `Wire.h`

2. **Open the Sketch** from this repo:
   ```bash
   Soil-Tester/SoilTester_ESP32.ino
