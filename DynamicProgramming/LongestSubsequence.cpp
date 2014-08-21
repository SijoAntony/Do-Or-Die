#include <iostream>
#include <string>
#include <vector>

using namespace std;

int longestSubsequence(string s1, string s2) {
    int n1 = s1.length(), n2 = s2.length();
    vector<vector<int> > L(n1 + 1, vector<int>(n2 + 1, 0));
    
    for (int i = 0; i <= n1; i++) {
        for(int j = 0; j <= n2; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else {
                L[i][j] = max(L[i-1][j], L[i][j-1]);
                if (s1[i] == s2[j])
                    L[i][j] = max(L[i][j], L[i-1][j-1] + 1);
            }    
        }
    }
    
    return L[n1][n2];    
}

int main()
{
    string s1 = "abcd";
    string s2 = "abcd";
    cout<<"Length of subsequence : "<<longestSubsequence(s1, s2);
    return 0;
}

