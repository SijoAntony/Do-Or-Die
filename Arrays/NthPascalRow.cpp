/**
*   Print the nth pascal row using recursion
**/

#include <iostream>
#include <vector>

using namespace std;

void generate(vector<int> &row, int n, int index) {
    if (index == n)
        return;
        
    row[0] = 1;
    for (int i = index - 1; i > 0; i--)
        row[i] = row[i] + row[i - 1];
    row[index] = 1;
    
    generate(row, n, index + 1);
}

vector<int> generate(int n) {
    vector<int> row(n);
    generate(row, n, 0);
    return row;    
}

int main()
{   
    vector<int> row = generate(5);
    for (int j = 0; j < row.size(); j++)
        cout<<row[j]<<" ";
    return 0;
}
