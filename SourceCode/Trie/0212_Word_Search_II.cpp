#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
  string word;
  TrieNode *children[26];
  int cnt; // the number of children

  TrieNode () {
    word = "";
    memset(children, 0, 26 * sizeof(TrieNode*));
    cnt = 0;
  }
};

class Trie {
public:
  TrieNode *root;
  Trie() {
    root = new TrieNode();
  }
  void insert(string word) {
    TrieNode *ptr = root;
    for(auto &i : word) {
      if(ptr->children[i-'a'] == nullptr) {
        ptr->children[i-'a'] = new TrieNode();
        ptr->cnt++;
      }
      ptr = ptr->children[i-'a']; 
    }
    ptr->word = word;
    return;
  }
};


class Solution {
private:
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  int n, m;
public:
  void dfs(int x, int y, vector<vector<char>>& board, TrieNode *root, unordered_set<string> &res) {
    char ch = board[x][y];
    if(root == nullptr || root->children[ch-'a'] == nullptr) {
      return;
    }
    TrieNode *next = root->children[ch-'a'];
    if(next->word.size() > 0) {
      // cout << next->word << endl;
      res.insert(next->word);
    }

    board[x][y] = '#';
    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == '#') {
        continue;
      }
      dfs(nx, ny, board, next, res);
    }
    board[x][y] = ch;
    if(next->cnt == 0) {
      delete next;
      root->children[ch-'a'] = nullptr;
      root->cnt--;
    }
    return;
  }

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie *trie = new Trie();
    unordered_set<string> res;
    vector<string> ret;

    for(string word: words) {
      trie->insert(word);
    }

    n = board.size(), m = board[0].size();
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        dfs(i, j, board, trie->root, res);
      }
    }

    for(string word: res) {
      ret.push_back(word);
    }
    return ret;
  }
};


// another tricky method
#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
  string word;
  TrieNode *children[26];
  int cnt; // the number of children

  TrieNode () {
    word = "";
    memset(children, 0, 26 * sizeof(TrieNode*));
    cnt = 0;
  }
};

class Trie {
public:
  TrieNode *root;
  Trie() {
    root = new TrieNode();
  }
  void insert(string word) {
    TrieNode *ptr = root;
    for(auto &i : word) {
      if(ptr->children[i-'a'] == nullptr) {
        ptr->children[i-'a'] = new TrieNode();
        ptr->cnt++;
      }
      ptr = ptr->children[i-'a']; 
    }
    ptr->word = word;
    return;
  }
};


class Solution {
private:
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  int n, m;
public:
  void dfs(int x, int y, vector<vector<char>>& board, TrieNode *root, vector<string> &res) {
    char ch = board[x][y];
    if(root == nullptr || root->children[ch-'a'] == nullptr) {
      return;
    }
    TrieNode *next = root->children[ch-'a'];
    if(next->word.size() > 0) {
      // cout << next->word << endl;
      res.push_back(next->word);
      next->word = "";
    }

    board[x][y] = '#';
    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == '#') {
        continue;
      }
      dfs(nx, ny, board, next, res);
    }
    board[x][y] = ch;
    if(next->cnt == 0) {
      delete next;
      root->children[ch-'a'] = nullptr;
      root->cnt--;
    }
    return;
  }

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie *trie = new Trie();
    vector<string> ret;

    for(string word: words) {
      trie->insert(word);
    }

    n = board.size(), m = board[0].size();
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        dfs(i, j, board, trie->root, ret);
      }
    }
    return ret;
  }
};