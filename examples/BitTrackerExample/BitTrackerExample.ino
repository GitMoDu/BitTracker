

#include <BitTracker.h>

#define SERIAL_BAUD_RATE 9600

//#define TEST_MAX_SIZE


#define TEST_SIZE 100


BitTracker8<1> TestMin;
BitTracker8<7> Test7;
BitTracker8<16> Test16;
BitTracker8<17> Test17;
BitTracker8< 33> Test33;
BitTracker16< 257> Test257;

uint8_t External[32];
BitTracker8External<32> Test32External(External);

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
	DebugBitTracker<uint8_t, 1>(&TestMin, false);

	Serial.println(F("Bit Tracker Template 7 "));
	Serial.println();
	DebugBitTracker<uint8_t, 7>(&Test7, false);

	Serial.println();
	Serial.println(F("Bit Tracker Template 16"));
	DebugBitTracker<uint8_t, 16>(&Test16, false);

	Serial.println();
	Serial.println(F("Bit Tracker Template 17"));
	DebugBitTracker<uint8_t, 17>(&Test17, false);

	Serial.println(F("Bit Tracker Template 32 External"));
	Serial.println();
	DebugExternalBitTracker<uint8_t, 32>(&Test32External, false);

	Serial.println(F("Bit Tracker Template 33"));
	Serial.println();
	DebugBitTracker<uint8_t, 33>(&Test33, true);

	Serial.println(F("Bit Tracker Template 257"));
	Serial.println();
	DebugBitTracker<uint16_t, 257>(&Test257, true);





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

template<typename UInt, const UInt BitCount>
void DebugExternalBitTracker(TemplateExternalBitTracker<UInt, BitCount>* bitTracker, const bool blockView)
{
	Serial.print(F("Clear all: "));
	bitTracker->ClearAll();
	OutputBitTrackerStatus<TemplateExternalBitTracker<UInt, BitCount>>(bitTracker, blockView);

	Serial.print(F("Set all externally: "));
	External[0] = UINT8_MAX;
	External[1] = UINT8_MAX;
	External[2] = UINT8_MAX;
	External[3] = UINT8_MAX;
	OutputBitTrackerStatus<TemplateExternalBitTracker<UInt, BitCount>>(bitTracker, blockView);
}

template<typename UInt, const UInt BitCount>
void DebugBitTracker(TemplateBitTracker<UInt, BitCount>* bitTracker, const bool blockView)
{
	Serial.print(F("Clear all: "));
	bitTracker->ClearAll();
	OutputBitTrackerStatus<TemplateBitTracker<UInt, BitCount>>(bitTracker, blockView);

	Serial.print(F("Set all: "));
	bitTracker->SetAll();
	OutputBitTrackerStatus<TemplateBitTracker<UInt, BitCount>>(bitTracker, blockView);

	Serial.print(F("Reading "));
	Serial.print(bitTracker->GetBitCount());
	Serial.print(F(" bits took "));

	volatile uint8_t executor = 0;

	Start = micros();
	for (size_t j = 0; j < TEST_SIZE; j++)
	{
		for (size_t i = 0; i < bitTracker->GetBitCount(); i++)
		{
			executor++;
		}
	}
	const uint32_t calibration = micros() * 1000 - Start * 1000;

	for (size_t j = 0; j < TEST_SIZE; j++)
	{
		for (size_t i = 0; i < bitTracker->GetBitCount(); i++)
		{
			bitTracker->IsBitSet(i);
			executor++;
		}
	}
	Elapsed = micros() * 1000 - Start * 1000;

	Serial.print((Elapsed - calibration) / (bitTracker->GetBitCount() * TEST_SIZE));
	Serial.println(F(" ns per bit."));
	Serial.println();


	Serial.print(F("Writing "));
	Serial.print(bitTracker->GetBitCount());
	Serial.print(F(" bits took "));

	Start = micros();
	for (size_t j = 0; j < TEST_SIZE; j++)
	{
		for (size_t i = 0; i < bitTracker->GetBitCount(); i++)
		{
			bitTracker->SetBit(i);
			executor++;
		}
	}
	Elapsed = micros() * 1000 - Start * 1000;

	Serial.print((Elapsed - calibration) / (bitTracker->GetBitCount() * TEST_SIZE));
	Serial.println(F(" ns per bit."));
	Serial.println();

	Serial.println(F("Linear clear walk..."));
	Serial.println();

	Serial.print(bitTracker->GetSize());
	Serial.print(F(" bytes for: "));
	Serial.print(bitTracker->GetBitCount());
	Serial.println(F(" bits."));
	Serial.println();

	OutputBitTrackerStatus<TemplateBitTracker<UInt, BitCount>>(bitTracker, blockView);

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
				if (bitTracker->GetSize() < 100)
					OutputBitTrackerStatus<TemplateBitTracker<UInt, BitCount>>(bitTracker, blockView);
			}
		}
		else
		{
			if (bitTracker->IsBitSet(ClearIndex))
			{
				bitTracker->ClearBit(ClearIndex);
				OutputBitTrackerStatus<TemplateBitTracker<UInt, BitCount>>(bitTracker, blockView);
			}
		}
		ClearIndex++;
	}
	Serial.println(F("... done."));
	Serial.println();

	Serial.println();
}

template<class BitTrackerType>
void OutputBitTrackerStatus(BitTrackerType* bitTracker, const bool blockView)
{
	uint16_t Size;
	if (blockView)
	{
		Size = bitTracker->GetSize();
	}
	else
	{
		Size = bitTracker->GetSize() * BitTracker::BITS_IN_BYTE;
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
