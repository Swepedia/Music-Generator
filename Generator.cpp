//@author: Maxwell Heeschen

#include"Generator.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdlib>

using namespace std;

//
//Private
//

void Generator::writeToFile(vector<char> notes, string append) {
    ofstream outStream;

    string temp = getName();
    temp + "_";
    temp + append;
    outStream.open(temp.c_str());
    if(outStream.fail()) {
        cout << "Output file opening failed.\n";
        exit(1);
    }

    for(unsigned int i = 0; i < notes.size(); i++) {
        outStream << notes[i];
    }

    outStream.close();
}

//
//Public
//

Generator::Generator() {
    setNumMelodies(3);
    setBPM(72);
    setKey(0);
    setName("sample");
    char temp[] = {'*', '*', '*', '+', '+','+','+','+', '.', '.'};
    setSequence(temp);
//    sequence[0] = '*';
//    sequence[1] = '*';
//    sequence[2] = '*';
//    sequence[3] = '+';
//    sequence[4] = '+';
//    sequence[5] = '+';
//    sequence[6] = '+';
//    sequence[7] = '+';
//    sequence[8] = '.';
//    sequence[9] = '.';
}

int Generator::getNumMelodies() {
    return numMelodies;
}

int Generator::getBPM() {
    return BPM;
}

char Generator::getKey() {
    return key;
}

string Generator::getName() {
    return name;
}

void Generator::setNumMelodies(int num) {
    numMelodies = num;
}

void Generator::setBPM(int beat) {
    BPM = beat;
}

void Generator::setKey(char k) {
    key = k;
}

void Generator::setSequence(char s[]) {
    for(int i = 0; i < 10; i++) {
        sequence[i] = s[i];
    }
}

void Generator::setName(string n) {
    name = n;
}

void Generator::generate() {
    int numNotes;
    int lengthIntro;
    int lengthMiddle;
    int lengthOutro;
    vector<char> notes;

    //I'm using 4 because I want all the songs to be 4 minutes long
    numNotes = getBPM() * 4;

    for(int i = 0; i < 10; i++) {
        if(sequence[i] == SYMBOL_INTRO) {
            lengthIntro++;
        }
        else if(sequence[i] == SYMBOL_MIDDLE) {
            lengthMiddle++;
        }
        else if(sequence[i] == SYMBOL_OUTRO) {
            lengthOutro++;
        }
    }
}
