// BitTracker.h
// Provides a way of storing the binary state of up to 128 values,
// marking if they need to be updated.

#ifndef _BITTRACKER_h
#define _BITTRACKER_h

#include <Arduino.h>

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
	uint8_t Blocks = 0;
public:
	//Input index should never be larger than 7
	bool IsBitPending(const uint8_t index)
	{
		return Blocks & 1 << index;
	}

	uint8_t GetBitCount() const
	{
		return 8;
	}

	void SetBitPending(const uint8_t index)
	{
		Blocks |= 1 << index;
	}

	void ClearBitPending(const uint8_t index)
	{
		Blocks &= ~(1 << index);
	}

	void SetAllPending()
	{
		Blocks = 0xFF;
	}

	void ClearAllPending()
	{
		Blocks = 0;
	}

	bool HasPending()
	{
		return Blocks > 0;
	}
};

class BitTracker16 : public AbstractBitTracker
{
private:
	uint16_t Blocks = 0;
public:
	//Input index should never be larger than 15
	bool IsBitPending(const uint8_t index)
	{
		return Blocks & 1 << index;
	}

	uint8_t GetBitCount() const
	{
		return 16;
	}

	void SetBitPending(const uint8_t index)
	{
		Blocks |= 1 << index;
	}

	void ClearBitPending(const uint8_t index)
	{
		Blocks &= ~(1 << index);
	}

	void SetAllPending()
	{
		Blocks = 0xFFFF;
	}

	void ClearAllPending()
	{
		Blocks = 0;
	}

	bool HasPending()
	{
		return Blocks > 0;
	}
};

class BitTracker32 : public AbstractBitTracker
{
private:
	uint32_t Blocks = 0;
public:
	//Input index should never be larger than 31
	bool IsBitPending(const uint8_t index)
	{
		return Blocks & 1 << index;
	}

	uint8_t GetBitCount() const
	{
		return 32;
	}

	void SetBitPending(const uint8_t index)
	{
		Blocks |= 1 << index;
	}

	void ClearBitPending(const uint8_t index)
	{
		Blocks &= ~(1 << index);
	}

	void SetAllPending()
	{
		Blocks = 0xFFFFFF;
	}

	void ClearAllPending()
	{
		Blocks = 0;
	}

	bool HasPending()
	{
		return Blocks > 0;
	}
};

//Slower than all of the others, most scalable from 128 bits to more!
class BitTrackerArray : public AbstractBitTracker
{
#define BLOCK_ARRAY_SIZE_BYTES 16
#define BITS_IN_BYTE 8
private:
	uint8_t Blocks[BLOCK_ARRAY_SIZE_BYTES];

	uint8_t BlockIndex;
public:
	//Input index should never be larger than BLOCK_ARRAY_SIZE_BYTES*8
	bool IsBitPending(const uint8_t index)
	{
		BlockIndex = index / BITS_IN_BYTE;
		return Blocks[BlockIndex] & 1 << (index % BITS_IN_BYTE);
	}

	uint8_t GetBitCount() const
	{
		return BLOCK_ARRAY_SIZE_BYTES;
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
		for (uint8_t i = 0; i < BLOCK_ARRAY_SIZE_BYTES; i++)
		{
			Blocks[i] = 0xFF;
		}
	}

	void ClearAllPending()
	{
		for (uint8_t i = 0; i < BLOCK_ARRAY_SIZE_BYTES; i++)
		{
			Blocks[i] = 0;
		}
	}

	bool HasPending()
	{
		for (uint8_t i = 0; i < BLOCK_ARRAY_SIZE_BYTES; i++)
		{
			if (Blocks[i] >= 0)
			{
				return true;
			}
		}
		return false;
	}
};
#endif

