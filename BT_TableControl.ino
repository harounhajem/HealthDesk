#include "Communication.h"
#define BUTTON_UP 5
#define BUTTON_DOWN 6

CommunicationClass communication;

char msg;
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


	recivedMessage = "";
}

void Reset() {
	if (millis() - timer_ResetComndDelay > 80UL) {
		digitalWrite(BUTTON_UP, LOW);
		digitalWrite(BUTTON_DOWN, LOW);
	}
}

void MoveUp()
{
	digitalWrite(BUTTON_UP, HIGH);
}

void MoveDown()
{
	digitalWrite(BUTTON_DOWN, HIGH);
}