#include <iostream>
#include <string>
#include <list>

#define ALPHABET_SIZE 26
#define CHAR2INT(c) (c - 'a')

using namespace std;

struct SuffixTrieNode {
    SuffixTrieNode *children[ALPHABET_SIZE];
    list<int> suffixIndices;
};

class SuffixTrie {
public:
    
    SuffixTrie(string text) : root(new SuffixTrieNode()) {
        for (int i = 0; i < text.length(); i++)
            addSuffix(text.substr(i), i);
    }
    
    void addSuffix(string s, int index) {
        SuffixTrieNode *crawler = root;

        for (int i = 0; i < s.length(); i++) {
            if (!crawler->children[CHAR2INT(s[i])]) {
                crawler->children[CHAR2INT(s[i])] = new SuffixTrieNode();
            }
            crawler->suffixIndices.push_back(index);
            crawler = crawler->children[CHAR2INT(s[i])];
        }
    }
    
    void search(string p) {
        SuffixTrieNode *crawler = root;
        for (int i = 0; i < p.length(); i++) {
            if (!crawler->children[CHAR2INT(p[i])]) {
                cout<<"Not found!"<<endl;
                return;
            }
            crawler->suffixIndices.push_front(i);
            crawler = crawler->children[CHAR2INT(p[i])];
        }
        list<int> l = crawler->suffixIndices;
        list<int>::iterator it;
        for (it = l.begin(); it != l.end(); ++it)
            cout<<*it<<" ";
        cout<<endl;
    }
    
private:
    SuffixTrieNode *root;
};


int main()
{
    SuffixTrie S("geeksforgeeks.org");
    
    cout << "Search for 'ee'" << endl;
    S.search("ee");
 
    cout << "\nSearch for 'geek'" << endl;
    S.search("geek");
 
    cout << "\nSearch for 'quiz'" << endl;
    S.search("quiz");
 
    cout << "\nSearch for 'forgeeks'" << endl;
    S.search("forgeeks");
    return 0;
}
