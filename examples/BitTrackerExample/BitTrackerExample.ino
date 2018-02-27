

#include <BitTracker.h>
#include <HardwareSerial.h>

#define SERIAL_BAUD_RATE 57600

BitTracker8 Test8;
BitTracker16 Test16;
BitTrackerArray TestArray;


uint32_t Start, Elapsed;
uint8_t CallCounter;
uint32_t Sum;

void setup()
{
	Serial.begin(SERIAL_BAUD_RATE);
	while (!Serial)
		;

	randomSeed(analogRead(0));

	Serial.println(F("Bit Tracker Example"));

	Serial.println(F("Bit Tracker 8 "));
	DebugBitTracker(&Test8);
	Serial.println(F("Bit Tracker 16 "));
	DebugBitTracker(&Test16);
	Serial.println(F("Bit Tracker 128 "));
	DebugBitTracker(&TestArray);
}

void DebugBitTracker(AbstractBitTracker * bitTracker)
{
	bool Grunt = false;
	bitTracker->ClearAllPending();
	OutputBitTrackerStatus(bitTracker);

	bitTracker->SetAllPending();
	OutputBitTrackerStatus(bitTracker);

	Start = micros();
	for (uint8_t i = 0; i < bitTracker->GetBitCount(); i++)
	{
		Grunt = bitTracker->IsBitPending(i);
	}
	Elapsed = micros() - Start;

	bool NoIgnorePlz = Grunt && bitTracker->GetBitCount() > 0;

	Serial.print(F("Reading "));
	Serial.print(bitTracker->GetBitCount());
	Serial.print(F(" bits took "));
	Serial.print(Elapsed);
	Serial.println(F(" us."));

	Start = micros();
	for (uint8_t i = 0; i < bitTracker->GetBitCount(); i++)
	{
		bitTracker->SetBitPending(i);
	}
	Elapsed = micros() - Start;

	Serial.print(F("Writing "));
	Serial.print(bitTracker->GetBitCount());
	Serial.print(F(" bits took "));
	Serial.print(Elapsed);
	Serial.println(F(" us."));

	Serial.println(F(""));

	OutputBitTrackerStatus(bitTracker);
	while (bitTracker->HasPending())
	{
		uint8_t RandomIndex = random(bitTracker->GetBitCount());
		if (bitTracker->IsBitPending(RandomIndex))
		{
			bitTracker->ClearBitPending(RandomIndex);
			OutputBitTrackerStatus(bitTracker);
		}
	}

	Serial.println();
	Serial.println();
}

void OutputBitTrackerStatus(AbstractBitTracker * bitTracker)
{
	Serial.print(F("["));
	for (uint8_t i = 0; i < bitTracker->GetBitCount(); i++)
	{
		Serial.print(bitTracker->IsBitPending(i));
		if (i < bitTracker->GetBitCount() - 1)
		{
			Serial.print(F(","));
		}
	}
	Serial.println(F("]"));
}

void loop()
{

  /* add main program code here */

}
