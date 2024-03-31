// DecodeM10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Decoder.h"
#include "WaveWriter.h"
#include "Structures.h"

#define PRINT_SIZEOF(type) std::cout << "Size of " << #type << ": " << sizeof(type) << std::endl

int main(int Argc, char* Argv[])
{
    if (Argc < 3)
    {
        std::cerr << "Beasts and Bumpkins .m10 Decoder" << std::endl;
        std::cerr << "Usage: " << Argv[0] << " {InputFile} {OutputFile}" << std::endl;
        std::cerr << std::endl;
        return 1;
    }

    std::string InputFilename;
    std::string OutputFilename;
    InputFilename = Argv[1];
    OutputFilename = Argv[2];

    std::ifstream Input;
    Input.open(InputFilename.c_str(), std::ios_base::in | std::ios_base::binary);
    if (!Input.is_open())
    {
        std::cerr << "Could not open input file '" << InputFilename << "'." << std::endl;
        return 1;
    }

    std::ofstream Output;
    Output.open(OutputFilename.c_str(), std::ios_base::out | std::ios_base::binary);
    if (!Output.is_open())
    {
        std::cerr << "Could not open outptu file '" << OutputFilename << "'." << std::endl;
        return 1;
    }

    PrepareWaveHeader(Output);

    mtDecoder Decoder;
    Decoder.Initialize(Input);

    short Samples[4096];
    unsigned long Decoded;
    long SampleCount;
    SampleCount = 0;
    do
    {
        Decoded = Decoder.Decode(Samples, 4096);

        Output.write((char*)Samples, Decoded * 2);
        SampleCount += Decoded;
    } while (Decoded == 4096);

    Output.seekp(0);
    WriteWaveHeader(Output, 22050, 16, 1, SampleCount);
    return 0;
}

