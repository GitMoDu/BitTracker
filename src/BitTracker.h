// BitTracker.h
// Provides a way of storing the binary state of up to 128 values,
// marking if they need to be updated.

#ifndef _BITTRACKER_h
#define _BITTRACKER_h

#include <Arduino.h>

#define BYTE_COUNT_8_BIT	1
#define BYTE_COUNT_16_BIT	2
#define BYTE_COUNT_32_BIT	4
#define BYTE_COUNT_64_BIT	8
#define BYTE_COUNT_128_BIT	16

#define BITS_IN_BYTE		8

class IBitTracker
{
protected:
	inline virtual void SetBitPendingInternal(const uint8_t index) {}

public:
	virtual uint8_t GetBitCount() const { return 0; }
	virtual bool IsBitPending(const uint8_t index) { return false; }
	virtual bool HasPending() { return false; }
	virtual void SetBitPending(const uint8_t index) {}
	virtual void ClearBitPending(const uint8_t index) {}
	virtual void SetAllPending() {}
	virtual void SetAllPendingForced() {}
	virtual void ClearAllPending() {}
	virtual bool Initialize() { return false; }
	virtual uint8_t GetNextPendingIndex(const uint8_t startingIndex = 0) { return -1; }
	virtual uint8_t GetSize() { return 0; }
	virtual uint8_t GetRawBlock(const uint8_t index){return 0;}
};

class AbstractBitTracker : public IBitTracker
{
private:
	uint8_t Size = 0;

protected:
	virtual uint8_t* GetRaw() { return nullptr; }
	virtual uint8_t GetSizeInternal() const { return 0; }

protected:
	bool Initialize()
	{
		if (Size <= GetBitCount() && GetRaw() != nullptr)
		{
			for (uint8_t i = Size; i < GetBitCount(); i++)
			{
				ClearBitPending(i);
			}

			return true;
		}
		else
		{
			return false;
		}
	}

public:
	AbstractBitTracker(const uint8_t size)
	{
		Size = size;
	}

	uint8_t GetSize()
	{
		return Size;
	}

	uint8_t GetBitCount() const
	{
		return GetSizeInternal()*BITS_IN_BYTE;
	}

	uint8_t GetNextPendingIndex(const uint8_t startingIndex = 0)
	{
		for (uint8_t i = startingIndex; i < GetSize(); i++)
		{
			if (IsBitPending(i))
			{
				return i;
			}
		}

		return 0;
	}

	void SetAllPending()
	{
		for (uint8_t i = 0; i < Size; i++)
		{
			SetBitPendingInternal(i);
		}
	}

	void SetBitPending(const uint8_t index)
	{
		if (index < Size)
		{
			SetBitPendingInternal(index);
		}
	}

	uint8_t GetRawBlock(const uint8_t blockIndex)
	{
		if (blockIndex < GetSizeInternal())
		{
			return GetRaw()[blockIndex];
		}
		return 0;
	}

	bool HasPending()
	{
		for (uint8_t i = 0; i < BYTE_COUNT_32_BIT; i++)
		{
			if (GetRawBlock(i) > 0)
			{
				return true;
			}
		}
		return false;
	}
};

class BitTracker8 : public AbstractBitTracker
{
private:
	uint8_t Block = 0;

protected:
	uint8_t * GetRaw() { return &Block; }

public:
	BitTracker8(const uint8_t size) : AbstractBitTracker(size)
	{
		Initialize();
	}

	//Input index should never be larger than 7
	bool IsBitPending(const uint8_t index)
	{
		return Block & 1 << index;
	}

	uint8_t GetSizeInternal() const
	{
		return BYTE_COUNT_8_BIT;
	}

	inline void SetBitPendingInternal(const uint8_t index)
	{
		Block |= (1 << index);
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

class BitTracker16 : public AbstractBitTracker
{
private:
	uint8_t Blocks[BYTE_COUNT_16_BIT];
	uint8_t BlockIndex;

protected:
	uint8_t * GetRaw() { return Blocks; }

public:
	BitTracker16(const uint8_t size) : AbstractBitTracker(size)
	{
		Initialize();
	}

	//Input index should never be larger than BYTE_COUNT_16_BIT*8
	bool IsBitPending(const uint8_t index)
	{
		BlockIndex = index / BITS_IN_BYTE;
		return Blocks[BlockIndex] & 1 << (index % BITS_IN_BYTE);
	}

	uint8_t GetSizeInternal() const
	{
		return BYTE_COUNT_16_BIT;
	}

	inline void SetBitPendingInternal(const uint8_t index)
	{
		BlockIndex = index / BITS_IN_BYTE;
		Blocks[BlockIndex] |= 1 << (index % BITS_IN_BYTE);
	}

	void ClearBitPending(const uint8_t index)
	{
		BlockIndex = index / BITS_IN_BYTE;
		Blocks[BlockIndex] &= ~(1 << (index % BITS_IN_BYTE));
	}

	void SetAllPendingForced()
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
};

class BitTracker32 : public AbstractBitTracker
{
private:
	uint8_t Blocks[BYTE_COUNT_32_BIT];
	uint8_t BlockIndex;

protected:
	uint8_t * GetRaw() { return Blocks; }

public:
	BitTracker32(const uint8_t size) : AbstractBitTracker(size)
	{
		Initialize();
	}
	//Input index should never be larger than BYTE_COUNT_32_BIT*8
	bool IsBitPending(const uint8_t index)
	{
		BlockIndex = index / BITS_IN_BYTE;
		return Blocks[BlockIndex] & 1 << (index % BITS_IN_BYTE);
	}

	uint8_t GetSizeInternal() const
	{
		return BYTE_COUNT_32_BIT;
	}

	inline void SetBitPendingInternal(const uint8_t index)
	{
		BlockIndex = index / BITS_IN_BYTE;
		Blocks[BlockIndex] |= 1 << (index % BITS_IN_BYTE);
	}

	void ClearBitPending(const uint8_t index)
	{
		BlockIndex = index / BITS_IN_BYTE;
		Blocks[BlockIndex] &= ~(1 << (index % BITS_IN_BYTE));
	}

	void SetAllPendingForced()
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
};

class BitTracker64 : public AbstractBitTracker
{
private:
	uint8_t Blocks[BYTE_COUNT_64_BIT];
	uint8_t BlockIndex;

protected:
	uint8_t * GetRaw() { return Blocks; }

public:
	BitTracker64(const uint8_t size) : AbstractBitTracker(size)
	{
		Initialize();
	}
	//Input index should never be larger than BYTE_COUNT_64_BIT*8
	bool IsBitPending(const uint8_t index)
	{
		BlockIndex = index / BITS_IN_BYTE;
		return Blocks[BlockIndex] & 1 << (index % BITS_IN_BYTE);
	}

	inline void SetBitPendingInternal(const uint8_t index)
	{
		BlockIndex = index / BITS_IN_BYTE;
		Blocks[BlockIndex] |= 1 << (index % BITS_IN_BYTE);
	}

	void ClearBitPending(const uint8_t index)
	{
		BlockIndex = index / BITS_IN_BYTE;
		Blocks[BlockIndex] &= ~(1 << (index % BITS_IN_BYTE));
	}

	void SetAllPendingForced()
	{
		for (uint8_t i = 0; i < BYTE_COUNT_64_BIT; i++)
		{
			Blocks[i] = 0xFF;
		}
	}

	void ClearAllPending()
	{
		for (uint8_t i = 0; i < BYTE_COUNT_64_BIT; i++)
		{
			Blocks[i] = 0;
		}
	}

	bool HasPending()
	{
		for (uint8_t i = 0; i < BYTE_COUNT_64_BIT; i++)
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

protected:
	uint8_t * GetRaw() { return Blocks; }

public:
	BitTracker128(const uint8_t size) : AbstractBitTracker(size)
	{
		Initialize();
	}
	//Input index should never be larger than BYTE_COUNT_128_BIT*8
	bool IsBitPending(const uint8_t index)
	{
		BlockIndex = index / BITS_IN_BYTE;
		return Blocks[BlockIndex] & 1 << (index % BITS_IN_BYTE);
	}

	inline void SetBitPendingInternal(const uint8_t index)
	{
		BlockIndex = index / BITS_IN_BYTE;
		Blocks[BlockIndex] |= 1 << (index % BITS_IN_BYTE);
	}

	void ClearBitPending(const uint8_t index)
	{
		BlockIndex = index / BITS_IN_BYTE;
		Blocks[BlockIndex] &= ~(1 << (index % BITS_IN_BYTE));
	}

	void SetAllPendingForced()
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