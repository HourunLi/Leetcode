#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();
    int *p = (int *)calloc(2*n, sizeof(int));
    p[0] = nums[0];
    for(int i = 1; i < 2*n; i++) {
      p[i] = p[i-1] + nums[i%n];
    }
    int ret = INT_MIN;
    deque<int> q;
    for(int i = 0; i < 2*n; i++) {
      while(!q.empty() && q.front() < i - n) {
        q.pop_front();
      }
      ret = max(ret, q.empty() ? p[i] : p[i]-p[q.front()]);

      while(!q.empty() && p[i] <= p[q.back()]) {
        q.pop_back();
      }
      q.push_back(i);
    }
    return ret;
  }
};