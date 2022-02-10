#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    int len = s.size();
    unordered_map<string, int> memo;
    vector<string> ret;

    if (len < 10) {
      return {};
    }
    int pos = 0;
    while(pos <= len-10) {
      string sub = s.substr(pos, 10);
      if(memo[sub] == 1) {
        ret.emplace_back(sub);
      }
      memo[sub]++;
      
      pos++;
    }
    return ret;
  }
};

// optimized
class Solution {
private:
  unordered_map<char, int> bin = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
public:
  vector<string> findRepeatedDnaSequences(string s) {
    int len = s.size();
    unordered_map<int, int> memo;
    vector<string> ret;

    if (len < 10) {
      return {};
    }
    int pos = 0;
    int key = 0;
    for (pos = 0; pos < 9; ++pos) {
      key = (key << 2) | bin[s[pos]];
    }
    while(pos < len) {
      key = ((key << 2) | bin[s[pos]]) & ((1 << 20) - 1);
      if(memo[key] == 1) {
        ret.emplace_back(s.substr(pos-9, 10));
      }
      memo[key]++;
      pos++;
    }
    return ret;
  }
};
