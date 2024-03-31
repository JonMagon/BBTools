// WaveWriter.cpp : Functions for writing wave files
//

#include "stdafx.h"
#include "WaveWriter.h"

// Wave 'fmt ' chunk
struct SWaveFmtChunk
{
    SWaveFmtChunk()
    {
        memset(this, 0, sizeof(SWaveFmtChunk));
    }
    uint16_t FormatTag;
    uint16_t Channels;
    uint32_t SampleRate;
    uint32_t BytesPerSec;
    uint16_t BlockAlign;
    uint16_t BitsPerSample;
};

void PrepareWaveHeader(std::ostream& Output)
{
    WriteWaveHeader(Output, 0, 0, 0, 0);
    return;
}

void WriteWaveHeader(std::ostream& Output, unsigned long SampleRate, \
                     unsigned char BitsPerSample, unsigned char Channels, \
                     unsigned long NumberSamples)
{
    unsigned long Temp;

    // Write some RIFF information
    Output.write("RIFF", 4);
    Temp=NumberSamples*(BitsPerSample/8)+36;
    Output.write((char*)&Temp, 4);
    Output.write("WAVE", 4);
    Output.write("fmt ", 4);
    Temp=16;
    Output.write((char*)&Temp, 4);

    // Write the format chunk
    SWaveFmtChunk Fmt;
    Fmt.FormatTag=1;
    Fmt.Channels=Channels;
    Fmt.SampleRate=SampleRate;
    Fmt.BitsPerSample=BitsPerSample;
    Fmt.BytesPerSec=Fmt.BitsPerSample/8*Fmt.SampleRate*Fmt.Channels;
    Fmt.BlockAlign=Fmt.BitsPerSample/8*Fmt.Channels;
    Output.write((char*)&Fmt, 16);

    // Write the data information
    Output.write("data", 4);
    Temp=NumberSamples*(BitsPerSample/8);
    Output.write((char*)&Temp, 4);
    return;
}
