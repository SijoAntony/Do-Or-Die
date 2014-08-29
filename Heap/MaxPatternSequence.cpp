#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
typedef pair<string, int> LookUp;
typedef map<string, int> PatternMap;
const int size = 4;


class Comparator {
public:
    bool operator()(LookUp &l1, LookUp &l2)
    {
        return l1.second > l2.second;
    }
};

void printMaxKSequences(vector<string> &v, int k)
{
    PatternMap patternMap;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j <= v[i].length() - k; j++)
            patternMap[v[i].substr(j, k)]++;
    }    
    
    priority_queue<LookUp, vector<LookUp>, Comparator> q;
    for (PatternMap::iterator it = patternMap.begin(); it != patternMap.end(); ++it) {
        q.push(*it);
        if (q.size() > size)
            q.pop();
    }

    while (!q.empty()) {
        LookUp l = q.top();
        q.pop();
        cout<<l.first<<" "<<l.second<<endl;    
    }
}

int main()
{
    string A[] = {"xyzabcdef", "zabcd", "yzabcd", "abcd"};
    vector<string> v(A, A + sizeof(A)/sizeof(string));
    
    printMaxKSequences(v, 3);
    
    return 0;
}
