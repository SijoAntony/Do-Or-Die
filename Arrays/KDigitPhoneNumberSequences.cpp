#include <iostream>
#include <vector>

#include "ArrayUtils.h"

using namespace std;

int phonedigits[][3] = {
                            {1,  2,  3},
                            {4,  5,  6},
                            {7,  8,  9},
                            {-1, 0, -1}
                         };


void kDigitSequence(int startx, int starty, int maxx, int maxy, int k, vector<int>& current, vector<vector<int> >& results) {
    if (k == 0) {
        return;
    }

    if (startx < maxx && starty < maxy && phonedigits[startx][starty] != -1) {
        current.push_back(phonedigits[startx][starty]);
        if (k - 1 == 0)
            results.push_back(current);
        else {            
            kDigitSequence(startx, starty + 1, maxx, maxy, k - 1, current, results);
            kDigitSequence(startx+1, starty, maxx, maxy, k - 1, current, results);
        }
        current.pop_back();
    }
}

void printDigitSequences()
{
    vector<int> current;
    vector<vector<int> > sequences; 
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            kDigitSequence(i, j, 3, 3, 5, current, sequences);
    
    for (int i = 0; i < sequences.size(); i++) {
        printArray(sequences[i]);
    }
}

int main()
{
    printDigitSequences();
    return 0;    
}
