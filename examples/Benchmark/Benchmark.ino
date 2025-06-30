#include <BitTracker.h>

#define SERIAL_BAUD_RATE 9600

#define TEST_SIZE 1000

BitTracker8<1> TestMin;
BitTracker8<7> Test7;
BitTracker8<16> Test16;
BitTracker8<17> Test17;
BitTracker8<33> Test33;
BitTracker16<257> Test257;


void setup()
{
	Serial.begin(SERIAL_BAUD_RATE);
	while (!Serial)
		;

	delay(1000);

	Serial.println(F("Bit Tracker Benchmark"));
	Serial.println();

	Serial.println(F("Bit Tracker Template 1"));
	Serial.println();
	BenchmarkBitTracker<uint8_t, 1>(&TestMin, false);

	Serial.println(F("Bit Tracker Template 7 "));
	Serial.println();
	BenchmarkBitTracker<uint8_t, 7>(&Test7, false);

	Serial.println();
	Serial.println(F("Bit Tracker Template 16"));
	BenchmarkBitTracker<uint8_t, 16>(&Test16, false);

	Serial.println();
	Serial.println(F("Bit Tracker Template 17"));
	BenchmarkBitTracker<uint8_t, 17>(&Test17, false);

	Serial.println(F("Bit Tracker Template 33"));
	Serial.println();
	BenchmarkBitTracker<uint8_t, 33>(&Test33, true);

	Serial.println(F("Bit Tracker Template 257"));
	Serial.println();
	BenchmarkBitTracker<uint16_t, 257>(&Test257, true);
}

template<typename UInt, const UInt BitCount>
void BenchmarkBitTracker(TemplateBitTracker<UInt, BitCount>* bitTracker, const bool blockView)
{
	Serial.print(F("Reading "));
	Serial.print(bitTracker->GetBitCount());
	Serial.print(F(" bits took "));

	volatile uint8_t executor = 0;
	uint32_t compare = 0;
	uint32_t start = micros();
	for (size_t j = 0; j < TEST_SIZE; j++)
	{
		for (UInt i = 0; i < bitTracker->GetBitCount(); i++)
		{
			bitTracker->IsBitSet(i);
			executor++;
		}
	}
	uint64_t durationNanos = uint64_t(micros() - start) * 1000;
	uint32_t stepSumNanos = durationNanos / bitTracker->GetBitCount();
	uint32_t stepAverageNanos = stepSumNanos / TEST_SIZE;

	Serial.print(stepAverageNanos);
	Serial.println(F(" ns per bit."));

	Serial.print(F("Writing "));
	Serial.print(bitTracker->GetBitCount());
	Serial.print(F(" bits took "));

	start = micros();
	for (size_t j = 0; j < TEST_SIZE; j++)
	{
		for (UInt i = 0; i < bitTracker->GetBitCount(); i++)
		{
			executor++;
			bitTracker->SetBit(i);
		}
	}
	durationNanos = uint64_t(micros() - start) * 1000;
	stepSumNanos = durationNanos / bitTracker->GetBitCount();
	stepAverageNanos = stepSumNanos / TEST_SIZE;

	Serial.print(stepAverageNanos);
	Serial.println(F(" ns per bit."));
}

void loop()
{
}
