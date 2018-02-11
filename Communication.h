// Communication.h

#ifndef _COMMUNICATION_h
#define _COMMUNICATION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class CommunicationClass
{
 protected:


 public:
	 String ReadBytesUntil();
	 String Read();
	void init();
};

extern CommunicationClass Communication;

#endif

