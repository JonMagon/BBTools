// WaveWriter.h : Functions for writing wave files
//

#pragma once

void PrepareWaveHeader(std::ostream& Output);
void WriteWaveHeader(std::ostream& Output, unsigned long SampleRate, \
					 unsigned char BitsPerSample, unsigned char Channels, \
					 unsigned long NumberSamples);
