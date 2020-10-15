#include "Wav.h"

Wav::Wav()
{
}

void Wav::ReadFromFile(const char* path)
{
    this->path = path;
    std::ifstream file(path, std::ios::binary);

    char riff[5] = {}, wave[5] = {};

    file.read(riff, 4);
    file.read((char*)&chunkSize, 4);
    file.read(wave, 4);

    if (strcmp(riff, "RIFF") == 0 && strcmp(wave, "WAVE") == 0)
    {
        chunkSize += 8; 
 
        //-----Format-----
        file.seekg(16); //ignore fmt 
        file.read((char*)&formatSize, 4); //TODO: MAN KANN VON HIER TESTEN, OB ZUSATZPARAMETER GEBRAUCHT WERDEN

        {
            int temp = 0;
            file.read((char*)&temp, 4); //einen halben byte zu verarbeiten ist nervig

            audioFormat = temp & 0x0F;
            channels = temp >> 16; 
        }

        file.read((char*)&sampleRate, 4);
        file.read((char*)&bytePerSec, 4);

        {
            int temp = 0;
            file.read((char*)&temp, 4); //einen halben byte zu verarbeiten ist nervig

            blockAlign = temp & 0x0F;
            bitsPerSample = temp >> 16;
        }

        char data[5] = {};
        file.read(data, 4);

        if (strcmp(data, "data") == 0)
        {
            //-----Data-----
            file.read((char*)&dataSize, 4);

            if (bitsPerSample == 8)
            {
                sampleData = new float[dataSize];
                for (int i = 0; i < dataSize; i++)
                {
                    uint8_t temp = 0;
                    file.read((char*)&temp, 1);
                    sampleData[i] = (float)temp / 0xff;
                }
            }
            else
            {
                dataSize /= 2;
                sampleData = new float[dataSize];
                for (int i = 0; i < dataSize; i++)
                {
                    uint16_t temp = 0;
                    file.read((char*)&temp, 2);
                    sampleData[i] = (float)temp / 0xffff;
                }
            }
        }
        else
        {
            //ERROR: File has extra params after Byte 34
        }

    }
    else
    {
        //ERROR: Wrong file format
    }

    file.close();
}

void Wav::Clear()
{
    chunkSize = 0;
    formatSize = 0;
    audioFormat = 0;
    channels = 0;
    sampleRate = 0;
    bytePerSec = 0;
    blockAlign = 0;
    bitsPerSample = 0;
    sampleData = nullptr;
}

std::string Wav::GetValues()
{
    std::string res = "";
    res += "Path: ";
    res += path;
    res += "\nFilelength: " + std::to_string(chunkSize);
    res += "\nSampleRate: " + std::to_string(sampleRate);
    res += "\nChannel: ";
    if (channels == 1) res += "Mono";
    else if (channels == 2) res += "Stereo";

    return res;
}


Wav::~Wav()
{
    delete[] sampleData;
}