#include<cmath>
#include<map>
#include"fileToWav.h"

map<char, double> fileToWav::getFrequency(unsigned int key) {
    map<char, double> frequencies;
    switch(key) {
        case 0:
            {
                frequencies = {{'A', A4}, {'B', B4}, {'C', C4}, {'D', D4}, {'E', E4}, {'F', F4}, {'G', G4}};
                break;
            }
        case 1:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
        case 2:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
        case 3:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
        case 4:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
        case 5:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
        case 6:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
        case 7:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
        case 8:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
        case 9:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
        case 10:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
        case 11:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
        case 12:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
        case 13:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
        case 14:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
        case 15:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
        case 16:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
        case 17:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
        case 18:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
        case 19:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
        case 20:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
        case 21:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
        case 22:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
        case 23:
            {
                frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 1}, {'F', 1}, {'G', 1}};
                break;
            }
    }
    return frequencies;
}

void fileToWav::createWav(vector<string> files) {
}
