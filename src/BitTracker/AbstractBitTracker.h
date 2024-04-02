// AbstractBitTracker.h
// Provides a way of storing and retrieving the binary state of up to UINT16_MAX values,

#ifndef _ABSTRACT_BIT_TRACKER_h
#define _ABSTRACT_BIT_TRACKER_h

#include <stdint.h>

namespace BitTracker
{
	static constexpr uint8_t BITS_IN_BYTE = 8;

	static constexpr size_t BlockCount(const uint32_t bitCount)
	{
		return (bitCount / BITS_IN_BYTE) + ((bitCount % BITS_IN_BYTE) > 0) * 1;
	}
}

/// <summary>
/// Provides a way of storing and retrieving the binary state of up to UINT32_MAX values.
/// </summary>
/// <param name="UInt">The integer primitive used to address blocks of bits:
/// - uint8_t for up to UINT8_MAX bits
/// - uint16_t for up to UINT16_MAX bits
/// - uint32_t for up to UINT32_MAX bits
/// </param>
/// <param name="BitCount">How many individual bits are used. [1;UINT32_MAX]</param>
template<typename UInt, const UInt BitCount>
class AbstractBitTracker
{
private:
	static constexpr uint8_t BITS_IN_BYTE = BitTracker::BITS_IN_BYTE;
	static constexpr size_t BLOCK_COUNT = BitTracker::BlockCount(BitCount);

	static constexpr UInt BIT_WHOLE = BitCount / BITS_IN_BYTE;
	static constexpr uint8_t BIT_REMAINDER = BitCount % BITS_IN_BYTE;
	static constexpr UInt REMAINDER_START = (UInt)BIT_WHOLE * BITS_IN_BYTE;
	static constexpr UInt REMAINDER_COUNT = BitCount - REMAINDER_START;
	static constexpr UInt REMAINDER_END = REMAINDER_START + REMAINDER_COUNT;
	static constexpr UInt REMAINDER_BLOCK = REMAINDER_START / BITS_IN_BYTE;

private:
	uint8_t* Blocks;

public:
	/// <summary>
	/// </summary>
	/// <param name="blocks">Pre-allocated raw blocks for bit storage.</param>
	AbstractBitTracker(uint8_t* blocks)
		: Blocks(blocks)
	{}

	static constexpr size_t GetSize()
	{
		return BLOCK_COUNT;
	}

	static constexpr size_t GetBitCount()
	{
		return BitCount;
	}

public:
	/// <summary>
	/// Sets a single bit.
	/// </summary>
	/// <param name="index">[0; BitCount-1]</param>
	void SetBit(const UInt index)
	{
		if (index < BitCount)
		{
			Blocks[index / BITS_IN_BYTE] |= (1 << (index % BITS_IN_BYTE));
		}
	}

	/// <summary>
	/// Status of a single bit.
	/// </summary>
	/// <param name="index">[0; BitCount-1]</param>
	/// <returns>True if bit is set.</returns>
	const bool IsBitSet(const UInt index)
	{
		return (Blocks[index / BITS_IN_BYTE] & (((uint8_t)1) << (index % BITS_IN_BYTE)));
	}

	/// <summary>
	/// Clears a single bit.
	/// </summary>
	/// <param name="index">[0; BitCount-1]</param>
	void ClearBit(const UInt index)
	{
		Blocks[index / BITS_IN_BYTE] &= ~((uint8_t)1 << (index % BITS_IN_BYTE));
	}

	/// <summary>
	/// Replaces a single bit.
	/// </summary>
	/// <param name="index">[0; BitCount-1]</param>
	void ReplaceBit(const UInt index, const bool value)
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

	/// <summary>
	/// Set all blocks.
	/// </summary>
	void SetAll()
	{
		memset(Blocks, UINT8_MAX, BIT_WHOLE);

		for (UInt i = REMAINDER_START; i < REMAINDER_END; i++)
		{
			Blocks[REMAINDER_BLOCK] |= (1 << (i % BITS_IN_BYTE));
		}
	}

	/// <summary>
	/// Clear all blocks.
	/// </summary>
	void ClearAll()
	{
		memset(Blocks, 0, BIT_WHOLE);

		for (UInt i = REMAINDER_START; i < REMAINDER_END; i++)
		{
			Blocks[REMAINDER_BLOCK] &= ~((UInt)1 << (i % BITS_IN_BYTE));
		}
	}

public:
	/// <summary>
	/// Status of all bits.
	/// </summary>
	/// <returns>True if any bit is set.</returns>
	const bool HasSet()
	{
		for (size_t i = 0; i < GetSize(); i++)
		{
			if (Blocks[i] > 0)
			{
				return true;
			}
		}
		return false;
	}

	/// <summary>
	/// Locates the next set bit.
	/// Works best when paired with HasSet() to ignore if no bit is set.
	/// </summary>
	/// <param name="startingIndex"></param>
	/// <returns>Index of the next set bit. 0 if none found.</returns>
	const UInt GetNextSetIndex(const UInt startingIndex = 0)
	{
		if (startingIndex < BitCount)
		{
			for (UInt i = startingIndex; i < BitCount; i++)
			{
				if (IsBitSet(i))
				{
					return i;
				}
			}
		}

		return 0;
	}

public:
	const bool OrBits(AbstractBitTracker<UInt, BitCount>* tracker)
	{
		if (GetBitCount() == tracker->GetBitCount())
		{
			for (size_t i = 0; i < tracker->GetSize(); i++)
			{
				Blocks[i] = Blocks[i] | tracker->GetRawBlock(i);
			}

			return true;
		}

		return false;
	}

	const bool CopyBits(AbstractBitTracker<UInt, BitCount>* tracker)
	{
		if (GetBitCount() == tracker->GetBitCount())
		{
			for (size_t i = 0; i < tracker->GetSize(); i++)
			{
				Blocks[i] = tracker->GetRawBlock(i);
			}

			return true;
		}

		return false;
	}

	const bool AndBits(AbstractBitTracker<UInt, BitCount>& tracker)
	{
		if (GetBitCount() == tracker.GetBitCount())
		{
			for (size_t i = 0; i < tracker.GetSize(); i++)
			{
				Blocks[i] = Blocks[i] & ~tracker->GetRawBlock(i);
			}

			return true;
		}

		return false;
	}

	void OverrideBlock(const uint8_t blockValue, const UInt blockIndex)
	{
		Blocks[blockIndex] = blockValue;
	}

	const uint8_t GetRawBlock(const UInt blockIndex)
	{
		return Blocks[blockIndex];
	}
};


template <typename UInt, const UInt BitCount>
class TemplateBitTracker : public AbstractBitTracker<UInt, BitCount>
{
private:
	using BaseClass = AbstractBitTracker<UInt, BitCount>;

	uint8_t BlocksData[BitTracker::BlockCount(BitCount)]{};

public:
	TemplateBitTracker() : BaseClass(BlocksData)
	{}
};

template <typename UInt, const UInt BitCount>
class TemplateExternalBitTracker : public AbstractBitTracker<UInt, BitCount>
{
private:
	using BaseClass = AbstractBitTracker<UInt, BitCount>;

public:
	TemplateExternalBitTracker(uint8_t* blocksSource) : BaseClass(blocksSource) {}
};
#endif