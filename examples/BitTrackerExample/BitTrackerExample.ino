

#include <BitTracker.h>
#include <HardwareSerial.h>

#define SERIAL_BAUD_RATE 115200


#define TEST_SIZE 50


BitTracker8<7> Test8;
TemplateBitTracker<16> Test16;
TemplateBitTracker<30> Test32;
TemplateBitTracker<63> Test64;
TemplateBitTracker<257> TestLarge;


uint32_t Start, Elapsed;
uint8_t CallCounter;
uint32_t Sum;

void setup()
{
	Serial.begin(SERIAL_BAUD_RATE);
	while (!Serial)
		;

	delay(1000);

	randomSeed(analogRead(0));

	Serial.println(F("Bit Tracker Example"));

	Serial.println(F("Bit Tracker 8 "));
	DebugBitTracker(&Test8, false);

	Serial.println(F("Bit Tracker Template 16"));
	DebugBitTracker(&Test16, false);

	Serial.println(F("Bit Tracker Template 30"));
	DebugBitTracker(&Test32, true);

	Serial.println(F("Bit Tracker Template 63"));
	DebugBitTracker(&Test64, true);	

	Serial.println(F("Bit Tracker Template 257"));
	DebugBitTracker(&TestLarge, true);

	Serial.println();

	Serial.println(F("Bit Tracker Test Complete"));
}

void DebugBitTracker(IBitTracker * bitTracker, const bool blockView)
{
	Serial.print(bitTracker->GetSize());
	Serial.print(F(" bytes for: "));
	Serial.print(bitTracker->GetBitCount());
	Serial.println(F(" bits."));

	Serial.print(F("Clear all: "));
	bitTracker->ClearAll();
	OutputBitTrackerStatus(bitTracker, blockView);

	Serial.print(F("Set all: "));
	bitTracker->SetAll();
	OutputBitTrackerStatus(bitTracker, blockView);


	Serial.print(F("Reading "));
	Serial.print(bitTracker->GetBitCount());
	Serial.print(F(" bits took "));

	uint8_t Executor = 0;
	Sum = 0;
	for (uint16_t j = 0; j < TEST_SIZE; j++)
	{
		Start = micros();
		for (uint16_t i = 0; i < bitTracker->GetBitCount(); i++)
		{
			Executor += bitTracker->IsBitSet(i);
		}
		Elapsed = micros() - Start;
		Sum += Elapsed;
	}

	Serial.print(Sum / (bitTracker->GetBitCount()*TEST_SIZE));
	Serial.println(F(" us per bit."));


	Serial.print(F("Writing "));
	Serial.print(bitTracker->GetBitCount());
	Serial.print(F(" bits took "));
	Sum = 0;
	for (uint16_t j = 0; j < TEST_SIZE; j++)
	{
		Start = micros();
		for (uint16_t i = 0; i < bitTracker->GetBitCount(); i++)
		{
			bitTracker->SetBit(i);
		}
		Elapsed = micros() - Start;
		Sum += Elapsed;
	}


	Serial.print(Sum / (bitTracker->GetBitCount()*TEST_SIZE));
	Serial.println(F(" us per bit."));

	Serial.println(F("Random clear walk..."));

	OutputBitTrackerStatus(bitTracker, blockView);
	while (bitTracker->HasSet())
	{
		uint16_t RandomIndex = random(bitTracker->GetBitCount());

		if (bitTracker->IsBitSet(RandomIndex))
		{
			bitTracker->ClearBit(RandomIndex);
			OutputBitTrackerStatus(bitTracker, blockView);
		}
	}
	Serial.println(F("... done."));

	Serial.println();
}

void OutputBitTrackerStatus(IBitTracker * bitTracker, const bool blockView)
{
	if (blockView)
	{
		Serial.print('[');
		for (uint16_t i = 0; i < bitTracker->GetSize(); i++)
		{
			Serial.print(bitTracker->GetRawBlock(i) > 0);
			if (i < bitTracker->GetSize() - 1)
			{
				Serial.print(' ');
			}
		}
		Serial.println(']');

	}
	else
	{
		uint16_t MaximumBitCount = bitTracker->GetSize() * BITS_IN_BYTE;
		Serial.print('[');
		for (uint16_t i = 0; i < MaximumBitCount; i++)
		{
			Serial.print(bitTracker->IsBitSet(i));
			if (i < MaximumBitCount - 1)
			{
				Serial.print(' ');
			}
		}
		Serial.println(']');
	}
}

void loop()
{
}
