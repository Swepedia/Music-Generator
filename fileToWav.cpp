#include<cmath>
#include"fileToWav.h"
#include<fstream>
#include<iostream>

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

fileToWav::fileToWav() {
}

void fileToWav::createWav(vector<string> files) {
    string currentFile;
    string songName;
    int songNameLength;
    int key;
    int BPM;

    for(int i = 0; i < files[0].size(); i++) {
        if(files[0][i] == '_') {
            songNameLength = i;
        }
    }
    songName = files[0].substr(0, songNameLength) + ".wav";
    vector<string> notes;

    ofstream wavFile(songName.c_str(), ios::binary);
    if(wavFile.fail()) {
        cout << "Failed to create WAV file.\n";
        exit(1);
    }

    //Writing the WAVE header stuff
    wavFile << "RIFF----WAVfmt ";
    writeWord(wavFile, 16, 4); //Subchunk1 Size
    writeWord(wavFile, 1, 2); //Audio format, 1 = PCM
    writeWord(wavFile, 1, 2); //Number of channels
    writeWord(wavFile, 44100, 4); //Sample rate
    writeWord(wavFile, 88200, 4); //Byte rate (SampleRate * NumChannels * BitsPerSample) / 8
    writeWord(wavFile, 2, 2); //Block Align = NumChannels * BitsPerSample / 8
    writeWord(wavFile, 16, 2); //Bits Per Sample

    //keep track of the data chunk position
    size_t dataChunkPos = wavFile.tellp();
    wavFile << "data----";


    for(int i = 0; i < files.size(); i++) {
        ifstream input;

        currentFile = files[i];

        input.open(currentFile);
        if(input.fail()) {
            cout << "Could not open " << currentFile << endl;
            exit(1);
        }
        unsigned int key = input.get();
        map<char, double> frequencies = getFrequency(key);
        vector<char> notes;

        while(!input.eof()) {
            notes.push_back(input.get());
        }

        unsigned int BPM = notes.size() / 4;

        
        double lengthOfNote = 60 / BPM; //Use 60 because it's how many seconds in a minute
        double hz = 44100; //Samples per second
        int numSamples = hz * lengthOfNote;
        const double twoPi = 6.283185307179586476925286766559; 

        //Only checking the first letter to see if it is a 'melody', 'base',
        //or 'percussion' file
        wavFile.seekp(dataChunkPos + 8);
        if(currentFile[songNameLength + 1] == 'm') {
            for(int j = 0; j < notes.size(); j++) {
                if(notes[j] != '-' && notes[j] != ' ') {
                    for(int k = 0; k < numSamples; k++) {
                        writeWord(wavFile, (int)(sin(twoPi * k * frequencies[notes[j]])));
                    }
                }
            }
        }
        else if(currentFile[songNameLength + 1] == 'b') {
        }
        else if(currentFile[songNameLength + 1] == 'p') {
        }
        input.close();
    }
    size_t fileLength = wavFile.tellp();
    wavFile.seekp(dataChunkPos + 4);
    writeWord(wavFile, fileLength - dataChunkPos + 8);
    wavFile.seekp(4);
    writeWord(wavFile, fileLength - 8, 4);
}
