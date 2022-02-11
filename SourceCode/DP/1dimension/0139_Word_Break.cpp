#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isTheSame(string &s, int pos, string& pattern) {
    int len = pattern.length();
    if(len > pos) return false;
    return s.substr(pos - len, len) == pattern;
  }
  bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size(), dicSize = wordDict.size();
    int *ret = new int[n+1]();
    ret[0] = 1;
    for(int i = 1; i <= n ; i++) {
      for(int j = 0; j < dicSize; j++) {
        if(isTheSame(s, i, wordDict[j])) {
          ret[i] |= ret[i-wordDict[j].size()];
        }
      }
    }
    return ret[n];
  }
};