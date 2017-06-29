//@author: Maxwell Heeschen

#include"Generator.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

//
//Private
//

int numMelodies;
int BPM;
int key;
char sequence[11];
string name;

void Generator::writeToFile(vector<char> notes, string append) {

}

//
//Public
//

Generator::Generator() {

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
    sequence[10] = '\0';
}
