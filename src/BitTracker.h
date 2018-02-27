// BitTracker.h
// Provides a way of storing the binary state of up to 128 values,
// marking if they need to be updated.

#ifndef _BITTRACKER_h
#define _BITTRACKER_h

#include <Arduino.h>

#define BYTE_COUNT_16_BIT	2
#define BYTE_COUNT_32_BIT	4 
#define BYTE_COUNT_128_BIT	16

#define BITS_IN_BYTE		8

class AbstractBitTracker
{
public:
	virtual uint8_t GetBitCount() const { return 0; }
	virtual bool IsBitPending(const uint8_t index) { return false; }
	virtual bool HasPending() { return false; }
	virtual void SetBitPending(const uint8_t index) {}
	virtual void ClearBitPending(const uint8_t index) {}
	virtual void SetAllPending() {}
	virtual void ClearAllPending() {}

public:
	int8_t GetNextPendingIndex(const uint8_t startingIndex = 0)
	{
		if (HasPending())
		{
			for (uint8_t i = startingIndex; i < GetBitCount(); i++)
			{
				if (IsBitPending(i))
				{
					return i;
				}
			}
		}

		return -1;
	}
};

class BitTracker8 : public AbstractBitTracker
{
private:
	uint8_t Block = 0;
public:
	//Input index should never be larger than 7
	bool IsBitPending(const uint8_t index)
	{
		return Block & 1 << index;
	}

	uint8_t GetBitCount() const
	{
		return 8;
	}

	void SetBitPending(const uint8_t index)
	{
		Block |= (1 << index);
	}

	void ClearBitPending(const uint8_t index)
	{
		Block &= ~(1 << index);
	}

	void SetAllPending()
	{
		Block = 0xFF;
	}

	void ClearAllPending()
	{
		Block = 0;
	}

	bool HasPending()
	{
		return Block > 0;
	}
};

class BitTracker16 : public AbstractBitTracker
{
private:
	uint8_t Blocks[BYTE_COUNT_16_BIT];
	uint8_t BlockIndex;

public:
	//Input index should never be larger than BYTE_COUNT_16_BIT*8
	bool IsBitPending(const uint8_t index)
	{
		if (index > (BYTE_COUNT_16_BIT*BITS_IN_BYTE))
		{
			Serial.println(F("AYYY LMAOOOOOOOOOOOOOOOOOOOOO"));
		}
		BlockIndex = index / BITS_IN_BYTE;
		return Blocks[BlockIndex] & 1 << (index % BITS_IN_BYTE);
	}

	uint8_t GetBitCount() const
	{
		return BYTE_COUNT_16_BIT * BITS_IN_BYTE;
	}

	void SetBitPending(const uint8_t index)
	{
		BlockIndex = index / BITS_IN_BYTE;
		Blocks[BlockIndex] |= 1 << (index % BITS_IN_BYTE);
	}

	void ClearBitPending(const uint8_t index)
	{
		BlockIndex = index / BITS_IN_BYTE;
		Blocks[BlockIndex] &= ~(1 << (index % BITS_IN_BYTE));
	}

	void SetAllPending()
	{
		for (uint8_t i = 0; i < BYTE_COUNT_16_BIT; i++)
		{
			Blocks[i] = 0xFF;
		}
	}

	void ClearAllPending()
	{
		for (uint8_t i = 0; i < BYTE_COUNT_16_BIT; i++)
		{
			Blocks[i] = 0;
		}
	}

	bool HasPending()
	{
		for (uint8_t i = 0; i < BYTE_COUNT_16_BIT; i++)
		{
			if (Blocks[i] > 0)
			{
				return true;
			}
		}
		return false;
	}
};

class BitTracker32 : public AbstractBitTracker
{
private:
	uint8_t Blocks[BYTE_COUNT_32_BIT];
	uint8_t BlockIndex;

public:
	//Input index should never be larger than BYTE_COUNT_32_BIT*8
	bool IsBitPending(const uint8_t index)
	{
		if (index > (BYTE_COUNT_32_BIT*BITS_IN_BYTE))
		{
			Serial.println(F("AYYY LMAOOOOOOOOOOOOOOOOOOOOO"));
		}
		BlockIndex = index / BITS_IN_BYTE;
		return Blocks[BlockIndex] & 1 << (index % BITS_IN_BYTE);
	}

	uint8_t GetBitCount() const
	{
		return BYTE_COUNT_32_BIT * BITS_IN_BYTE;
	}

	void SetBitPending(const uint8_t index)
	{
		BlockIndex = index / BITS_IN_BYTE;
		Blocks[BlockIndex] |= 1 << (index % BITS_IN_BYTE);
	}

	void ClearBitPending(const uint8_t index)
	{
		BlockIndex = index / BITS_IN_BYTE;
		Blocks[BlockIndex] &= ~(1 << (index % BITS_IN_BYTE));
	}

	void SetAllPending()
	{
		for (uint8_t i = 0; i < BYTE_COUNT_32_BIT; i++)
		{
			Blocks[i] = 0xFF;
		}
	}

	void ClearAllPending()
	{
		for (uint8_t i = 0; i < BYTE_COUNT_32_BIT; i++)
		{
			Blocks[i] = 0;
		}
	}

	bool HasPending()
	{
		for (uint8_t i = 0; i < BYTE_COUNT_32_BIT; i++)
		{
			if (Blocks[i] > 0)
			{
				return true;
			}
		}
		return false;
	}
};

class BitTracker128 : public AbstractBitTracker
{
private:
	uint8_t Blocks[BYTE_COUNT_128_BIT];
	uint8_t BlockIndex;

public:
	//Input index should never be larger than BYTE_COUNT_128_BIT*8
	bool IsBitPending(const uint8_t index)
	{
		BlockIndex = index / BITS_IN_BYTE;
		return Blocks[BlockIndex] & 1 << (index % BITS_IN_BYTE);
	}

	uint8_t GetBitCount() const
	{
		return BYTE_COUNT_128_BIT * BITS_IN_BYTE;
	}

	void SetBitPending(const uint8_t index)
	{
		BlockIndex = index / BITS_IN_BYTE;
		Blocks[BlockIndex] |= 1 << (index % BITS_IN_BYTE);
	}

	void ClearBitPending(const uint8_t index)
	{
		BlockIndex = index / BITS_IN_BYTE;
		Blocks[BlockIndex] &= ~(1 << (index % BITS_IN_BYTE));
	}

	void SetAllPending()
	{
		for (uint8_t i = 0; i < BYTE_COUNT_128_BIT; i++)
		{
			Blocks[i] = 0xFF;
		}
	}

	void ClearAllPending()
	{
		for (uint8_t i = 0; i < BYTE_COUNT_128_BIT; i++)
		{
			Blocks[i] = 0;
		}
	}

	bool HasPending()
	{
		for (uint8_t i = 0; i < BYTE_COUNT_128_BIT; i++)
		{
			if (Blocks[i] > 0)
			{
				return true;
			}
		}
		return false;
	}
};
#endif

