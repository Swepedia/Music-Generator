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
    temp += "_";
    temp += append;
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
    int numNotesIntro;
    int lengthMiddle;
    int numNotesMiddle;
    int lengthOutro;
    int numNotesOutro;
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
    numNotesIntro = (static_cast<double> (lengthIntro) / 10) * numNotes;
    numNotesMiddle = (static_cast<double> (lengthMiddle) / 10) * numNotes; 
    numNotesOutro = (static_cast<double> (lengthOutro) / 10) * numNotes; 

    //Begin generation of the music notes
    //I do all this stuff at the beginning to get a uniform distribution to the
    //random numbers. It also makes it so that I can get different random
    //numbers more than once a second, which would be the case if I used rand()
    random_device randDev;
    mt19937 randGenerator(randDev());
    uniform_int_distribution<int> distr(1, 100);
    uniform_int_distribution<int> distrNotes(1, 7);
    int prob = 0;
    int temp;

    //Generation of melody happens here
    for(int i = 0; i < getNumMelodies(); i++) {
        notes.push_back(getKey());
        for(int j = 0; j < numNotesIntro + numNotesMiddle; j++) {
            prob = distr(randGenerator);
            if(prob <= 60) {
                temp = distrNotes(randGenerator);
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

        //I do this so that the melody only plays during the intro and middle
        for(int j = 0; j < numNotesOutro; j++) {
            notes.push_back(' ');
        }
        append = "melody";
        append += to_string(i);
        writeToFile(notes, append);
        notes.clear();
    }

    //Generation of base line
    
    //Do this so the base line doesn't play during the intro
    notes.push_back(getKey());
    for(int i = 0; i < numNotesIntro; i++) {
        notes.push_back(' ');
    }
    for(int i = 0; i < numNotesMiddle + numNotesOutro; i++) {
        prob = distr(randGenerator);
        if(prob <= 50) {
            temp = distrNotes(randGenerator);
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
        else if(prob <= 90 && i > 0 && notes[i - 1] != ' ') {
            notes.push_back('-');
        }
        else {
            notes.push_back(' ');
        }
    }
    append = "base";
    writeToFile(notes, append);
    notes.clear();

    //Generation of Percusion
    
    //Do this so the percussion doesn't play during intro
    notes.push_back(getKey());
    for(int i = 0; i < numNotesIntro; i++) {
        notes.push_back(' ');
    }
    for(int i = 0; i < numNotesMiddle + numNotesOutro; i++) {
        prob = distr(randGenerator);
        if(prob <= 40) {
            notes.push_back('.');
        }
        else if(prob <= 60) {
            notes.push_back('_');
        }
        else {
            notes.push_back(' ');
        }
    }
    append = "percussion";
    writeToFile(notes, append);
}
