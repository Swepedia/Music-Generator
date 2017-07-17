//@author: Maxwell Heeschen

#include<iostream>
#include"Generator.h"

int x;
Generator generator;

int check();
void displayMainMenu();
void displayGenerateMenu();
void displayPlayMenu();

int main() {
    //int x;
      //  cin >> x;
  //  while(cin.fail() || x > 3 || x < 1) {
  //      cout << "Invalid Option. Try again:\n";
  //      cin.clear();
  //      cin.ignore(256, '\n');
  //      cin >> x;
  //  }

    displayMainMenu();

    return 0;
}

int check(int lower, int upper) {
    int temp;
    cin >> temp;
    while(cin.fail() || temp > upper || temp < lower) {
        cout << "Invalid Option. Try again:\n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> temp;
    }
    return temp;
}

void displayMainMenu() {
    cout << "\n\n\n\n\n";
    cout << "++++++++++++++++++++\n";
    cout << "+ Welcome to the   +\n";
    cout << "+ Music Generator! +\n";
    cout << "++++++++++++++++++++\n\n\n";
    cout << "\t1) Generate Song\n";
    cout << "\t2) Play Song\n";
    cout << "\t3) Quit\n\n";
    cout << "Choose an option: ";
    x = check(1, 3);

    switch(x) {
        case 1:
            displayGenerateMenu();
            break;
        case 2:
            displayPlayMenu();
            break;
        case 3:
            break;
    }
}

void displayGenerateMenu() {
    cout << "\t1) Name\n";
    cout << "\t2) Length of Sections\n";
    cout << "\t3) BPM\n";
    cout << "\t4) # of Melody Parts\n";
    cout << "\t5) Key\n";
    cout << "\t6) Generate\n";
    cout << "\t7) Cancel\n";
    x = check(1, 7);

    switch(x) {
        case 1:
            {
                string name;
                cout << "Input the name of the song:\n";

                getline(cin, name);
                generator.setName(name);
                break;
            }
        case 2:
            {
                string temp;
                cout << "Determine the length of each section of the song.\n";
                cout << "The sections are as follows:\n";
                cout << "\tIntro = '*'\n";
                cout << "\tMiddle = '+'\n";
                cout << "\tOutro = '.'\n\n";
                cout << "Input the corresponding symbol that goes with each section:\n";
                cout << "(limit 10, order doesn't matter)\n";
                cout << "]\r[";

                getline(cin, temp);
                generator.setSequence(temp);
                break;
            }
        case 3:
            {
                cout << "Enter the desired tempo in beats per minute (limit 1-400):\n";

                generator.setBPM(check(1, 400));
                break;
            }
        case 4:
            {
                cout << "Enter the desired number of melody parts\n";
                cout << "WARNING -- There is no current implementation of\n";
                cout << "           chord generation. This means that the more\n";
                cout << "           parts you add, the worse it will sound.\n";
                cout << "           I'm setting the current limit to 20 parts.\n:";

                generator.setNumMelodies(check(1, 20));
                break;
            }
        case 5:
            {
                cout << "Enter the number corresponding to the desired key.\n";
                cout << "--Major--\n";
                cout << "\tA - 1\tAb - 8\n";
                cout << "\tB - 2\tBb - 9\n";
                cout << "\tC - 3\t\n";
                cout << "\tD - 4\tDb - 10\n";
                cout << "\tE - 5\tEb - 11\n";
                cout << "\tF - 6\tF# - 12\n";
                cout << "\tG - 7\t\n\n";
                cout << "--Minor--\n";
                cout << "\tA - 13\tAb - 20\n";
                cout << "\tB - 14\tBb - 21\n";
                cout << "\tC - 15\t\n";
                cout << "\tD - 16\tDb - 22\n";
                cout << "\tE - 17\tEb - 23\n";
                cout << "\tF - 18\tF# - 24\n";
                cout << "\tG - 19\t\n\n";

                generator.setKey(check(1, 24));
                break;
            }
        case 6:
            {
                cout << "Generating song: " << generator.getName() << endl;
                generator.generate();
                cout << "Generation complete!\n";
                break;
            }
        case 7:
            displayMainMenu();
            break;
    }
}

void displayPlayMenu() {
}
