/**
*   Design an algorithm and write code to remove the duplicate characters in a string without 
*   using any additional buffer. 
*
*   NOTE: One or two additional variables are fine. An extra copy of the array is not.
*
**/

#include <iostream>
#include <string>

using namespace std;

void removeDuplicates(string& str) 
{
    int length = str.length();
    int tail = 1;
    
    for(int i = 1; i < length; i++) {
        int j;
        for (j = 0; j < tail; j++)
            if(str[j] == str[i])
                break;
        if (j == tail) {
            str[tail++] = str[i];
        }
    }
    str.resize(tail);
}

int main()
{
    string tests[6] = {"abcd", "aaaaa", "aaabbb", "ababab", "", "a"};
    for(int i = 0; i < 6; i++) {
        cout<<tests[i];
        removeDuplicates(tests[i]);
        cout<<" : "<<tests[i]<<endl;
    }
    
    return 0;    
}
