#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIG_PIN 9
#define ECHO_PIN 10
#define BUZZER_PIN 6
#define WARNING_DISTANCE 10  // Distance threshold in cm

// Initialize LCD with I2C address 0x27 (change if needed)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    
    lcd.begin();
    lcd.backlight();

    lcd.setCursor(0, 0);
    lcd.print("Distance Meter");
    delay(2000);
    lcd.clear();
}

long measureDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    long distance = duration * 0.034 / 2;  // Convert to cm
    return distance;
}

void loop() {
    long distance = measureDistance();

    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.setCursor(10, 0);
    lcd.print(distance);
    lcd.print(" cm   ");  // Extra spaces to clear old values

    if (distance > 400 || distance <= 0) {
        lcd.setCursor(0, 1);
        lcd.print("Out of range! ");
        digitalWrite(BUZZER_PIN, LOW);
    } else {
        lcd.setCursor(0, 1);
        lcd.print("Safe Distance ");
        
        if (distance <= WARNING_DISTANCE) {
            digitalWrite(BUZZER_PIN, HIGH); // Turn on buzzer
        } else {
            digitalWrite(BUZZER_PIN, LOW); // Turn off buzzer
        }
    }

    delay(500);
}
