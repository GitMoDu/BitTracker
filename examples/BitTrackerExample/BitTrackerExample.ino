

#include <BitTracker.h>
#include <HardwareSerial.h>

#define SERIAL_BAUD_RATE 57600


#define TEST_SIZE 200

BitTracker8 Test8(8);
BitTracker16 Test16(16);
BitTracker32 Test32(32);
BitTracker64 Test64(64);
BitTracker128 TestSmallOnLarge(10);


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

	Serial.println(F("Bit Tracker 16"));
	DebugBitTracker(&Test16);

	Serial.println(F("Bit Tracker 32"));
	DebugBitTracker(&Test32);

	Serial.println(F("Bit Tracker 64"));
	DebugBitTracker(&Test64);	

	Serial.println(F("Bit Tracker 128 with only 10 used bits"));
	DebugBitTracker(&TestSmallOnLarge);

	Serial.println();

	Serial.println(F("Bit Tracker Test Complete"));
}

void DebugBitTracker(IBitTracker * bitTracker)
{
	bool Grunt = false;
	Serial.print(F("Clear all: "));
	bitTracker->ClearAllPending();
	OutputBitTrackerStatus(bitTracker);

	Serial.print(F("Set all pending: "));
	bitTracker->SetAllPending();
	OutputBitTrackerStatus(bitTracker);

	Sum = 0;
	for (uint16_t j = 0; j < TEST_SIZE; j++)
	{
		Start = micros();
		for (uint8_t i = 0; i < bitTracker->GetBitCount(); i++)
		{
			Grunt = bitTracker->IsBitPending(i);
		}
		Elapsed = micros() - Start;
		Sum += Elapsed;
	}


	bool NoIgnorePlz = Grunt && bitTracker->GetBitCount() > 0;

	Serial.print(F("Reading "));
	Serial.print(bitTracker->GetBitCount());
	Serial.print(F(" bits took "));
	Serial.print(Sum / (bitTracker->GetBitCount()*TEST_SIZE));
	Serial.println(F(" us per bit."));

	Sum = 0;
	for (uint16_t j = 0; j < TEST_SIZE; j++)
	{
		Start = micros();
		for (uint8_t i = 0; i < bitTracker->GetBitCount(); i++)
		{
			bitTracker->SetBitPending(i);
		}
		Elapsed = micros() - Start;
		Sum += Elapsed;
	}

	Serial.print(F("Writing "));
	Serial.print(bitTracker->GetBitCount());
	Serial.print(F(" bits took "));
	Serial.print(Sum / (bitTracker->GetBitCount()*TEST_SIZE));
	Serial.println(F(" us per bit."));

	Serial.println(F("Random clear walk..."));

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
	Serial.println(F("... done."));

	Serial.println();
}

void OutputBitTrackerStatus(IBitTracker * bitTracker)
{
	Serial.print('[');
	for (uint8_t i = 0; i < bitTracker->GetBitCount(); i++)
	{
		Serial.print(bitTracker->IsBitPending(i));
		if (i < bitTracker->GetBitCount() - 1)
		{
			Serial.print(' ');
		}
	}
	Serial.println(']');
}

void loop()
{
}
