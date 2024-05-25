Bluetooth and Wi-Fi Lightbulb Control System

This project enables the control of multiple lightbulbs using both Bluetooth and Wi-Fi connections. It utilizes the ESP32 microcontroller, which allows for seamless integration with both wireless technologies.
Features

    Control lightbulbs remotely via Bluetooth or Wi-Fi.
    Supports individual control for each lightbulb (bedroom, bathroom, kitchen).
    Simple integration with home automation systems through the Espalexa library.
    Easy setup and configuration.

Hardware Requirements

    ESP32 microcontroller board (e.g., ESP32 DevKitC).
    Lightbulbs connected to GPIO pins for control.
    Bluetooth-enabled device for Bluetooth control.
    Wi-Fi network for Wi-Fi control.
    Alexa Echo Dot

Software Dependencies

    Arduino IDE or compatible IDE.
    ESP32 Arduino Core installed in the Arduino IDE.
    Espalexa library for Alexa integration.
    Arduino libraries for Wi-Fi and Bluetooth support.

Installation and Setup

    Connect the lightbulbs to the designated GPIO pins on the ESP32 board.
    Install the necessary libraries in your Arduino IDE.
    Open the provided sketch (espalexa.ino) in the Arduino IDE.
    Customize the Wi-Fi credentials (ssid and password) to match your network.
    Upload the sketch to your ESP32 board.
    Power on the ESP32 board and ensure it connects to your Wi-Fi network.

Usage

    Bluetooth Control: Pair your Bluetooth-enabled device with the ESP32 board. Send commands (0-5) to control individual lightbulbs. Use '8' to turn all bulbs on simultaneously and '9' to turn all bulbs off.

    Wi-Fi Control: Once connected to the same Wi-Fi network as the ESP32 board, integrate it with your home automation system through the Espalexa library. You can then control the lightbulbs using voice commands via Alexa or any compatible device.

Troubleshooting

    If encountering issues with Wi-Fi connectivity, ensure the ESP32 board is within range of your Wi-Fi router and the credentials are correct.
    Check for any conflicts with GPIO pin assignments or hardware connections.
    Refer to the Arduino IDE's serial monitor for debugging messages.

Credits

    Developed by cristinapopei
    Inspired by projects from the Arduino and ESP32 communities.
