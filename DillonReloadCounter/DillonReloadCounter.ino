/*
 Name:		DillonReloadCounter.ino
 Created:	3/18/18 7:48:39 PM
 Author:	christophermckearn
*/

//Constants:
const int ledPin = 3;   //pin 3 has PWM funtion
const int flexPin = A0; //pin A0 to read analog input

						//Variables:
int value; //save analog value

void setup() {

	pinMode(ledPin, OUTPUT);  //Set pin 3 as 'output'
	Serial.begin(9600);       //Begin serial communication

}

void loop() {

	value = analogRead(flexPin);         //Read and save analog value from potentiometer
										 //Serial.println(value);               //Print value
	value = map(value, 700, 900, 0, 255);//Map value 0-1023 to 0-255 (PWM)
	analogWrite(ledPin, value);          //Send PWM value to led

	delay(100); //Small delay

	int count = 0;  //the flex sensor at rest is plus or minus 2 around 699.
					//So, any value over 705 I want to count as a bullet passing the sensor. 
					//I'm super frustrated that I can't figure this out.
	for (int i = 0; value >= 100; i++) {
		Serial.print("Total Bullet Count: ");
		Serial.println(value + i);

	}
}