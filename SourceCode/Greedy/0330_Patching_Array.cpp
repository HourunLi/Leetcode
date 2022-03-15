#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minPatches(vector<int>& nums, int n) {
    int size = nums.size();
    long long cur = 0;
    int ret = 0;
    for(int i = 0; i < size;) {
      if(cur+1 >= nums[i]) {
        cur += nums[i];
        i++;
      }else{
        ret++;
        // cout << ret << endl;
        cur = cur*2 + 1;
      }
      if(cur >= n) 
        return ret;
    }

    while(cur < n) {
      ret++;
      // cout << ret << endl;
      cur = cur*2 + 1;
    }
    return ret;
  }
};