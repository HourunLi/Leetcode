#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size(), ret = n + 1;
    long long *p = (long long*)malloc((n+1) * sizeof(long long));
    p[0] = 0;
    for(int i = 0; i < n; ++i) {
      p[i+1] = nums[i] + p[i];
    }

    deque<int> q;
    for(int i = 0; i < n+1; i++) {
      long long t = p[i];
      while(!q.empty() && t <= p[q.back()]) {
        q.pop_back();
      }

      while(!q.empty() && t- p[q.front()] >= k) {
        ret = min(ret, i - q.front());
        q.pop_front();
      }
      q.push_back(i);
    }
    return ret < n + 1 ? ret: -1;
  }
};