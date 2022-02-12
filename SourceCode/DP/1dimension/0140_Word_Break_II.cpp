#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
  vector<string>* memo;
  bool *vis;
public:
  bool isTheSame(string &s, int pos, int len, string& pattern) {
    if(pos < 0) return false;
    return s.substr(pos, len) == pattern;
  }
  void dfs(string &s, int pos, vector<string>& wordDict) {
    if(vis[pos]){
      return;
    }
    vis[pos] = true;
    int dicSize = wordDict.size();
    for(int i = 0; i < dicSize; ++i) {
      int len = wordDict[i].size();
      if(isTheSame(s, pos-len, len, wordDict[i])) {
        dfs(s, pos - len, wordDict);
        for(string &str : memo[pos - len]) {
          memo[pos].emplace_back(str.empty()? wordDict[i] : str + " " + wordDict[i]);
        }
      }
    }
    return;
  } 
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    memo = new vector<string>[n+1];
    vis = new bool[n+1]();
    memo[0] = {""};
    vis[0] = true;
    for(int i = 1; i <= n; i++) {
      memo[i] = {};
    }
    dfs(s, n, wordDict);
    return memo[n];
  }
};