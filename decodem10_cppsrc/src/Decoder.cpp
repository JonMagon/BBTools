#include "stdafx.h"
#include "Decoder.h"
#include "Structures.h"

// Declare the decoding functions
void InitializeDecoder(SM10DecoderPrivate* DecoderStruct, uint8_t* CompressedData);
void DecodeBlock(SM10DecoderPrivate* DecoderStruct);

mtDecoder::mtDecoder() :
        m_InputBuffer(NULL),
        m_Input(NULL),
        m_SampleBufferOffset(0),
        m_SamplesDecodedSoFar(0),
        m_TotalSampleCount(0)
{
    return;
}

mtDecoder::~mtDecoder()
{
    Clear();
    return;
}

void mtDecoder::Initialize(std::istream& Input)
{
    // Calculate the file size
    std::streamsize FileSize;
    Clear();

    Input.seekg(0, std::ios_base::end);
    FileSize = Input.tellg();
    Input.seekg(0);

    if (FileSize < 1)
    {
        std::cerr << "Empty file." << std::endl;
        return;
    }

    // Read the PT header
    if (!ParsePTHeader(Input))
    {
        return;
    }

    // Load the file in
    std::streamsize DataSize;
    DataSize = FileSize - Input.tellg();
    m_InputBuffer = new uint8_t[DataSize];
    Input.read((char*)m_InputBuffer, DataSize);

    std::cout << "Total sample count: " << m_TotalSampleCount << std::endl;

    // Initialize the decoder
    m_Input = new SM10DecoderPrivate;
    try
    {
        InitializeDecoder(m_Input, m_InputBuffer);
    }
    catch (...)
    {
        std::cerr << "The decoder could not be initialized (bug in program)." << std::endl;
    }
    m_SampleBufferOffset = 432;
    m_SamplesDecodedSoFar = 0;
    return;
}

union mtFloatInt
{
    float Float;
    uint32_t Int;
};

unsigned long mtDecoder::Decode(short* OutputBuffer, unsigned long SampleCount)
{
    if (!m_TotalSampleCount)
    {
        return 0;
    }

    unsigned int Same = 0;
    unsigned int Different = 0;

    for (unsigned long i = 0; i < SampleCount; i++)
    {
        mtFloatInt Sample;
        Sample.Int = 0x4B400000;

        if (m_SampleBufferOffset >= 432)
        {
            try
            {
                DecodeBlock(m_Input);
            }
            catch (...)
            {
                std::cerr << "The decoder encountered a problem (bug in program)." << std::endl;
                return i;
            }
            m_SampleBufferOffset = 0;
        }

        Sample.Float += m_Input->SampleBuffer[m_SampleBufferOffset];
        m_SampleBufferOffset++;
        m_SamplesDecodedSoFar++;

        unsigned long Clipped;
        Clipped = Sample.Int & 0x1FFFF;
        if (Clipped > 0x7FFF && Clipped < 0x18000)
        {
            if (Clipped >= 0x10000)
            {
                Clipped = 0x8000;
            }
            else
            {
                Clipped = 0x7FFF;
            }
        }

        OutputBuffer[i] = (short)Clipped;

        if (m_SamplesDecodedSoFar >= m_TotalSampleCount)
        {
            return i + 1;
        }
    }
    return SampleCount;
}

void mtDecoder::Clear()
{
    delete[] m_InputBuffer;
    m_InputBuffer = NULL;
    delete m_Input;
    m_Input = NULL;
    return;
}

static unsigned long ReadBytes(std::istream& Input, uint8_t Count)
{
    uint8_t i;
    uint8_t Byte;
    unsigned long Result;

    Result = 0;
    for (i = 0; i < Count; i++)
    {
        Input.read((char*)&Byte, 1);
        Result <<= 8;
        Result |= Byte;
    }
    return Result;
}

bool mtDecoder::ParsePTHeader(std::istream& Input)
{
    // Signature
    char Sig[2];
    Input.read(Sig, 2);
    if (memcmp(Sig, "PT", 2) != 0)
    {
        std::cerr << "Missing PT signature." << std::endl;
        return false;
    }

    Input.seekg(2, std::ios_base::cur);

    // Data offset
    uint32_t DataOffset;
    Input.read((char*)&DataOffset, 4);

    // Read in the header (code borrowed from Valery V. Anisimovsky (samael@avn.mccme.ru) )
    unsigned int CompressionType;
    uint8_t byte;
    bool bInHeader;
    bool bInSubHeader;

    bInHeader = true;
    while (bInHeader)
    {
        Input.read((char*)&byte, 1);
        switch (byte) // parse header code
        {
        case 0xFF: // end of header
            bInHeader = false;
        case 0xFE: // skip
        case 0xFC: // skip
            break;
        case 0xFD: // subheader starts...
            bInSubHeader = true;
            while (bInSubHeader)
            {
                Input.read((char*)&byte, 1);
                switch (byte) // parse subheader code
                {
                case 0x83:
                    Input.read((char*)&byte, 1);
                    CompressionType = ReadBytes(Input, byte);
                    break;
                case 0x85:
                    Input.read((char*)&byte, 1);
                    m_TotalSampleCount = ReadBytes(Input, byte);
                    break;
                case 0xFF:
                    break;
                case 0x8A: // end of subheader
                    bInSubHeader = false;
                default: // ???
                    Input.read((char*)&byte, 1);
                    Input.seekg(byte, std::ios_base::cur);
                }
            }
            break;
        default:
            Input.read((char*)&byte, 1);
            if (byte == 0xFF)
                Input.seekg(4, std::ios_base::cur);
            Input.seekg(byte, std::ios_base::cur);
        }
    }

    // Print some things out
    std::cout << "Compression: " << CompressionType << std::endl;

    // Seek to the data offset
    Input.seekg(DataOffset);
    return true;
}

// ================================= Functions ===============================

const unsigned int BitmaskLookupTable[] = {0, 1, 3, 7, 0x0F, 0x1F, 0x3F, 0x7F, 0x0FF};

const unsigned char ByteLookupTable[] = {
    4, 6, 5, 9, 4, 6, 5, 0x0D, 4, 6, 5, 0x0A, 4, 6, 5, 0x11,
    4, 6, 5, 9, 4, 6, 5, 0x0E, 4, 6, 5, 0x0A, 4, 6, 5, 0x15,
    4, 6, 5, 9, 4, 6, 5, 0x0D, 4, 6, 5, 0x0A, 4, 6, 5, 0x12,
    4, 6, 5, 9, 4, 6, 5, 0x0E, 4, 6, 5, 0x0A, 4, 6, 5, 0x19,
    4, 6, 5, 9, 4, 6, 5, 0x0D, 4, 6, 5, 0x0A, 4, 6, 5, 0x11,
    4, 6, 5, 9, 4, 6, 5, 0x0E, 4, 6, 5, 0x0A, 4, 6, 5, 0x16,
    4, 6, 5, 9, 4, 6, 5, 0x0D, 4, 6, 5, 0x0A, 4, 6, 5, 0x12,
    4, 6, 5, 9, 4, 6, 5, 0x0E, 4, 6, 5, 0x0A, 4, 6, 5, 0,
    4, 6, 5, 9, 4, 6, 5, 0x0D, 4, 6, 5, 0x0A, 4, 6, 5, 0x11,
    4, 6, 5, 9, 4, 6, 5, 0x0E, 4, 6, 5, 0x0A, 4, 6, 5, 0x15,
    4, 6, 5, 9, 4, 6, 5, 0x0D, 4, 6, 5, 0x0A, 4, 6, 5, 0x12,
    4, 6, 5, 9, 4, 6, 5, 0x0E, 4, 6, 5, 0x0A, 4, 6, 5, 0x1A,
    4, 6, 5, 9, 4, 6, 5, 0x0D, 4, 6, 5, 0x0A, 4, 6, 5, 0x11,
    4, 6, 5, 9, 4, 6, 5, 0x0E, 4, 6, 5, 0x0A, 4, 6, 5, 0x16,
    4, 6, 5, 9, 4, 6, 5, 0x0D, 4, 6, 5, 0x0A, 4, 6, 5, 0x12,
    4, 6, 5, 9, 4, 6, 5, 0x0E, 4, 6, 5, 0x0A, 4, 6, 5, 2,
    4, 0x0B, 7, 0x0F, 4, 0x0C, 8, 0x13, 4, 0x0B, 7, 0x10, 4, 0x0C,
    8, 0x17, 4, 0x0B, 7, 0x0F, 4, 0x0C, 8, 0x14, 4, 0x0B, 7, 0x10,
    4, 0x0C, 8, 0x1B, 4, 0x0B, 7, 0x0F, 4, 0x0C, 8, 0x13, 4, 0x0B,
    7, 0x10, 4, 0x0C, 8, 0x18, 4, 0x0B, 7, 0x0F, 4, 0x0C, 8, 0x14,
    4, 0x0B, 7, 0x10, 4, 0x0C, 8, 1, 4, 0x0B, 7, 0x0F, 4, 0x0C,
    8, 0x13, 4, 0x0B, 7, 0x10, 4, 0x0C, 8, 0x17, 4, 0x0B, 7, 0x0F,
    4, 0x0C, 8, 0x14, 4, 0x0B, 7, 0x10, 4, 0x0C, 8, 0x1C, 4, 0x0B,
    7, 0x0F, 4, 0x0C, 8, 0x13, 4, 0x0B, 7, 0x10, 4, 0x0C, 8, 0x18,
    4, 0x0B, 7, 0x0F, 4, 0x0C, 8, 0x14, 4, 0x0B, 7, 0x10, 4, 0x0C,
    8, 3, 4, 0x0B, 7, 0x0F, 4, 0x0C, 8, 0x13, 4, 0x0B, 7, 0x10,
    4, 0x0C, 8, 0x17, 4, 0x0B, 7, 0x0F, 4, 0x0C, 8, 0x14, 4, 0x0B,
    7, 0x10, 4, 0x0C, 8, 0x1B, 4, 0x0B, 7, 0x0F, 4, 0x0C, 8, 0x13,
    4, 0x0B, 7, 0x10, 4, 0x0C, 8, 0x18, 4, 0x0B, 7, 0x0F, 4, 0x0C,
    8, 0x14, 4, 0x0B, 7, 0x10, 4, 0x0C, 8, 1, 4, 0x0B, 7, 0x0F,
    4, 0x0C, 8, 0x13, 4, 0x0B, 7, 0x10, 4, 0x0C, 8, 0x17, 4, 0x0B,
    7, 0x0F, 4, 0x0C, 8, 0x14, 4, 0x0B, 7, 0x10, 4, 0x0C, 8, 0x1C,
    4, 0x0B, 7, 0x0F, 4, 0x0C, 8, 0x13, 4, 0x0B, 7, 0x10, 4, 0x0C,
    8, 0x18, 4, 0x0B, 7, 0x0F, 4, 0x0C, 8, 0x14, 4, 0x0B, 7, 0x10,
    4, 0x0C, 8, 3
};

const struct {
    unsigned int HighBits;
    unsigned int SkipBits;
    float Float;
} LookupTable[] = {
    1, 8, 0.0,
    1, 7, 0.0,
    0, 8, 0.0,
    0, 7, 0.0,
    0, 2, 0.0,
    0, 2, -1.0,
    0, 2, 1.0,
    0, 3, -1.0,
    0, 3, 1.0,
    1, 4, -2.0,
    1, 4, 2.0,
    1, 3, -2.0,
    1, 3, 2.0,
    1, 5, -3.0,
    1, 5, 3.0,
    1, 4, -3.0,
    1, 4, 3.0,
    1, 6, -4.0,
    1, 6, 4.0,
    1, 5, -4.0,
    1, 5, 4.0,
    1, 7, -5.0,
    1, 7, 5.0,
    1, 6, -5.0,
    1, 6, 5.0,
    1, 8, -6.0,
    1, 8, 6.0,
    1, 7, -6.0,
    1, 7, 6.0
};

const float FloatLookupTable[] = {
    0.0f, -9.9677598e-1f, -9.90327e-1f, -9.8387903e-1f, -9.77431e-1f,
    -9.7098202e-1f, -9.6453398e-1f, -9.58085e-1f, -9.5163703e-1f,
    -9.3075401e-1f, -9.0495998e-1f, -8.7916702e-1f, -8.5337299e-1f,
    -8.2757902e-1f, -8.0178601e-1f, -7.7599198e-1f, -7.5019801e-1f,
    -7.2440499e-1f, -6.9861102e-1f, -6.7063498e-1f, -6.19048e-1f,
    -5.6746e-1f, -5.1587301e-1f, -4.64286e-1f, -4.12698e-1f,
    -3.6111099e-1f, -3.09524e-1f, -2.5793701e-1f, -2.06349e-1f,
    -1.54762e-1f, -1.03175e-1f, -5.1587e-2f, 0.0, 5.1587e-2f,
    1.03175e-1f, 1.54762e-1f, 2.06349e-1f, 2.5793701e-1f, 3.09524e-1f,
    3.6111099e-1f, 4.12698e-1f, 4.64286e-1f, 5.1587301e-1f,
    5.6746e-1f, 6.19048e-1f, 6.7063498e-1f, 6.9861102e-1f, 7.2440499e-1f,
    7.5019801e-1f, 7.7599198e-1f, 8.0178601e-1f, 8.2757902e-1f,
    8.5337299e-1f, 8.7916702e-1f, 9.0495998e-1f, 9.3075401e-1f,
    9.5163703e-1f, 9.58085e-1f, 9.6453398e-1f, 9.7098202e-1f,
    9.77431e-1f, 9.8387903e-1f, 9.90327e-1f, 9.9677598e-1f
};

int GetBits(SM10DecoderPrivate* DecoderStruct, int Count)
{
    unsigned int Result;
    Result = DecoderStruct->CurrentBits & BitmaskLookupTable[Count];
    DecoderStruct->BitCount -= Count;
    DecoderStruct->CurrentBits >>= Count;

    if (DecoderStruct->BitCount < 8)
    {
        unsigned int NewBits;
        NewBits = *DecoderStruct->CompressedData << DecoderStruct->BitCount;

        DecoderStruct->CurrentBits = NewBits | DecoderStruct->CurrentBits;
        DecoderStruct->CompressedData++;
        DecoderStruct->BitCount += 8;
    }
    return Result;
}

void SkipBits(SM10DecoderPrivate *DecoderStruct, int Count)
{
    DecoderStruct->BitCount -= Count;
    DecoderStruct->CurrentBits >>= Count;

    if (DecoderStruct->BitCount < 8)
    {
        unsigned int NewBits;
        NewBits = *DecoderStruct->CompressedData << DecoderStruct->BitCount;

        DecoderStruct->CurrentBits = NewBits | DecoderStruct->CurrentBits;
        DecoderStruct->CompressedData++;
        DecoderStruct->BitCount += 8;
    }
    return;
}

void FunctionOne(float* Buffer)
{
    float* CurrentPtr = Buffer + 5;

    for (unsigned int i = 0; i < 54 ; i++)
    {
        double a = CurrentPtr[-8] + CurrentPtr[-2];
        double b = CurrentPtr[-10] + CurrentPtr[0];
        double c = CurrentPtr[-6] + CurrentPtr[-4];

        CurrentPtr[-5] = (float)(a * -0.11459156 + b * 0.01803268 + c * 0.59738597);
        CurrentPtr += 2;
    }
    return;
}

void FunctionTwo(float* DecoderStructTable1, float* Arg2)
{
    float Table[24];

    for (unsigned i = 0; i < 11; i++)
    {
        Table[11 - i] = DecoderStructTable1[10 - i];
    }

    Table[0] = 1.0;

    for (unsigned int i = 0; i < 12; i++)
    {
        double Previous;
        Previous = -Table[11] * DecoderStructTable1[11];

        for (unsigned int CounterC = 0; CounterC < 11; CounterC++)
        {
            float* PtrA = Table + 10 - CounterC;
            float* PtrB = DecoderStructTable1 + 10 - CounterC;

            Previous -= (*PtrA) * (*PtrB);
            Table[11 - CounterC] = float(Previous) * (*PtrB) + (*PtrA);
        }

        Table[0] = float(Previous);
        Table[i + 12] = float(Previous);

        if (i > 0)
        {
            unsigned int CounterA = i;
            unsigned int CounterB = i;

            for (unsigned int j = 0; j < i; j++)
            {
                Previous -= Table[11 + i - j] * Arg2[j];
            }
        }

        Arg2[i] = float(Previous);
    }
    return;
}

void FunctionThree(SM10DecoderPrivate* DecoderStruct, int Flag, float* Out, unsigned int CountInt)
{
    if (Flag != 0)
    {
        unsigned int Index = 0;
        unsigned int HighBits = 0;

        do
        {
            unsigned int LookedUpValue;
            unsigned int Bits;
            Bits = DecoderStruct->CurrentBits & 0xFF;;

            LookedUpValue = ByteLookupTable[(HighBits << 8) + Bits];
            HighBits = LookupTable[LookedUpValue].HighBits;

            SkipBits(DecoderStruct, LookupTable[LookedUpValue].SkipBits);

            if (LookedUpValue > 3)
            {
                Out[Index] = LookupTable[LookedUpValue].Float;
                Index += CountInt;
            }
            else if (LookedUpValue > 1)
            {
                unsigned int Bits;
                Bits = GetBits(DecoderStruct, 6) + 7;

                if (Bits * CountInt + Index > 108)
                {
                    Bits = (108 - Index) / CountInt;
                }

                if (Bits > 0)
                {
                    float* Ptr;
                    Ptr = Out + Index;
                    Index += Bits * CountInt;

                    for (unsigned int i = 0; i < Bits; i++)
                    {
                        *Ptr = 0;
                        Ptr += CountInt;
                    }
                }
            }
            else
            {
                int Count = 7;

                while (GetBits(DecoderStruct, 1) == 1)
                {
                    Count++;
                }

                if (GetBits(DecoderStruct, 1))
                {
                    Out[Index] = float(Count);
                }
                else
                {
                    Out[Index] = -float(Count);
                }

                Index += CountInt;
            }
        } while (Index < 108);
    }
    else
    {
        unsigned int Index = 0;

        do
        {
            switch (DecoderStruct->CurrentBits & 0x3)
            {
            case 1:
                Out[Index] = -2.0;
                SkipBits(DecoderStruct, 2);
                break;
            case 3:
                Out[Index] = 2.0;
                SkipBits(DecoderStruct, 2);
                break;
            case 2:
            case 0:
                Out[Index] = 0;
                SkipBits(DecoderStruct, 1);
                break;
            default:
                break;
            }
            Index += CountInt;
        } while (Index < 108);
    }
    return;
}

void FunctionFour(SM10DecoderPrivate* DecoderStruct, unsigned int Index, unsigned int Count)
{
    float Buffer[12];
    FunctionTwo(DecoderStruct->Table1, Buffer);

    float* Ptr;
    Ptr = DecoderStruct->SampleBuffer + Index;

    for (unsigned int i = 0; i < Count; i++)
    {
        for (unsigned int k = 0; k < 12; k++)
        {
            double Summation = 0.0;
            for (unsigned int j = 0; j < 12; j++)
            {
                Summation += DecoderStruct->Table2[j] * Buffer[(j + k) % 12];
            }

            double Result = Ptr[k] + Summation;
            DecoderStruct->Table2[11 - k] = float(Result);
            Ptr[k] = float(Result);
        }
        Ptr += 12;
    }
    return;
}

void InitializeDecoder(SM10DecoderPrivate* DecoderStruct, uint8_t* CompressedData)
{
    DecoderStruct->CurrentBits = CompressedData[0];
    DecoderStruct->CompressedData = CompressedData + 1;
    DecoderStruct->BitCount = 8;
    DecoderStruct->FirstBit = GetBits(DecoderStruct, 1);
    DecoderStruct->Second4Bits = 32 - GetBits(DecoderStruct, 4);
    DecoderStruct->FloatTable[0] = float(GetBits(DecoderStruct, 4) + 1) * 8.0f;

    double AFloat = 1.04 + double(GetBits(DecoderStruct, 6)) * 0.001;
    for (unsigned int i = 0; i < 63; i++)
    {
        DecoderStruct->FloatTable[i + 1] = float(DecoderStruct->FloatTable[i] * AFloat);
    }
    memset(DecoderStruct->Table1, 0, sizeof(float) * 12);
    memset(DecoderStruct->Table2, 0, sizeof(float) * 12);
    memset(DecoderStruct->BigTable, 0, sizeof(float) * 324);
    return;
}

void DecodeBlock(SM10DecoderPrivate* DecoderStruct)
{
    float TableA[12];
    float TableB[118];

    unsigned int Bits;
    Bits = GetBits(DecoderStruct, 6);

    int Flag;
    Flag = Bits < DecoderStruct->Second4Bits ? 1 : 0;

    TableA[0] = (FloatLookupTable[Bits] - DecoderStruct->Table1[0]) * 0.25f;

    for (unsigned int i = 1; i < 4; i++)
    {
        Bits = GetBits(DecoderStruct, 6);

        TableA[i] = (FloatLookupTable[Bits] - DecoderStruct->Table1[i]) * 0.25f;
    }

    for (unsigned int i = 4; i < 12; i++)
    {
        Bits = GetBits(DecoderStruct, 5);

        TableA[i] = (FloatLookupTable[Bits + 16] - DecoderStruct->Table1[i]) * 0.25f;
    }

    float* CurSampleBufPtr = DecoderStruct->SampleBuffer;

    for (unsigned int i = 216; i < 648; i += 108)
    {
        unsigned int BigTableIndex;
        BigTableIndex = i - GetBits(DecoderStruct, 8);

        float SomeFloat;
        float SomeOtherFloat;
        SomeFloat = float(GetBits(DecoderStruct, 4)) * 2.0f / 30.0f;
        SomeOtherFloat = DecoderStruct->FloatTable[GetBits(DecoderStruct, 6)];

        if (!DecoderStruct->FirstBit)
        {
            FunctionThree(DecoderStruct, Flag, TableB + 5, 1);
        }
        else
        {
            unsigned char IndexAdjust;

            IndexAdjust = GetBits(DecoderStruct, 1);
            Bits = GetBits(DecoderStruct, 1);

            FunctionThree(DecoderStruct, Flag, TableB + 5 + IndexAdjust, 2);

            if (Bits)
            {
                for (unsigned int i = 0; i < 108; i += 2)
                {
                    TableB[i + 6 - IndexAdjust] = 0;
                }
            }
            else
            {
                for (unsigned long i = 0; i < 5; i++)
                {
                    TableB[i] = 0;
                    TableB[i + 113] = 0;
                }

                FunctionOne(TableB + 6 - IndexAdjust);
                SomeOtherFloat *= 0.5;
            }
        }

        float* BigTablePtr = DecoderStruct->BigTable + BigTableIndex;

        for (unsigned int i = 0; i < 108; i++)
        {
            *CurSampleBufPtr = SomeOtherFloat * TableB[i + 5] + SomeFloat * BigTablePtr[i];
            CurSampleBufPtr++;
        }
    }

    for (unsigned int i = 0; i < 324; i++)
    {
        DecoderStruct->BigTable[i] = DecoderStruct->SampleBuffer[i + 108];
    }

    for (unsigned int i = 0; i < 12; i++)
    {
        DecoderStruct->Table1[i] += TableA[i];
    }
    FunctionFour(DecoderStruct, 0, 1);

    for (unsigned int i = 0; i < 12; i++)
    {
        DecoderStruct->Table1[i] += TableA[i];
    }
    FunctionFour(DecoderStruct, 12, 1);

    for (unsigned int i = 0; i < 12; i++)
    {
        DecoderStruct->Table1[i] += TableA[i];
    }
    FunctionFour(DecoderStruct, 24, 1);

    for (unsigned int i = 0; i < 12; i++)
    {
        DecoderStruct->Table1[i] += TableA[i];
    }
    FunctionFour(DecoderStruct, 36, 33);
    return;
}
