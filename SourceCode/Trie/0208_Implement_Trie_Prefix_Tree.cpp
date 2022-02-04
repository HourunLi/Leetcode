#include<bits/stdc++.h>
using namespace std;

class Trie {
private:
  struct PrefixTree {
    PrefixTree *node[26];
    char c;
    bool IsWord;

    PrefixTree(char c) : c(c), IsWord(false){
      memset(node, 0, sizeof(PrefixTree *) * 26);
    }

    PrefixTree(){
      c = '\0';
      IsWord = false;
      memset(node, 0, sizeof(PrefixTree *) * 26);
    }
  };

  PrefixTree *root;
public:
    /** Initialize your data structure here. */
    Trie() {
      root = new PrefixTree();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
      PrefixTree *ptr = root;
      for(auto &i : word) {
        if((ptr->node)[i-'a'] == nullptr) {
          (ptr->node)[i-'a'] = new PrefixTree(i);
        }
        ptr = (ptr->node)[i-'a']; 
      } 
      ptr->IsWord = true;
      return;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
      PrefixTree *ptr = root;
      for(auto &i : word) {
        if((ptr->node)[i-'a'] == nullptr) return false;
        ptr = (ptr->node)[i-'a']; 
      } 
      return (ptr->IsWord);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
      PrefixTree *ptr = root;
      for(auto &i : prefix) {
        if((ptr->node)[i-'a'] == nullptr) return false;
        ptr = (ptr->node)[i-'a']; 
      } 
      return true;       
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */