

#include <BitTracker.h>

#define SERIAL_BAUD_RATE 500000

//#define TEST_MAX_SIZE


#define TEST_SIZE 5

TemplateBitTracker<1> TestMin;
TemplateBitTracker<7> Test7;
TemplateBitTracker<16> Test16;
TemplateBitTracker<33> Test33;
TemplateBitTracker<257> Test257;

uint8_t External[32];

TemplateExternalBitTracker<32> Test32External(External);

#ifdef TEST_MAX_SIZE
TemplateBitTracker<UINT16_MAX> TestMax;
#endif



uint32_t Start, Elapsed;
uint8_t CallCounter;

void setup()
{
	Serial.begin(SERIAL_BAUD_RATE);
	while (!Serial)
		;

	delay(1000);

	Serial.println(F("Bit Tracker Example"));
	Serial.println();

	Serial.println(F("Bit Tracker Template 1"));
	Serial.println();
	DebugBitTracker(&TestMin, false);

	Serial.println(F("Bit Tracker Template 7 "));
	Serial.println();
	DebugBitTracker(&Test7, false);

	Serial.println();
	Serial.println(F("Bit Tracker Template 16"));
	DebugBitTracker(&Test16, false);

	Serial.println(F("Bit Tracker Template 33"));
	Serial.println();
	DebugBitTracker(&Test33, true);

	Serial.println(F("Bit Tracker Template 257"));
	Serial.println();
	DebugBitTracker(&Test257, true);

	Serial.println(F("Bit Tracker Template 32 External"));
	Serial.println();
	DebugExternalBitTracker(&Test32External, false);



#ifdef TEST_MAX_SIZE
	Serial.println(F("Bit Tracker Template Max"));
	Serial.println();
	DebugBitTracker(&TestMax, true);
	TemplateBitTracker<UINT16_MAX> TestMax;
#endif


	Serial.println();
	Serial.println();

	Serial.println(F("Bit Tracker Test Complete"));
	Serial.println();
}

void DebugExternalBitTracker(IBitTracker* bitTracker, const bool blockView)
{
	Serial.print(F("Clear all: "));
	bitTracker->ClearAll();
	OutputBitTrackerStatus(bitTracker, blockView);

	Serial.print(F("Set all externally: "));
	External[0] = UINT8_MAX;
	External[1] = UINT8_MAX;
	External[2] = UINT8_MAX;
	External[3] = UINT8_MAX;
	OutputBitTrackerStatus(bitTracker, blockView);

	DebugBitTracker(bitTracker, blockView);
}
void DebugBitTracker(IBitTracker * bitTracker, const bool blockView)
{
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

	Start = micros();
	for (uint16_t j = 0; j < TEST_SIZE; j++)
	{
		for (uint16_t i = 0; i < bitTracker->GetBitCount(); i++)
		{
			Executor += bitTracker->IsBitSet(i);
		}
	}
	Elapsed = micros()*1000 - Start*1000;

	Serial.print(Elapsed / (bitTracker->GetBitCount()*TEST_SIZE));
	Serial.println(F(" ns per bit."));
	Serial.println();


	Serial.print(F("Writing "));
	Serial.print(bitTracker->GetBitCount());
	Serial.print(F(" bits took "));

	Start = micros();
	for (uint16_t j = 0; j < TEST_SIZE; j++)
	{
		for (uint16_t i = 0; i < bitTracker->GetBitCount(); i++)
		{
			bitTracker->SetBit(i);
		}
	}
	Elapsed = micros()*1000 - Start*1000;

	Serial.print(Elapsed / (bitTracker->GetBitCount()*TEST_SIZE));
	Serial.println(F(" ns per bit."));
	Serial.println();

	Serial.println(F("Linear clear walk..."));
	Serial.println();

	Serial.print(bitTracker->GetSize());
	Serial.print(F(" bytes for: "));
	Serial.print(bitTracker->GetBitCount());
	Serial.println(F(" bits."));
	Serial.println();

	OutputBitTrackerStatus(bitTracker, blockView);

	uint16_t ClearIndex = 0;

	while (bitTracker->HasSet())
	{
		if (blockView)
		{
			bool BlockClear = true;
			for (uint16_t i = 0; (i < bitTracker->GetBitCount()) && BlockClear; i++)
			{
				if (bitTracker->IsBitSet(ClearIndex + i))
				{
					BlockClear = false;
				}
			}

			if (!BlockClear)
			{
				bitTracker->OverrideBlock(0, ClearIndex);
				if(bitTracker->GetSize() < 100)
					OutputBitTrackerStatus(bitTracker, blockView);
			}
		}
		else
		{
			if (bitTracker->IsBitSet(ClearIndex))
			{
				bitTracker->ClearBit(ClearIndex);
				OutputBitTrackerStatus(bitTracker, blockView);
			}
		}
		ClearIndex++;
	}
	Serial.println(F("... done."));
	Serial.println();

	Serial.println();
}

void OutputBitTrackerStatus(IBitTracker * bitTracker, const bool blockView)
{
	uint16_t Size;
	if (blockView)
	{
		Size = bitTracker->GetSize();
	}
	else
	{
		Size = bitTracker->GetSize() * BITS_IN_BYTE;
	}

	Serial.print('[');
	for (uint16_t i = 0; i < Size; i++)
	{
		if (blockView)
		{
			if (bitTracker->GetRawBlock(i) > 0)
			{
				Serial.print('#');
			}
			else
			{
				Serial.print('_');
			}
		}
		else
		{
			Serial.print(bitTracker->IsBitSet(i) > 0);
		}

		if (i < Size - 1)
		{
			Serial.print(' ');
		}
	}
	Serial.println(']');
	Serial.println();
}

void loop()
{
}
