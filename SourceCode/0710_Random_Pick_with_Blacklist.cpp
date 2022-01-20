#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
  int N;
  int pos_;
  unordered_map<int, int> mmap;
public:
  Solution(int n, vector<int>& blacklist) {
    srand(0);
    sort(blacklist.begin(), blacklist.end());
    int size = blacklist.size();
    N = n - size;
    pos_ = size-1;
    if(N > RAND_MAX) {
      cout << "WARNING: Solution\n";
    }
    int white = n;
    for(auto i: blacklist) {
      if(i >= N) { 
        break;
      }
      white = getNext(white, blacklist);
      mmap[i] = white;
    }
  }
  
  int getNext(int pos, vector<int>& blacklist) {
    pos--;
    while(true) {
      if(pos > blacklist[pos_]) {
        return pos;
      }else if(pos == blacklist[pos_]) {
        pos--;
        pos_--;
      }else{
        cout << "WARNING\n";
      }
    }
    return -1;
  }
  int pick() {
    int pos = rand() % N;
    if(mmap.find(pos) != mmap.end()) {
      return mmap[pos];
    }
    return pos;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */