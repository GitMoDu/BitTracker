// BitTracker.h

#ifndef _BIT_TRACKER_h
#define _BIT_TRACKER_h

#include "BitTracker/AbstractBitTracker.h"

template <const uint8_t BitCount>
class BitTracker8 : public TemplateBitTracker<uint8_t, BitCount>
{
public:
	BitTracker8() : TemplateBitTracker<uint8_t, BitCount>() {}
};

template <const uint16_t BitCount>
class BitTracker16 : public TemplateBitTracker<uint16_t, BitCount>
{
public:
	BitTracker16() : TemplateBitTracker<uint16_t, BitCount>() {}
};

template <const uint32_t BitCount>
class BitTracker32 : public TemplateBitTracker<uint32_t, BitCount>
{
public:
	BitTracker32() : TemplateBitTracker<uint32_t, BitCount>() {}
};

template <const uint8_t BitCount>
class BitTracker8External : public TemplateExternalBitTracker<uint8_t, BitCount>
{
public:
	BitTracker8External(uint8_t* blocksSource) : TemplateExternalBitTracker<uint8_t, BitCount>(blocksSource) {}
};

template <const uint16_t BitCount>
class BitTracker16External : public TemplateExternalBitTracker<uint16_t, BitCount>
{
public:
	BitTracker16External(uint8_t* blocksSource) : TemplateExternalBitTracker<uint16_t, BitCount>(blocksSource) {}
};

template <const uint32_t BitCount>
class BitTracker32External : public TemplateExternalBitTracker<uint32_t, BitCount>
{
public:
	BitTracker32External(uint8_t* blocksSource) : TemplateExternalBitTracker<uint32_t, BitCount>(blocksSource) {}
};
#endif