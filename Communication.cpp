// 
// 
// 

#include "Communication.h"

String CommunicationClass::ReadBytesUntil()
{
	String recivedMessage = "";


	if (Serial.available() > 0)
	{
		Serial.print("RCV: ");
		const int MAX_MESSAGE_LENGTH = 35;
		char buffer[MAX_MESSAGE_LENGTH];
		size_t num_read = Serial.readBytesUntil('#', buffer, sizeof(buffer) - 1);
		buffer[num_read] = '\0'; // Set null at the end since String is NULL-terminated

		Serial.println(buffer);
		recivedMessage = buffer;
	}

	return recivedMessage;
}

String CommunicationClass::Read()
{
	String recivedMessage = "";


	if (Serial.available() > 0)
	{
		Serial.print("RCV: ");
		delay(15);

		// Read byte by byte
		while (Serial.available() > 0)
		{
			char msg = Serial.read(); // Convert byte to Char
			recivedMessage += msg;
		}
		Serial.println(recivedMessage);
	}

	return recivedMessage;
}

void CommunicationClass::init()
{
	Serial.println("Init CommunicationClass");
}


CommunicationClass Communication;

