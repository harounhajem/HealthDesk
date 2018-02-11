#define BUTTON_UP 5
#define BUTTON_DOWN 6

char msg;
String recivedMessage;
boolean upAction_isActive = true,
downAction_isActive = true;

String COMMAND_UP = "UP";
String COMMAND_DOWN = "DN";



void setup()
{
	Serial.begin(9600);
	pinMode(BUTTON_UP, OUTPUT);
	pinMode(BUTTON_DOWN, OUTPUT);
}

void loop()
{



	// Recive command
	if (Serial.available() > 0)
	{
		Serial.print("MSG: ");
		recivedMessage = "";
		delay(2);

		// decypher
		while (Serial.available() > 0)
		{
			msg = Serial.read();
			Serial.print(msg);
			recivedMessage += msg;
		}
		Serial.println(recivedMessage);

	}


	// Execute command
	if (recivedMessage == COMMAND_UP)
	{
		Serial.println("UP");
		MoveUp();
	}
	else if (recivedMessage == COMMAND_DOWN)
	{
		Serial.println("DOWN");
		MoveDown();
	}


	recivedMessage = "";
}


void MoveUp()
{
	if (upAction_isActive) {
		analogWrite(BUTTON_UP, 255);
	}
	else {
		analogWrite(BUTTON_UP, 0);
	}
	upAction_isActive = !upAction_isActive;
}

void MoveDown()
{
	if (downAction_isActive) {
		analogWrite(BUTTON_DOWN, 255);
	}
	else
	{
		analogWrite(BUTTON_DOWN, 0);
	}
	downAction_isActive = !downAction_isActive;
}