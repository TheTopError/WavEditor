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
	short formatSize; //Anzehl der Bytes vom Rest des subchunks
	short audioFormat; //Sollte 1 sein (Linear Quantization, no compression)
	short channels; //1 Mono, 2 Stereo
	int sampleRate; // Rate in der ein Analogsignal gemessen und in ein Signal umgewandelt wird (hz)
	
	int bytePerSec; //sampleRate * channels * bitsPerSample/8
	int blockAlign; //Nummer von einem Sample mit allen Channeln abgerundet: blockAlign = channels * ((sampleRate + 7) / 8)
	int bitsPerSample;

	//Zwei weitere Werte falls PCM vorhanden
    //Bei stereio wird erst der linke, dann der rechte kanal gespeichert.

	//Subchunk-2 - Beginnt mit "data"
	int dataSize; //Anzahl der Bytes vom Rest des Subchunks, kann man mit NumSamples * NumChannels * BitsPerSample/8 errechnen

	//sampledata

	unsigned char* sampleData;




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

