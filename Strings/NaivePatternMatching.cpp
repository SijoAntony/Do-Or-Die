#include <iostream>
#include <string>

using namespace std;

int findPattern(string &s, string &p)
{
    for (int i = 0; i <= s.length() - p.length(); i++) {
        for (int j = 0; j < p.length(); j++) {
            if (s[i + j] != p[j])
                break;
            if (j == p.length() - 1)
                return i;
        }
    }
    
    return -1;
}

int main()
{
    string s = "bacbabababacaca";
    string p = "ababaca";
    cout<<"Position of pattern "<<p<<" in string "<<s<<" is "<<findPattern(s, p)<<endl;
       
    return 0;
}
