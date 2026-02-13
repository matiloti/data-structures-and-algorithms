using namespace std;
#include <iostream>
#include <string>
#include <map>

struct TrieNode {
    char value;
    map<char, TrieNode*> children;
    bool isWord;
    TrieNode(char c, bool isWord): value(c), children({}), isWord(isWord) {}
};

class Trie {
    private:
        TrieNode* root;
    public:
        Trie() {
            root = new TrieNode('-', false);
        }
        
        void insert(string word) {
            TrieNode* curr = root;
            for (int i = 0; i < word.size(); i++) {
                char c = word[i];
                if(curr->children.find(c) == curr->children.end()) 
                    curr->children.insert({c, new TrieNode(c, false)});
                curr = curr->children[c];
                if(i == word.size() - 1) curr->isWord = true;
            }
        }
        
        bool search(string word) {
            TrieNode* curr = root;
            for (int i = 0; i < word.size(); i++) {
                char c = word[i];
                if(curr->children.find(c) == curr->children.end()) return false;
                curr = curr->children[c];
                if(curr->isWord && i == word.size() - 1) return curr->isWord;
            }
            return false;
        }
        
        bool hasPrefix(string prefix) {
            TrieNode* curr = root;
            for (int i = 0; i < prefix.size(); i++) {
                char c = prefix[i];
                if(curr->children.find(c) == curr->children.end()) return false;
                curr = curr->children[c];
            }
            return true;
        }
        
    // TODO
};


int main()
{
    Trie trie = Trie();
    trie.insert("top");
    trie.insert("bye");
    cout<<trie.hasPrefix("to");
    cout<<trie.search("to");
    trie.insert("to");
    cout<<trie.search("to");
    return 0;
}