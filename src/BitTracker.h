// BitTracker.h
// Provides a way of storing and retrieving the binary state of up to UINT16_MAX values,

#ifndef _BITTRACKER_h
#define _BITTRACKER_h

#include <stdint.h>

#define BITS_IN_BYTE		8


#define BYTES_NEEDED_PER_BIT_COUNT(bitCount) ((bitCount / BITS_IN_BYTE) + (bitCount % BITS_IN_BYTE > 0))


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
	virtual uint8_t GetRawBlock(const uint16_t blockIndex = 0);
	virtual void OverrideBlock(const uint8_t blockValue, const uint16_t blockIndex = 0);

public:
	bool MergeBits(IBitTracker* tracker)
	{
		if (GetBitCount() == tracker->GetBitCount())
		{
			for (uint16_t i = 0; i < tracker->GetSize(); i++)
			{
				OverrideBlock(GetRawBlock(i) | tracker->GetRawBlock(i), i);
			}

			return true;
		}
		return false;
	}

	bool ReplaceBits(IBitTracker* tracker)
	{
		if (GetBitCount() == tracker->GetBitCount())
		{
			for (uint16_t i = 0; i < tracker->GetSize(); i++)
			{
				OverrideBlock(tracker->GetRawBlock(i), i);
			}

			return true;
		}
		return false;
	}

	bool MergeClear(IBitTracker& tracker)
	{
		if (GetBitCount() == tracker.GetBitCount())
		{
			for (uint16_t i = 0; i < tracker.GetSize(); i++)
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

	void ReplaceBit(const uint16_t index, const bool value)
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
class BaseTemplateBitTracker : public IBitTracker
{
protected:
	uint8_t* Blocks = nullptr;

protected:
	void SetBlocksSource(uint8_t* blocks)
	{
		Blocks = blocks;
	}

private:
	inline void SetBitInternal(const uint16_t index)
	{
		Blocks[index / BITS_IN_BYTE] |= 1 << (index % BITS_IN_BYTE);
	}

public:
	BaseTemplateBitTracker() : IBitTracker()
	{
	}

	uint16_t GetSize() const
	{
		return BYTES_NEEDED_PER_BIT_COUNT(BitCount);
	}

	uint16_t GetBitCount() const
	{
		return BitCount;
	}

	void OverrideBlock(const uint8_t blockValue, const uint16_t blockIndex = 0)
	{
		if (blockIndex < GetSize())
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

	void ReplaceBit(const uint16_t index, const bool enable)
	{
		if (index < BitCount)
		{
			if (enable)
			{
				SetBitInternal(index);
			}
			else
			{
				ClearBit(index);
			}
		}
	}

	uint8_t GetRawBlock(const uint16_t blockIndex = 0)
	{
		if (blockIndex < GetSize())
		{
			return Blocks[blockIndex];
		}

		return 0;
	}

	void ClearAll()
	{
		for (uint16_t i = 0; i < GetSize(); i++)
		{
			Blocks[i] = 0;
		}
	}

	bool HasSet()
	{
		for (uint16_t i = 0; i < GetSize(); i++)
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

//BitCount <= 65535
template <const uint16_t BitCount>
class TemplateBitTracker : public BaseTemplateBitTracker<BitCount>
{
private:
	uint8_t BlocksData[BYTES_NEEDED_PER_BIT_COUNT(BitCount)];

public:
	TemplateBitTracker() : BaseTemplateBitTracker<BitCount>()
	{
		BaseTemplateBitTracker<BitCount>::SetBlocksSource(BlocksData);
	}	
};

//BitCount <= 65535
template <const uint16_t BitCount>
class TemplateExternalBitTracker : public BaseTemplateBitTracker<BitCount>
{
public:
	TemplateExternalBitTracker(uint8_t* blocksSource = nullptr) : BaseTemplateBitTracker<BitCount>()
	{
		BaseTemplateBitTracker<BitCount>::SetBlocksSource(blocksSource);
	}
};
#endif
