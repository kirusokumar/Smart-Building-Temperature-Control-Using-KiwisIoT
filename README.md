# Smart Building Temperature Control Using ESP8266 and KiwisIoT

A simple IoT project to monitor indoor temperature and humidity using a DHT11 sensor, ESP8266 NodeMCU, and KiwisIoT.

## About the Project

This project focuses on monitoring indoor temperature and humidity in a building using IoT technology. The ESP8266 NodeMCU collects environmental data from a DHT11 sensor and sends the readings to the KiwisIoT dashboard through Wi-Fi.

The system also checks the temperature against a predefined threshold and updates the temperature status. This makes it easy to monitor indoor conditions remotely through a cloud dashboard.

## Features

- Real-time temperature monitoring
- Humidity monitoring
- Temperature status indication
- ESP8266 Wi-Fi connectivity
- KiwisIoT cloud dashboard
- Simple and beginner-friendly IoT implementation

## Hardware Components

- ESP8266 NodeMCU
- DHT11 Temperature and Humidity Sensor
- Jumper wires
- USB cable

## Circuit Connections

The DHT11 sensor is connected to the ESP8266 NodeMCU.

| DHT11 | ESP8266 NodeMCU |
|---|---|
| VCC | 3.3V |
| GND | GND |
| DATA | D2 |

## Temperature Status

The system uses a predefined temperature threshold of 30°C.

When the temperature is below 30°C, the system displays `TEMPERATURE NORMAL`.

When the temperature reaches or exceeds 30°C, the system displays `HIGH TEMPERATURE`.

## KiwisIoT Dashboard

The project sends the following information to the KiwisIoT dashboard:

- Channel 0 – Temperature (°C)
- Channel 1 – Humidity (%)
- Channel 2 – Temperature Status

The dashboard allows users to remotely monitor indoor environmental conditions and view the current temperature status.

## Working Principle

The DHT11 sensor measures the temperature and humidity inside the building. The ESP8266 reads the sensor values and compares the temperature with the configured threshold.

The system generates a status based on the temperature reading. The temperature, humidity, and status are then transmitted to KiwisIoT through Wi-Fi.

The dashboard displays the sensor information, helping users monitor the building environment remotely.

## Software Used

- Arduino IDE
- ESP8266 Board Package
- DHT Sensor Library
- KiwisIoT Arduino Library

## Project Tutorial

For the complete project tutorial, circuit details, and implementation, check out the Hackster.io project:

[Smart Building Temperature Control Using KiwisIoT](https://www.hackster.io/kirusokumar/smart-building-temperature-control-using-kiwisiot-5d2ef1)

## Explore KiwisIoT

I use KiwisIoT to connect ESP8266 hardware with a cloud dashboard and monitor project data remotely. It makes IoT projects easier to visualize and helps build connected monitoring applications.

Website: https://www.kiwisiot.in/

Arduino Library: https://github.com/Kiwistron/KiwisIoT

Example Projects: https://github.com/Kiwistron/KiwisIoT-Projects/tree/main

## About the Author

I enjoy building IoT projects, experimenting with sensors and microcontrollers, and exploring ways to connect hardware with cloud platforms. I share my projects to help others learn, experiment, and build their own IoT applications.

---

Built with curiosity, sensors, and IoT.
