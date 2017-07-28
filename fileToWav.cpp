#include<cmath>
#include"fileToWav.h"

unsigned int* getIntervals(unsigned int key) {
    int pos1;
    int pos2;
    unsigned int* intervals;
    if(key < 7) {
        unsigned int intervals[6] = {2, 2, 1, 2, 2, 2};
        pos1 = 2;
        pos2 = 6;
    }
    for(; key; --key) {
        if(key % 2 == 0) {
            intervals[pos1--] = 2;
            if(pos1 >= 0) {
                intervals[pos1] = 1;
            }
        }
        else {
            if(pos2 == 6) {
                intervals[--pos2] = 1;
            }
            else {
                intervals[pos2--] = 2;
                intervals[pos2] = 1;
            }
        }
    }
    return intervals;
}

double getFrequency(int intervals[], unsigned int key) {
    double frequency;
    return frequency;
}

void fileToWav::createWav(vector<string> files) {
}
