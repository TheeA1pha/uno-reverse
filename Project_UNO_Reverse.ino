#include <LiquidCrystal.h>
#define sigPin 7 // Connect to the SIG pin on your sensor

long duration;
int distance;

void setup() {
    Serial.begin(9600);
    Serial.println("Distance measurement using 3-Pin/SIG Ultrasonic Sensor.");
    delay(500);
}

void loop() {
    // 1. Set the pin to OUTPUT to send the trigger pulse
    pinMode(sigPin, OUTPUT);
    digitalWrite(sigPin, LOW);
    delayMicroseconds(2);
    
    digitalWrite(sigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(sigPin, LOW);

    // 2. IMMEDIATELY switch the pin to INPUT to listen for the echo
    pinMode(sigPin, INPUT);
    duration = pulseIn(sigPin, HIGH);

    // 3. Calculate distance
    distance = duration * 0.0344 / 2;

    // 4. Print results
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(100); // Wait before the next reading
}
