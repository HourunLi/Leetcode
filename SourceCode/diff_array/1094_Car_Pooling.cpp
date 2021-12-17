#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    int diff[1005];
    memset(diff, 0, sizeof(diff));
    for(auto &i : trips) {
      int num = i[0], begin = i[1], end = i[2];
      diff[begin] += num;
      diff[end] -= num;
    }
    if(diff[0] > capacity) {
      return false;
    }
    for(int i = 1; i < 1005; i++) {
      diff[i] += diff[i-1];
      if(diff[i] > capacity) {
        return false;
      }
    }
    return true;
  }
};