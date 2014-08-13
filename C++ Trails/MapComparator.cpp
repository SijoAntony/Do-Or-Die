#include <iostream>
#include <set>

using namespace std;

class Comparator {
public:
    bool operator()(const int& lhs, const int& rhs) const {
        return lhs < rhs;
    }    
};


int main()
{
    set<int, Comparator> table;
    int A[] = {5, 2, 3, 1, 6, 8};
    int size = sizeof(A) / sizeof(int);

    for (int i = 0; i < size; i++)
        table.insert(A[i]);
        
    for (set<int>::iterator it = table.begin(); it != table.end(); ++it)
        cout<<*it<<" ";
    cout<<endl;
        
    return 0;
}
