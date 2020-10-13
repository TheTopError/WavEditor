#pragma once
#include <stdint.h>
#include <fstream>
#include <string>
//http://soundfile.sapp.org/doc/WaveFormat/

class Wav
{
public: 

	std::string path;

	//RIFF-Header - Beginnt mit "Riff" in Ascii
	int chunkSize; //Dateilänge in Bytes - 8 (-8, weil ChunkID und ChunkSize nicht miteinberechnet werden)

	//Subchunk-1 - Beginnt mit "fmt " und beschreibt sound data format
	int formatSize; //Anzehl der Bytes vom Rest des subchunks
	uint8_t audioFormat; //Sollte 1 sein (Linear Quantization, no compression)
	uint8_t channels; //1 Mono, 2 Stereo
	int sampleRate; // Rate in der ein Analogsignal gemessen und in ein Signal umgewandelt wird (hz)
	
	int bytePerSec; //sampleRate * channels * bitsPerSample/8
	int blockAlign; //Nummer von einem Sample mit allen Channeln abgerundet: blockAlign = channels * ((sampleRate + 7) / 8)
	uint8_t bitsPerSample;

	//Zwei weitere Werte falls PCM vorhanden
    //Bei stereo wird erst der linke, dann der rechte kanal gespeichert. 12 12 12 12

	//SampleRate: X
	//sampleData[X]/0xff: Y

	//Subchunk-2 - Beginnt mit "data"
	int dataSize; //Anzahl der Bytes vom Rest des Subchunks, kann man mit NumSamples * NumChannels * BitsPerSample/8 errechnen

	uint8_t* sampleData;




private:



public:

	Wav();
	~Wav();

	void UpdateValues();
	void PlayWav();
	void WriteToFile();
	void ReadFromFile(const char* path = "sine.wav");
	std::string GetValues();

private:


};

