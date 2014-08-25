#include <iostream>
#include <vector>

using namespace std;

struct Member {
    int s;
    int b;
    
    Member(int _s, int _b) 
        : s(_s)
        , b(_b) {
    }    
};

bool compare(Member& m1, Member& m2) {
    return m1.s < m2.s && m1.b < m2.b;
}

int maxPeople(vector<Member>& people)
{
    int maxN = 1;
    vector<int> maxP(people.size(), 1);
    
    for (int i = 1; i < people.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (compare(people[j], people[i]))
                maxP[i] = max(maxP[i], maxP[j] + 1);
        }
        maxN = max(maxN, maxP[i]);
    }
    
    return maxN;
}

int ceilIndex(vector<Member> &v, int low, int high, Member& key)
{
    while(high - low > 1) {
        int mid = low + (high - low) / 2;
        compare(key, v[mid]) ? high : low = mid;
    }
    return high;
}

int maxPeopleEx(vector<Member>& people)
{
    int maxN = 1;
    vector<Member> maxP(people.size(), Member(0, 0));
    
    maxP[0] = people[0];
    
    for (int i = 1; i < people.size(); i++) {
        if (compare(people[i], maxP[0]))
            maxP[0] = people[i];
        else if(compare(maxP[maxN - 1], people[i])) {
            maxP[maxN++] = people[i];
        }
        else {
            int index = ceilIndex(maxP, 0, maxN - 1, people[i]);
            if (compare(maxP[index], people[i]))
                maxP[index] = people[i];
        }
    }    
    return maxN;
}

int main()
{
    vector<Member> people;
    
    people.push_back(Member(1, 1));
    people.push_back(Member(1, 2));
    people.push_back(Member(2, 1));
    people.push_back(Member(2, 2));
    
    cout<<"Max no of people to be invited: "<<maxPeopleEx(people)<<endl;
    return 0;
}
