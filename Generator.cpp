//@author: Maxwell Heeschen

#include"Generator.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<random>

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
    setNumMelodies(1);
    setBPM(72);
    setKey(0);
    setName("sample");
    char temp[] = {'*', '*', '*', '+', '+','+','+','+', '.', '.'};
    setSequence(temp);
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
    string append;

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
    notes.push_back(getKey());

    //Begin generation of the music notes
    //I do all this stuff at the beginning to get a uniform distribution to the
    //random numbers. It also makes it so that I can get different random
    //numbers more than once a second, which would be the case if I used rand()
    random_device randDev;
    mt19937 generator(randDev());
    uniform_int_distribution<int> distr(1, 100);
    uniform_int_distribution<int> distrNotes(1, 7);
    int prob = 0;
    int temp;

    for(int i = 0; i < getNumMelodies(); i++) {
        for(int j = 0; j < numNotes; j++) {
            prob = distr(generator);
            if(prob <= 60) {
                temp = distrNotes(generator);
                switch(temp) {
                    case 1:
                        notes.push_back('A');
                        break;
                    case 2:
                        notes.push_back('B');
                        break;
                    case 3:
                        notes.push_back('C');
                        break;
                    case 4:
                        notes.push_back('D');
                        break;
                    case 5:
                        notes.push_back('E');
                        break;
                    case 6:
                        notes.push_back('F');
                        break;
                    case 7:
                        notes.push_back('G');
                        break;
                }
            }
            else if(prob <= 80 && j > 0 && notes[j - 1] != ' ') {
                notes.push_back('-');
            }
            else {
                notes.push_back(' ');
            }
        }
        append = "melody";
        append += i;
        writeToFile(notes, append);
    }
}
