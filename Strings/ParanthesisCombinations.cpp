/**
*   Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*
*   For example, given n = 3, a solution set is:
*
*   "((()))", "(()())", "(())()", "()(())", "()()()"
*
**/

#include <iostream>
#include <string>

using namespace std;

void print(int open, int close, string s)
{
    if (open == 0 && close == 0) {
        cout<<s<<" ";
        return;
    }
    
    if (open > 0)
        print(open - 1, close + 1, s + "(");

    if (close > 0)
        print(open, close - 1, s + ")");
    
}

int main()
{
    
    print(3, 0, "");
    return 0;    
}
