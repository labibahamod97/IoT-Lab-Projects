# IoT-Lab-Projects
Arduino sends Morse code using LED flashes, and an LDR sensor receives the light pulses. The transmitter converts text into timed dots and dashes. The receiver measures ON/OFF durations, decodes the Morse symbols, and shows the translated text on an I2C LCD.


# **Arduino Morse Code Transmitter & Receiver**

## **Overview**

This project uses two Arduino systems to send and receive Morse code through visible light.
The transmitter converts text into Morse patterns and flashes an LED or relay-controlled lamp.
The receiver uses an LDR sensor to read the light pulses, decode the timing, and display the translated message on an I2C LCD.
This setup demonstrates a simple optical communication system similar to Li-Fi.

---

## **Features**

* Converts normal text into Morse code
* Sends Morse using an LED or relay
* Detects light pulses with an LDR module
* Decodes dots, dashes, letter gaps, and word gaps
* Real-time output on a 16×2 I2C LCD
* Works with any light source, including a phone flashlight
* Low-cost components
* Simple C/C++ code for Arduino

---

## **Hardware Requirements**

### **Transmitter**

* Arduino UNO/Nano
* LED or relay module
* 220Ω resistor (if LED is used)
* USB cable

### **Receiver**

* Arduino UNO/Nano
* LDR sensor module (AO / DO / VCC / GND)
* 16×2 I2C LCD
* Jumper wires

---

## **Connections**

### **Transmitter**

| Component   | Arduino Pin |
| ----------- | ----------- |
| LED / Relay | Pin 13      |
| GND         | GND         |

### **Receiver**

| Component | Arduino Pin |
| --------- | ----------- |
| LDR AO    | A2          |
| LDR VCC   | 5V          |
| LDR GND   | GND         |
| LCD SDA   | A4          |
| LCD SCL   | A5          |
| LCD VCC   | 5V          |
| LCD GND   | GND         |

---

## **How It Works**

### **Transmitter**

1. User enters text in Serial Monitor.
2. Arduino converts each character into Morse symbols.
3. LED or relay flashes for dots and dashes.
4. Off timing separates symbols, letters, and words.

### **Receiver**

1. LDR monitors brightness changes.
2. Short ON = dot, long ON = dash.
3. Short OFF = same letter, medium OFF = new letter, long OFF = new word.
4. Arduino translates Morse patterns into characters.
5. Output appears on the LCD.

---

## **Default Morse Timing**

| Morse Element | Duration (ms) |
|---------------|---------------|
| Dot           | <= 250        |
| Dash Min      | >= 251        |
| Dash Max      | <= 650        |
| Letter Gap    | 650           |
| Word Gap      | 1450          |



---

## **Folder Structure**

```
/Transmitter
   └── transmitter.ino

/Receiver
   └── receiver.ino

README.md
```

---

## **Example Transmission**

**Input:** HELLO
**Process:** LED flashes Morse code
**Output:** HELLO (on receiver LCD)

---

## **Applications**

* Optical communication
* Li-Fi demonstration
* Educational projects
* Emergency signaling
* Arduino learning projects

---

## **Future Improvements**

* Adaptive threshold for light intensity
* Stronger external light support
* Two-way communication
* Save received messages in EEPROM
* Optional WiFi logging with ESP32


