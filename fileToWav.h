#ifndef FILETOWAV_H
#define FILETOWAV_H

#include<fstream>
#include<string>
#include<vector>
#include<map>

using namespace std;

namespace littleEndian
{
    template<typename Word>
    void writeWord(ostream out, Word word, unsigned size = sizeof(Word)) {
        for(; size; --size, word >>= 8) {
            out.put(static_cast<char> (word & 0xFF));
        }
    }
}

using namespace littleEndian;

class fileToWav
{
    private:
        const double G3 = 196.0;
        const double GS3 = 207.7;
        const double A3 = 220.0;
        const double AS3 = 233.1;
        const double B3 = 246.9;
        const double C4 = 261.6;
        const double CS4 = 277.2;
        const double D4 = 293.7;
        const double DS4 = 311.1;
        const double E4 = 329.6;
        const double F4 = 349.2;
        const double FS4 = 370;
        const double G4 = 392.0;
        const double GS4 = 415.3;
        const double A4 = 440.0;
        const double AS4 = 466.2;
        const double B4 = 493.9;
        const double C5 = 523.3;
        const double CS5 = 554.4;
        const double D5 = 587.3;
        const double DS5 = 622.3;
        const double E5 = 659.3;
        map<char, double> getFrequency(unsigned int key);

    public:
        void createWav(vector<string> files);
};

#endif
