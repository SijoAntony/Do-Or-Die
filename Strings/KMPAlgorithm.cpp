#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> buildPrefixTable(string &s)
{
    vector<int> prefixTable(s.length(), 0);
    for(int i = 1, j = 0; i < s.length();) {
        if (s[i] == s[j]) {
            prefixTable[i] = j + 1;
            i++, j++;
        }
        else if (j > 0)
            j = prefixTable[j- 1];
        else {
            prefixTable[i] = 0;
            i++;
        }
    }
    return prefixTable;
}
    
int findPattern(string &s, string &p)
{
    vector<int> T = buildPrefixTable(p);
    int n = s.length(), m = p.length();

    for (int i = 0, j = 0; i < n;) {
        if (s[i] == p[j]) {
            if (j == m - 1)
                return i - j;
            i++, j++;
        }
        else if (j > 0)
            j = T[j - 1];
        else
            i++;
    }
    
    return -1;
}

int main()
{
    string s = "bacbabababacaca";
    string p = "ababacaaa";
    cout<<"Position of pattern "<<p<<" in string "<<s<<" is "<<findPattern(s, p)<<endl;
    return 0;
}
