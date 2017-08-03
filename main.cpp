#include<iostream>
#include"Generator.h"
#include<limits>

int x;
Generator generator;

int check();
void displayMainMenu();
void displayGenerateMenu();
void displayPlayMenu();

void chooseGenerateMenu();
void choosePlayMenu();

int main() {
    displayMainMenu();
    return 0;
}

int check(int lower, int upper) {
    int temp;
    cout << "Choose an option: ";
    cin >> temp;
    while(cin.fail() || temp > upper || temp < lower) {
        cout << "Invalid Option. Try again: ";
        cin.clear();
        cin.ignore();
        cin >> temp;
    }
    return temp;
}

//If you don't care about the length but want the other checks done use -1 as arg
string check(int maxStringLength) {
    string temp;
    bool inputFailed; 
    
    //It's a do-while loop because I need to flush the cin buffer before doing anything
    do {
        cin.clear();
        cin.ignore();
        getline(cin, temp);
        inputFailed = false;
        if(maxStringLength != -1) {
            if(temp.length() > maxStringLength) {
                cout << "Too long! It should be no longer than " << maxStringLength << endl;
                inputFailed = true;
            }
        }
        if(temp.empty()) {
            cout << "Input cannot be blank.\n";
            inputFailed = true;
        }
        if(temp.find("/") != string::npos && temp.find("\\") != string::npos) {
            cout << "Cannot use '/' or '\\'\n";
            inputFailed = true;
        }
    } while(inputFailed);
    return temp;
}

void displayMainMenu() {
    bool go = true;
    while(go) {
        cout << "\n++++++++++++++++++++\n";
        cout << "| Welcome to the   |\n";
        cout << "| Music Generator! |\n";
        cout << "++++++++++++++++++++\n\n\n";
        cout << "\t1) Generate Song\n";
        cout << "\t2) Play Song\n";
        cout << "\t3) Quit\n\n";
        x = check(1, 3);

        switch(x) {
            case 1:
                displayGenerateMenu();
                break;
            case 2:
                displayPlayMenu();
                break;
            case 3:
                go = false;
                break;
        }
    }
}

void displayGenerateMenu() {
    bool go = true;
    while(go) {
        cout << "++++++++++++++++++++\n\n";
        cout << "\t1) Name\n";
        cout << "\t2) Length of Sections\n";
        cout << "\t3) BPM\n";
        cout << "\t4) # of Melody Parts\n";
        cout << "\t5) Key\n";
        cout << "\t6) Info\n";
        cout << "\t7) Generate\n";
        cout << "\t8) Cancel\n";
        x = check(1, 8);

        switch(x) {
            case 1:
                {
                    cout << "\nCurrent name is: " << generator.getName() << endl;
                    cout << "Input the name of the song:\n";

                    generator.setName(check(-1));
                    break;
                }
            case 2:
                {
                    string temp;
                    cout << "\nDetermine the length of each section of the song.\n";
                    cout << "The sections are as follows:\n";
                    cout << "\tIntro = '*'\n";
                    cout << "\tMiddle = '+'\n";
                    cout << "\tOutro = '.'\n\n";
                    cout << "Current sequence is: [" << generator.getSequence() << "]\n";
                    cout << "Input the corresponding symbol that goes with each section:\n";
                    cout << "(limit 10, order doesn't matter)\n";

                    generator.setSequence(check(10));
                    break;
                }
            case 3:
                {
                    cout << "\nCurrent BPM is: " << generator.getBPM() << endl;
                    cout << "Enter the desired tempo in beats per minute (limit 1-400):\n";

                    generator.setBPM(check(1, 400));
                    break;
                }
            case 4:
                {
                    cout << "\nCurrent # of melodies is: " << generator.getNumMelodies() << endl;
                    cout << "Enter the desired number of melody parts\n";
                    cout << "WARNING -- There is no current implementation of\n";
                    cout << "           chord generation. This means that the more\n";
                    cout << "           parts you add, the worse it will sound.\n";
                    cout << "           I'm setting the current limit to 20 parts.\n";

                    generator.setNumMelodies(check(1, 20));
                    break;
                }
            case 5:
                {
                    cout << "\nCurrent key is: " << (generator.getKey() + 1) << endl;
                    cout << "Enter the number corresponding to the desired key.\n";
                    cout << "--Major--\n";
                    cout << "\tC  - 1\tB - 8\n";
                    cout << "\tF  - 2\tE - 9\n";
                    cout << "\tBb - 3\tA - 10\n";
                    cout << "\tEb - 4\tD - 11\n";
                    cout << "\tAb - 5\tG - 12\n";
                    cout << "\tDb - 6\t\n";
                    cout << "\tGb - 7\t\n\n";
                    cout << "--Harmonic Minor--\n";
                    cout << "\tA  - 13\tG# - 20\n";
                    cout << "\tD  - 14\tC# - 21\n";
                    cout << "\tG  - 15\tF# - 22\n";
                    cout << "\tC  - 16\tB  - 23\n";
                    cout << "\tF  - 17\tE  - 24\n";
                    cout << "\tBb  - 18\t\n";
                    cout << "\tEb - 19\t\n\n";

                    //I subtract 1 so I don't have to deal with off-by-one
                    generator.setKey(check(1, 24) - 1);
                    break;
                }
            case 6:
                {
                    cout << "\nSong Info:\n";
                    cout << "Name:---------------" << generator.getName() << endl;
                    cout << "Sequence:-----------" << generator.getSequence() << endl;
                    cout << "BPM:----------------" << generator.getBPM() << endl;
                    cout << "# of Melodies:------" << generator.getNumMelodies() << endl;
                    cout << "Key:----------------" << generator.getKey() << endl;
                    break;
                }
            case 7:
                {
                    cout << "\nGenerating song: " << generator.getName() << endl;
                    generator.generate();
                    cout << "Generation complete!\n";
                    go = false;
                    break;
                }
            case 8:
                go = false;
                break;
        }
    }
}

void displayPlayMenu() {
}
