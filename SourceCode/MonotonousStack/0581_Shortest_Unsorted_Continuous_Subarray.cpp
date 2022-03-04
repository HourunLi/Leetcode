#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int findUnsortedSubarray(vector<int>& nums) {
    stack<int> sta;
    int n = nums.size();
    int l = n, r = 0;
    for(int i = 0; i < n; i++){
      while(!sta.empty() && nums[i] < nums[sta.top()]) {
        l = min(l, sta.top());
        sta.pop();
      }
      sta.push(i);
    }
    sta = stack<int>();
    for(int i = n-1; i >=0; i--){
      while(!sta.empty() && nums[i] > nums[sta.top()]) {
        r = max(r, sta.top());
        sta.pop();
      }
      sta.push(i);
    }
    return (r-l) < 0 ? 0 : r - l + 1;
  }
};