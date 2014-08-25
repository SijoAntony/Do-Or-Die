#include <iostream>
#include <vector>

using namespace std;

struct Movie {
    int start;
    int end;
    
    Movie(int _start, int _end)
        : start(_start)
        , end(_end){
    }
    
};

bool compare(Movie m1, Movie m2) {
    return m1.start < m2.start;
}

int maxMovies(vector<Movie>& m)
{
    int size = m.size();
    if (size <= 1) return size;
    
    vector<int> maxs(size, 1);
    int maxNum = 1;
    
    sort(m.begin(), m.end(), compare);
    
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (m[i].start >= m[j].end)
                maxs[i] = max(maxs[i], maxs[j] + 1);
        }
        maxNum = max(maxNum, maxs[i]);
    }
    
    return maxNum;
}
    
int main()
{   
    vector<Movie> m;
    m.push_back(Movie(7, 9));
    m.push_back(Movie(0, 10));
    m.push_back(Movie(4, 5));
    m.push_back(Movie(8, 9));
    m.push_back(Movie(4, 10));
    m.push_back(Movie(5, 7));
    
    cout<<"Max no of movies :"<<maxMovies(m)<<endl;
    
    return 0;
}
