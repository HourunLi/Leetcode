#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    if(n < 3)
      return false;
    stack<int> sta;
    sta.push(0);
    int *preMinArr = new int[n]();
    int preMin = INT_MAX;
    for(int i = 0; i < n; i++) {
      preMin = min(preMin, nums[i]);
      preMinArr[i] = preMin;
      while(!sta.empty() && nums[i] >= nums[sta.top()]) {
        sta.pop();
      }
      if(!sta.empty() && sta.top() && preMinArr[sta.top()-1] < nums[i]) {
        return true;
      }
      sta.push(i);
    }
    return false;
  }
};