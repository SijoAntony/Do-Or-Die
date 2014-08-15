#include <iostream>

using namespace std;

struct TSTNode {
    TSTNode(char c) 
        : data(c)
        , left(0)
        , equal(0)
        , right(0) {
        
    }

    char data;
    int value;
    TSTNode *left;
    TSTNode *equal;
    TSTNode *right;
};


class TernarySearchTree {
public:
    TernarySearchTree() : root(new TSTNode('l')){}
    ~TernarySearchTree(){
       delete root; 
    }
    
    void insert(string str, int value) {
        TSTNode *crawler = root;
        
        for (int i = 0; i < str.length(); i++) {
            if (str[i] < crawler->data) {
                if (!crawler->left)
                    crawler->left = new TSTNode(str[i]);
                crawler = crawler->left;
               
            }
            else if (str[i] > crawler->data) {
                if (!crawler->right)
                    crawler->right = new TSTNode(str[i]);
                crawler = crawler->right;
            }
            else {
                if (!crawler->equal)
                    crawler->equal = new TSTNode(str[i]);
                crawler = crawler->equal;
            }
        }
        
        crawler->value = value;
    }

    int search(string str) {
        TSTNode *crawler = root;
        
        for (int i = 0; i < str.length(); i++) {
            if (str[i] < crawler->data) {
                if (!crawler->left)
                    return 0;
                crawler = crawler->left;
               
            }
            else if (str[i] > crawler->data) {
                if (!crawler->right)
                    return 0;
                crawler = crawler->right;
            }
            else {
                if (!crawler->equal)
                    return 0;
                crawler = crawler->equal;
            }
        }
        
        return crawler->value;        
    }

private:
    TSTNode *root;
};

int main()
{
    TernarySearchTree tst;
    
    tst.insert("trie", 1);
    tst.insert("there", 2);
    tst.insert("answer", 3);
    tst.insert("any", 4);
    tst.insert("bye", 5);
    
    cout<<tst.search("trie")<<endl;
    cout<<tst.search("ther")<<endl;
    cout<<tst.search("answer")<<endl;
    cout<<tst.search("any")<<endl;    
    
    return 0;
}
