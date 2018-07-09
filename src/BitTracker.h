// BitTracker.h
// Provides a way of storing the binary state of up to 128 values,
// marking if they need to be updated.

#ifndef _BITTRACKER_h
#define _BITTRACKER_h

#include <Arduino.h>

#include <stdint.h>

#define BITS_IN_BYTE		8

class IBitTracker
{
public:
	virtual uint16_t GetBitCount() const;
	virtual bool IsBitPending(const uint8_t index);
	virtual bool HasPending();
	virtual void SetBitPending(const uint8_t index);
	virtual void ClearBitPending(const uint8_t index);
	virtual void SetAllPending();
	virtual void SetAllPendingForced();
	virtual void ClearAllPending();
	virtual uint16_t GetSize() const;
	virtual uint8_t GetRawBlock(const uint8_t index = 0);
	virtual void OverrideBlock(const uint8_t blockValue, const uint8_t blockIndex = 0);

public:
	uint8_t GetNextPendingIndex(const uint8_t startingIndex = 0)
	{
		for (uint8_t i = startingIndex; i < GetSize(); i++)
		{
			if (IsBitPending(i))
			{
				return i;
			}
		}
	}
};

//BitCount <= 8
template <const uint16_t BitCount>
class BitTracker8 : public IBitTracker
{
private:
	uint8_t Block = 0;

private:
	inline void SetBitPendingInternal(const uint8_t index)
	{
		Block |= (1 << index);
	}

public:
	BitTracker8() : IBitTracker()
	{
		Block = 0;
	}

	uint16_t GetSize() const
	{
		return 1;
	}

	uint16_t GetBitCount() const
	{
		return BitCount;
	}

	uint8_t GetRawBlock(const uint8_t blockIndex = 0)
	{
		if (blockIndex == 0)
		{
			return Block;
		}
		return 0;
	}

	void OverrideBlock(const uint8_t blockValue, const uint8_t blockIndex = 0)
	{
		if (blockIndex == 0)
		{
			Block = blockValue;
		}
	}

	void SetAllPending()
	{
		for (uint8_t i = 0; i < GetBitCount(); i++)
		{
			SetBitPendingInternal(i);
		}
	}

	bool IsBitPending(const uint8_t index)
	{
		if (index < BitCount)
		{
			return Block & 1 << index;
		}
		
		return false;		
	}

	void SetBitPending(const uint8_t index)
	{
		SetBitPendingInternal(index);
	}

	void ClearBitPending(const uint8_t index)
	{
		Block &= ~(1 << index);
	}

	void SetAllPendingForced()
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

//BitCount <= 255
template <const uint16_t BitCount>
class TemplateBitTracker : public IBitTracker
{
private:
	static const uint8_t Size = (uint8_t)ceil((double)BitCount / (double)BITS_IN_BYTE);

	uint8_t Blocks[Size];

private:
	inline void SetBitPendingInternal(const uint8_t index)
	{
		Blocks[index / BITS_IN_BYTE] |= 1 << (index % BITS_IN_BYTE);
	}

public:
	TemplateBitTracker()
	{
		for (uint16_t i = 0; i < GetBitCount(); i++)
		{
			ClearBitPending(i);
		}
	}

	uint16_t GetSize() const
	{
		return Size;
	}

	uint16_t GetBitCount() const
	{
		return BitCount;
	}

	void OverrideBlock(const uint8_t blockValue, const uint8_t blockIndex)
	{
		if (blockIndex < Size)
		{
			Blocks[blockIndex] = blockValue;
		}
	}

	void SetAllPending()
	{
		for (uint16_t i = 0; i < BitCount; i++)
		{
			SetBitPendingInternal(i);
		}
	}

	void SetBitPending(const uint8_t index)
	{
		if (index < BitCount)
		{
			SetBitPendingInternal(index);
		}
	}

	uint8_t GetRawBlock(const uint8_t blockIndex)
	{
		if (blockIndex < Size)
		{
			return Blocks[blockIndex];
		}

		return 0;
	}

	void ClearAllPending()
	{
		for (uint8_t i = 0; i < Size; i++)
		{
			Blocks[i] = 0;
		}
	}

	bool HasPending()
	{
		for (uint8_t i = 0; i < Size; i++)
		{
			if (GetRawBlock(i) > 0)
			{
				return true;
			}
		}
		return false;
	}

	bool IsBitPending(const uint8_t index)
	{
		return Blocks[index / BITS_IN_BYTE] & 1 << (index % BITS_IN_BYTE);
	}

	void ClearBitPending(const uint8_t index)
	{
		Blocks[index / BITS_IN_BYTE] &= ~(1 << (index % BITS_IN_BYTE));
	}

	void SetAllPendingForced()
	{
		for (uint8_t i = 0; i < Size; i++)
		{
			Blocks[i] = UINT8_MAX;
		}
	}
};
#endif