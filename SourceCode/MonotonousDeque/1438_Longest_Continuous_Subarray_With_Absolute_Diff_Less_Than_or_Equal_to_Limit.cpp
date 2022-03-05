#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestSubarray(vector<int>& nums, int limit) {
    int n = nums.size();
    int l = 0, ret = 1;
    deque<int> min_q, max_q;
    for(int r = 0; r < n; r++) {
      while(!min_q.empty() && nums[r] < nums[min_q.back()]) {
        min_q.pop_back();
      }
      min_q.push_back(r);

      while(!max_q.empty() && nums[r] > nums[max_q.back()]) {
        max_q.pop_back();
      }
      max_q.push_back(r);

      while(!min_q.empty() && !max_q.empty() && nums[max_q.front()] - nums[min_q.front()] > limit) {
        l++;
        while(min_q.front() < l) {
          min_q.pop_front();
        }
        while(max_q.front() < l) {
          max_q.pop_front();
        }     
      } 
      ret = max(r -l + 1, ret);
    }
    return ret;
  }
};