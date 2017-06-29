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

int numMelodies;
int BPM;
int key;
string name;
char sequence[] = {'*', '*', '*', '+', '+', '+', '+', '+', '.', '.', '\0'};

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
}

int Generator::getNumMelodies() {
    return numMelodies;
}

int Generator::getBPM() {
    return BPM;
}

int Generator::getKey() {
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

void Generator::setKey(int k) {
    key = k;
}

void Generator::setSequence(char s[]) {
    for(int i = 0; i < 10; i++) {
        sequence[i] = s[i];
    }
}
