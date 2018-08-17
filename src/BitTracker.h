// BitTracker.h
// Provides a way of storing and retrieving the binary state of up to UINT16_MAX values,

#ifndef _BITTRACKER_h
#define _BITTRACKER_h

#include <Arduino.h>

#include <stdint.h>

#define BITS_IN_BYTE		8

class IBitTracker
{
public:
	virtual uint16_t GetBitCount() const;
	virtual bool IsBitSet(const uint16_t index);
	virtual bool HasSet();
	virtual void SetBit(const uint16_t index);
	virtual void ClearBit(const uint16_t index);
	virtual void SetAll();
	virtual void ClearAll();
	virtual uint16_t GetSize() const;
	virtual uint8_t GetRawBlock(const uint8_t blockIndex = 0);
	virtual void OverrideBlock(const uint8_t blockValue, const uint8_t blockIndex = 0);

public:
	bool MergeSet(IBitTracker &tracker)
	{
		if (GetBitCount() == tracker.GetBitCount())
		{
			for (uint8_t i = 0; i < tracker.GetSize(); i++)
			{
				OverrideBlock(GetRawBlock(i) | tracker.GetRawBlock(i), i);
			}

			return true;
		}
		return false;
	}

	bool MergeClear(IBitTracker &tracker)
	{
		if (GetBitCount() == tracker.GetBitCount())
		{
			for (uint8_t i = 0; i < tracker.GetSize(); i++)
			{				
				OverrideBlock(GetRawBlock(i) & ~tracker.GetRawBlock(i), i);
			}

			return true;
		}
		return false;
	}

	uint16_t GetNextSetIndex(const uint16_t startingIndex = 0)
	{
		for (uint16_t i = startingIndex; i < GetBitCount(); i++)
		{
			if (IsBitSet(i))
			{
				return i;
			}
		}

		return 0;
	}

	void ReplaceBit(const uint8_t index, const bool value)
	{
		if (value)
		{
			SetBit(index);
		}
		else
		{
			ClearBit(index);
		}
	}
};

//BitCount <= 65535
template <const uint16_t BitCount>
class TemplateBitTracker : public IBitTracker
{
private:
	static const uint8_t Size = (uint8_t)ceil((double)BitCount / (double)BITS_IN_BYTE);

	uint8_t Blocks[Size];

private:
	inline void SetBitInternal(const uint16_t index)
	{
		Blocks[index / BITS_IN_BYTE] |= 1 << (index % BITS_IN_BYTE);
	}

public:
	TemplateBitTracker()
	{
		for (uint16_t i = 0; i < GetBitCount(); i++)
		{
			ClearBit(i);
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

	void OverrideBlock(const uint8_t blockValue, const uint8_t blockIndex = 0)
	{
		if (blockIndex < Size)
		{
			Blocks[blockIndex] = blockValue;
		}
	}

	void SetAll()
	{
		for (uint16_t i = 0; i < BitCount; i++)
		{
			SetBitInternal(i);
		}
	}

	void SetBit(const uint16_t index)
	{
		if (index < BitCount)
		{
			SetBitInternal(index);
		}
	}

	uint8_t GetRawBlock(const uint8_t blockIndex = 0)
	{
		if (blockIndex < Size)
		{
			return Blocks[blockIndex];
		}

		return 0;
	}

	void ClearAll()
	{
		for (uint8_t i = 0; i < Size; i++)
		{
			Blocks[i] = 0;
		}
	}

	bool HasSet()
	{
		for (uint8_t i = 0; i < Size; i++)
		{
			if (Blocks[i] > 0)
			{
				return true;
			}
		}
		return false;
	}

	bool IsBitSet(const uint16_t index)
	{
		return Blocks[index / BITS_IN_BYTE] & 1 << (index % BITS_IN_BYTE);
	}

	void ClearBit(const uint16_t index)
	{
		Blocks[index / BITS_IN_BYTE] &= ~(1 << (index % BITS_IN_BYTE));
	}
};
#endif
