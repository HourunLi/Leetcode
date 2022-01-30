#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ret;
    int strLen = s.size();
    int wordsSize = words.size(), wordLen = words[0].size();
    int windowSize = wordsSize * wordLen;
    unordered_map<string, int> gmap;
    for(auto str : words) {
      gmap[str]++;
    }

    // initial position
    for(int startPos = 0; startPos < wordLen; startPos++) {
      int pos = startPos, windowPos = pos;
      unordered_map<string, int> lmap;
      while(pos + windowSize <= strLen) {
        while(windowPos - pos < windowSize) {
          string word = s.substr(windowPos, wordLen);
          lmap[word]++;
          windowPos += wordLen;
          if(gmap[word] == 0) {
            pos = windowPos;
            lmap.clear();
            break;
          }
          
          if(lmap[word] > gmap[word]) {
            while(lmap[word] > gmap[word]) {
              lmap[s.substr(pos, wordLen)]--;
              pos += wordLen;
            }
            break;
          }
        }
        if(windowPos - pos == windowSize) {
          ret.push_back(pos);
          lmap[s.substr(pos, wordLen)]--;
          pos += wordLen;
        }
      }
      lmap.clear();
    }
    return ret;
  }
};