#pragma once

struct SM10DecoderPrivate
{
    uint8_t* CompressedData;
    uint32_t CurrentBits;
    uint32_t BitCount;
    uint32_t FirstBit;
    uint32_t Second4Bits;
    float FloatTable[64];
    float Table1[12];
    float Table2[12];
    float BigTable[324];
    float SampleBuffer[432];
};
