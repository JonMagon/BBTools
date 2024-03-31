#pragma once

#include <istream>

struct SM10DecoderPrivate;

class mtDecoder
{
public:
    mtDecoder();
    ~mtDecoder();

    void Initialize(std::istream& Input);
    unsigned long Decode(short* OutputBuffer, unsigned long SampleCount);

protected:
    void Clear();
    bool ParsePTHeader(std::istream& Input);
    
    uint8_t* m_InputBuffer;
    SM10DecoderPrivate* m_Input;
    unsigned long m_SampleBufferOffset;
    unsigned long m_SamplesDecodedSoFar;
    unsigned long m_TotalSampleCount;
};
