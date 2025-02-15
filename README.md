# arduino_ultrasonic_meter

Components Required:
Arduino Uno/Nano
HC-SR04 Ultrasonic Sensor
16x2 LCD with I2C Module
Buzzer
Jumper Wires
Wiring Diagram:
![image](https://github.com/user-attachments/assets/cb4e0bc7-56cc-4556-82f8-97fb9f8628cf)


How It Works:
The HC-SR04 ultrasonic sensor measures distance by sending an ultrasonic pulse and receiving the echo.
The LCD displays the measured distance in centimeters.
If the distance is below 10 cm, the buzzer will activate as a warning.
If the distance is out of range (>400 cm or <=0 cm), the LCD displays "Out of range!".
The display updates every 500 ms.
