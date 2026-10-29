#include <LiquidCrystal.h>
#define sigPin 2 // Connect to the SIG pin on your sensor

long duration;
int distance;
LiquidCrystal lcd(12, 11, 8, 7, 6, 5);

void setup() {
    Serial.begin(9600);
    Serial.println("Distance measurement using 3-Pin/SIG Ultrasonic Sensor.");
    delay(500);

    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Distance Monitor");
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

    lcd.setCursor(0, 1);
    lcd.print("Dist: ");
    lcd.print(distance);
    lcd.print("cm   ");

    delay(100); // Wait before the next reading
    if(distance > 40) {
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("where my hug at?");

	} else if (distance < 10) {
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("PDIDDY NO");

	} else {    
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("no no square");
	}

}
