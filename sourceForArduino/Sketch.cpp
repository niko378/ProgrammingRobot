/*
* WeGotThisOne.cpp
*
* Created: 2018-01-28 4:50:14 AM
* Author : nic
*/

#include <avr/io.h>
#include <Arduino.h>
#define TMP_REQUIS 1500

char data[] = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
void setup()
{
	Serial.begin(9600);   //Sets the baud for serial data transmission
	pinMode(13, OUTPUT);  //Sets digital pin 13 as output pin
	pinMode(12, OUTPUT);
	Serial.print("AT+NAMErobot1");
	
}
void loop()
{
	if (Serial.available() > 0)     // Send data only when you receive data:
	{
						
		Serial.readBytesUntil(99, data, 15);        //Read the incoming data & store into data
		for(int i = 0 ; i < 15 ; i++)
		{
			Serial.print(data[i] - '0');          //conversion char -> nombre
			if (data[i] == 1)       //avancer
			{
				digitalWrite(13, HIGH);
				digitalWrite(12, HIGH);
			}
			else if (data[i] == 2)  //droite
			digitalWrite(13, HIGH);
			else if (data[i] == 3)   //gauche
			digitalWrite(12, HIGH);
			else if (data[i] == 100) {
				break;
			}
			_delay_ms(TMP_REQUIS);
			digitalWrite(13, LOW);
			digitalWrite(12, LOW);
			_delay_ms(1000); 
			
		}
	}
}
