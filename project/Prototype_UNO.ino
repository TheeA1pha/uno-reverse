#include "Ultrasonic.h"

Ultrasonic ultrasonic(7);
void setup()
{
	pinMode(2, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(13, OUTPUT);

	Serial.begin(9600);
}

void loop()
{
	long RangeInInches;
	long RangeInCentimeters;
	
	Serial.println("The distance to obstacles in front is: ");
	
	RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
	Serial.print(RangeInCentimeters);//0~400cm
	Serial.println(" cm");
	delay(250);

	if(RangeInCentimeters > 100) {
		digitalWrite(2, LOW);
		digitalWrite(8, LOW);
		digitalWrite(13, HIGH);
	} else if (RangeInCentimeters < 10) {
		digitalWrite(13, LOW);
		digitalWrite(8, LOW);
		digitalWrite(2, HIGH);
	} else {
		digitalWrite(2, LOW);
		digitalWrite(13, LOW);
		digitalWrite(8, HIGH);
	}
	}