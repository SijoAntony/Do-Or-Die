/**
* Given sorted array in decreasing order. Find first occurrence of given key.
* For example given an array as { 8, 7, 6, 6, 2, 2 ,2 , 2, 2 , 1 }
* 
* First occurence of 2 is 4
* First occurence of 7 is 1 etc.
*
* 
**/

#include <iostream>

using namespace std;

class Solution {
public:
    int getFirstOccurence(int A[], int size, int key) {
        int low = 0;
        int high = size - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            
            if (A[mid] == key) {
                if(mid > 0 && A [mid - 1] == key)
                    high = mid - 1;
                else
                    return mid;
            } 
            else if (A[mid] > key)
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return -1;
    }
};

int main()
{
    int A[] = {8, 7, 6, 6, 2, 2 ,2 , 2, 2 , 1};
    int size = sizeof(A) / sizeof (int);
    int key = 2;
    
    Solution sl;
    cout<<"First Occurence of "<<key<<" is "<<sl.getFirstOccurence(A, size, key)<<endl;
    
    return 0;
}
