#include "Wav.h"

Wav::Wav()
{
}

void Wav::ReadFromFile(const char* path)
{
    this->path = path;
    std::ifstream file(path, std::ios::binary);
    uint8_t currentByte = 0;

    char riff[5] = {}, wave[5] = {};
    file.read(riff, 4);
    file.seekg(8);
    file.read(wave, 4);

    if (strcmp(riff, "RIFF") == 0 && strcmp(wave, "WAVE") == 0)
    {
        file.seekg(4);
        file.read((char*)&chunkSize, 4);
        chunkSize += 8;

        currentByte += 16; // 16

        //-----Format-----
        file.seekg(currentByte);
        file.read((char*)&formatSize, 4); //TODO: MAN KANN VON HIER TESTEN, OB ZUSATZPARAMETER GEBRAUCHT WERDEN
        currentByte += 4; // 20

        file.seekg(currentByte);
        {
            int temp = 0;
            file.read((char*)&temp, 4); //einen halben byte zu verarbeiten ist nervig

            audioFormat = temp & 0x0F;
            channels = temp >> 16; 

        }
        currentByte += 4; // 24

        file.seekg(currentByte);
        file.read((char*)&sampleRate, 4);
        currentByte += 4; // 28

        file.seekg(currentByte);
        file.read((char*)&bytePerSec, 4);
        currentByte += 4; // 32

        file.seekg(currentByte);
        {
            int temp = 0;
            file.read((char*)&temp, 4); //einen halben byte zu verarbeiten ist nervig

            blockAlign = temp & 0x0F;
            bitsPerSample = temp >> 16;

        }
        currentByte += 4; // 36

        file.seekg(currentByte);
        char data[5] = {};
        file.read(data, 4);
        currentByte += 4; // 40

        if (strcmp(data, "data") == 0)
        {
            //-----Data-----
            file.seekg(currentByte);
            file.read((char*)&dataSize, 4);
            currentByte += 4; // 44

            sampleData = new unsigned char[dataSize];

            for (int i = 0; i < dataSize; i++)
            {
                file.seekg(i + currentByte);
                file.read((char*)&sampleData[i], 1);
                //Access by casting to int or float
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