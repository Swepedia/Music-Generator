//@author: Maxwell Heeschen

#include<vector>
#include<string>

using namespace std;

class Generator
{
private:
    int numMelodies;
    int BPM;
    char key;
    string name;
    /*
     * can be anything between 1-20
     */
    
    char sequence[10];
    /*
     * How long the intro, middle, and outro are
     * intro = '*'
     * middle = '+'
     * outro = '.'
     */

    static const char SYMBOL_INTRO = '*';
    static const char SYMBOL_MIDDLE = '+';
    static const char SYMBOL_OUTRO = '.';

    void writeToFile(vector<char> notes, string append);
    /*
     * Writes the vector of notes to a file to be played back later. The name
     * of the file is the variable 'name' and then the arg 'append' is appended
     * to the end of 'name' preceeded by a '_'. Ex:
     *      'filename_melody01', 'filename_bassLine', etc.
     */

public:
    Generator();

    int getNumMelodies();
    int getBPM();
    int getKey();
    string getName();

    void setNumMelodies(int num);
    void setBPM(int beat);
    void setKey(int k);
    void setSequence(string s);
    void setName(string n);

    
    void generate();
    /*
     * The meat of the program. This is where the generation of notes happens.
     * Outputs the notes to a vector which is then printed to a file using the
     * writeToFile method.
     */
};
