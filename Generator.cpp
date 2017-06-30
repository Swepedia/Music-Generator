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
    numMelodies = 3;
    BPM = 72;
    key = 0;
    name = "sample";
    sequence[0] = '*';
    sequence[1] = '*';
    sequence[2] = '*';
    sequence[3] = '+';
    sequence[4] = '+';
    sequence[5] = '+';
    sequence[6] = '+';
    sequence[7] = '+';
    sequence[8] = '.';
    sequence[9] = '.';
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

void Generator::generate() {
}
