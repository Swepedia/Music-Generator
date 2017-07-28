#ifndef FILETOWAV_H
#define FILETOWAV_H

#include<fstream>
#include<string>
#include<vector>

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
        const double C_FREQUENCY = 261.626;
        const double CFLAT_FREQUENCY = 246.94;
        unsigned int* getIntervals(unsigned int key);
        /*
         * Gets the length of the intervals between different notes. The
         * intervals between the notes are between 1-2, and the 1 intervals
         * travel like an inch worm to the left if you list the notes starting
         * with C going to B. There are never more than 2 intervals of 1 in the
         * set of 7 notes, and the space between the 1 intervals changes
         * between 2-3 as the 'inch worm' travels to the left
         */

        double getFrequency(int intervals[], unsigned int key);
    public:
        void createWav(vector<string> files);
};

#endif
