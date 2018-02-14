#include "Communication.h"
#define BUTTON_UP 6
#define BUTTON_DOWN 5

CommunicationClass communication;

String recivedMessage;

String COMMAND_UP = "UP";
String COMMAND_DOWN = "DN";

unsigned long timer_ResetComndDelay = 0;


void setup()
{
	Serial.begin(9600);
	pinMode(BUTTON_UP, OUTPUT);
	pinMode(BUTTON_DOWN, OUTPUT);
}

void loop()
{

	// Recive message
	recivedMessage = communication.ReadBytesUntil();


	// Execute Command
	if (recivedMessage == COMMAND_UP)
	{
		Serial.println("EXEC: UP");
		MoveUp();
		timer_ResetComndDelay = millis();
	}
	else if (recivedMessage == COMMAND_DOWN)
	{
		Serial.println("EXEC: DOWN");
		MoveDown();
		timer_ResetComndDelay = millis();

	}
	else if (recivedMessage == "") {
		Reset();
	}

	// Execute Timer
	// - blink and play sound
	// - cancel timer if user pushes buttons breaks



}

void Reset() {
	if (millis() - timer_ResetComndDelay > 12UL) {
		digitalWrite(BUTTON_UP, HIGH);
		digitalWrite(BUTTON_DOWN, HIGH);
	}
}

void MoveUp()
{
	digitalWrite(BUTTON_UP, LOW);
}

void MoveDown()
{
	digitalWrite(BUTTON_DOWN, LOW);
}