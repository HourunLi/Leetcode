#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
  int ch;
  map<int, TrieNode *> child;
  TrieNode() {
    ch = 0;
  }
  TrieNode(int c) {
    ch = c;
  }
};

class Trie {
  TrieNode *trieRoot;
public:
  Trie() {
    trieRoot = new TrieNode();
  }
  TrieNode* getRoot() {
    return trieRoot;
  }
};

bool insert(int ch, TrieNode *ptr) {
  if(ptr->child.find(ch) == ptr->child.end()) {
    ptr->child[ch] = new TrieNode(ch);
    return true;
  }
  return false;
}

TrieNode* getChild(int ch, TrieNode *ptr) {
  if(ptr->child.find(ch) == ptr->child.end()) {
    return nullptr;
  }
  return ptr->child[ch];
}


class Solution {
public:
  int countDistinct(vector<int>& nums, int k, int p) {
    int n = nums.size(), ret = 0;
    Trie *root = new Trie();
    for(int i = 0; i < n; i++) {
      TrieNode *ptr = root->getRoot();
      int cnt = 0;
      for(int j = i; j < n; j++) {
        if(nums[j] % p == 0)  {
          if(++cnt > k) {
            break;
          }
        }
        if(insert(nums[j], ptr)) {
          ++ret;
        }
        ptr = getChild(nums[j], ptr);
      }
    }
    return ret;
  }
};