#include <iostream>

#define CHAR2INT(c) (c - 'a')
#define ALPHABET_SIZE 26

using namespace std;

struct TrieNode {
    int value;
    TrieNode *children[ALPHABET_SIZE];
};

class Trie {
public:    
    Trie() : root(new TrieNode) {
    
    }
    void insert(string str, int value) {
        TrieNode *crawler = root;
        
        for (int i = 0; i < str.length(); i++) {
            if (!crawler->children[CHAR2INT(str[i])]) {
                crawler->children[CHAR2INT(str[i])] = new TrieNode();
            }
            crawler = crawler->children[CHAR2INT(str[i])];
        }
        
        crawler->value = value;
    }
    
    int search(string str) {
        TrieNode *crawler = root;
        
        for (int i = 0; i < str.length(); i++) {
            if (!crawler->children[CHAR2INT(str[i])])
                return 0;
            crawler = crawler->children[CHAR2INT(str[i])];
        }
        
        return crawler->value;
            
    }
    
private:
    TrieNode *root;
};

int main()
{
    Trie trie;
    
    trie.insert("trie", 1);
    trie.insert("there", 2);
    trie.insert("answer", 3);
    trie.insert("any", 4);
    trie.insert("bye", 5);
    
    cout<<trie.search("trie")<<endl;
    cout<<trie.search("ther")<<endl;
    cout<<trie.search("answer")<<endl;
    cout<<trie.search("bye")<<endl;

    return 0;
}
