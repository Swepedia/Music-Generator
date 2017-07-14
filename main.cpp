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
            cin >> name;
            generator.setName(name);
            break;
            }
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            displayMainMenu();
            break;
    }
}
