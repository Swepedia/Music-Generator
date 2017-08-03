#include<cmath>
#include<map>
#include"fileToWav.h"

map<char, double> fileToWav::getFrequency(unsigned int key) {
    map<char, double> frequencies;
    switch(key) {
        //major keys:
        //C
        case 0:
            {
                frequencies = {{'A', A4}, {'B', B4}, {'C', C4}, {'D', D4}, {'E', E4}, {'F', F4}, {'G', G4}};
                break;
            }
        //F
        case 1:
            {
                frequencies = {{'A', A4}, {'B', AS4}, {'C', C5}, {'D', D5}, {'E', E5}, {'F', F4}, {'G', G4}};
                break;
            }
        //Bb
        case 2:
            {
                frequencies = {{'A', A4}, {'B', AS3}, {'C', C4}, {'D', D4}, {'E', DS4}, {'F', F4}, {'G', G4}};
                break;
            }
        //Eb
        case 3:
            {
                frequencies = {{'A', GS4}, {'B', AS4}, {'C', C5}, {'D', D5}, {'E', DS4}, {'F', F4}, {'G', G4}};
                break;
            }
        //Ab
        case 4:
            {
                frequencies = {{'A', GS3}, {'B', AS3}, {'C', C4}, {'D', CS4}, {'E', DS4}, {'F', F4}, {'G', G4}};
                break;
            }
        //Db
        case 5:
            {
                frequencies = {{'A', GS4}, {'B', AS4}, {'C', C5}, {'D', CS4}, {'E', DS4}, {'F', F4}, {'G', FS4}};
                break;
            }
        //Gb
        case 6:
            {
                frequencies = {{'A', GS3}, {'B', AS3}, {'C', B3}, {'D', CS4}, {'E', DS4}, {'F', F4}, {'G', FS3}};
                break;
            }
        //B
        case 7:
            {
                frequencies = {{'A', AS4}, {'B', B3}, {'C', CS4}, {'D', DS4}, {'E', E4}, {'F', FS4}, {'G', GS4}};
                break;
            }
        //E
        case 8:
            {
                frequencies = {{'A', A4}, {'B', B4}, {'C', CS5}, {'D', DS5}, {'E', E4}, {'F', FS4}, {'G', GS4}};
                break;
            }
        //A
        case 9:
            {
                frequencies = {{'A', A3}, {'B', B3}, {'C', CS4}, {'D', D4}, {'E', E4}, {'F', FS4}, {'G', GS4}};
                break;
            }
        //D
        case 10:
            {
                frequencies = {{'A', A4}, {'B', B4}, {'C', CS5}, {'D', DS4}, {'E', E4}, {'F', FS4}, {'G', G4}};
                break;
            }
        //G
        case 11:
            {
                frequencies = {{'A', A3}, {'B', B3}, {'C', C4}, {'D', D4}, {'E', E4}, {'F', FS4}, {'G', G3}};
                break;
            }
        //Harmonic Minor:
        //A
        case 12:
            {
                frequencies = {{'A', A4}, {'B', B4}, {'C', C4}, {'D', D4}, {'E', E4}, {'F', F4}, {'G', GS4}};
                break;
            }                                                                                                
        //D                                                                                                  
        case 13:                                                                                             
            {                                                                                                
                frequencies = {{'A', A4}, {'B', AS4}, {'C', CS5}, {'D', D5}, {'E', E5}, {'F', F4}, {'G', G4}};
                break;
            }                                                                                                
        //G                                                                                                 
        case 14:                                                                                             
            {                                                                                                
                frequencies = {{'A', A4}, {'B', AS3}, {'C', C4}, {'D', D4}, {'E', DS4}, {'F', FS4}, {'G', G4}};
                break;
            }                                                                                                
        //C                                                                                                 
        case 15:                                                                                             
            {                                                                                                
                frequencies = {{'A', GS4}, {'B', B4}, {'C', C5}, {'D', D5}, {'E', DS4}, {'F', F4}, {'G', G4}};
                break;
            }                                                                                                
        //F                                                                                                 
        case 16:                                                                                             
            {                                                                                                
                frequencies = {{'A', GS3}, {'B', AS3}, {'C', C4}, {'D', CS4}, {'E', E4}, {'F', F4}, {'G', G4}};
                break;
            }                                                                                                
        //Bb                                                                                                 
        case 17:                                                                                             
            {                                                                                                
                frequencies = {{'A', A4}, {'B', AS4}, {'C', C5}, {'D', CS4}, {'E', DS4}, {'F', F4}, {'G', FS4}};
                break;
            }                                                                                                
        //Eb                                                                                                 
        case 18:                                                                                             
            {                                                                                                
                frequencies = {{'A', GS3}, {'B', AS3}, {'C', B3}, {'D', D4}, {'E', DS4}, {'F', F4}, {'G', FS3}};
                break;
            }                                                                                                
        //G#                                                                                                 
        case 19:                                                                                             
            {                                                                                                
                frequencies = {{'A', AS4}, {'B', B3}, {'C', CS4}, {'D', DS4}, {'E', E4}, {'F', G4}, {'G', GS4}};
                break;
            }                                                                                                
        //C#                                                                                                 
        case 20:                                                                                             
            {                                                                                                
                frequencies = {{'A', A4}, {'B', C5}, {'C', CS5}, {'D', DS5}, {'E', E4}, {'F', FS4}, {'G', GS4}};
                break;
            }                                                                                                
        //F#                                                                                                 
        case 21:                                                                                             
            {                                                                                                
                frequencies = {{'A', A3}, {'B', B3}, {'C', CS4}, {'D', D4}, {'E', F4}, {'F', FS4}, {'G', GS4}};
                break;
            }                                                                                                
        //B                                                                                                  
        case 22:
            {                                                                                                
                frequencies = {{'A', AS4}, {'B', B4}, {'C', CS5}, {'D', DS4}, {'E', E4}, {'F', FS4}, {'G', G4}};
                break;
            }                                                                                                
        //E                                                                                                  
        case 23:
            {                                                                                                
                frequencies = {{'A', A3}, {'B', B3}, {'C', C4}, {'D', DS4}, {'E', E4}, {'F', FS4}, {'G', G3}};
                break;
            }
    }
    return frequencies;
}

void fileToWav::createWav(vector<string> files) {
}
