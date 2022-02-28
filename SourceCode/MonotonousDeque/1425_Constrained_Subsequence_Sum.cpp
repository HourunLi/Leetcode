#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int constrainedSubsetSum(vector<int>& nums, int k) {
    int n = nums.size();
    int* p = new int[n];
    int ret = nums[0];
    p[0] = nums[0];
    deque<int> q;
    q.push_back(0);
    for(int i = 1; i < n; i++) {
      while(!q.empty() && q.front() < i-k) {
        q.pop_front();
      }
      p[i] = max(nums[i], nums[i] + p[q.front()]);
      while(!q.empty() && p[q.back()] <= p[i]) {
        q.pop_back();
      }
      q.push_back(i);
      ret = max(ret, p[i]);
    }
    return ret;
  }
};