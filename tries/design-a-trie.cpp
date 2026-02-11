using namespace std;
#include <iostream>
#include <string>
#include <map>

struct TrieNode {
    char value;
    map<char, TrieNode*> children;
    boolean isWord;
    TrieNode(char c, bool isWord): value(c), children({}), isWord(isWord) {}
};

class Trie {
    private:
        TrieNode* root;
    public:
        TrieNode() {
            root = TrieNode('-');
        }
        
        insert(string word) {
            TrieNode* curr = root;
            for (int i = 0; i < word.size(); i++) {
                char c = word[i];
                bool found = false;
                for(TrieNode* node : curr->children) {
                    if(node->value == c) {
                        curr = node;
                        found = true;
                        break;
                    }
                }
                if(!found) {
                    curr->children.insert(c, new TrieNode(c));
                }
            }
        }
        
    // TODO
}


int main()
{
    // TODO

    return 0;
}