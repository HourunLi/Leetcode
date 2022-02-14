#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxChunksToSorted(vector<int>& arr) {
    int n = arr.size();
    int cnt = 0, max_ = -1, ret = 0;
    for(int &item : arr) {
      max_ = max(item, max_);
      ++cnt;
      if(cnt == max_) {
        ret++;
      }
    }
    return ret;
  }
};