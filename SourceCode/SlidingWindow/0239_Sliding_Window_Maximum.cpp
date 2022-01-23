#include<bits/stdc++.h>
using namespace std;

// 优先队列
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<pair<int, int> > q;
    for(int i = 0; i < k ; i++) 
      q.emplace(nums[i], i);
    vector<int> ans{q.top().first};
    for(int i = k; i < n; i++) {
      q.emplace(nums[i], i);
      while(q.top().second <= i-k)
        q.pop(); 
      ans.push_back(q.top().first);
    }
    return ans;
  }
};

//单调栈
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ret;
    deque<int> q;
    for(int i = 0; i < k; i++) {
      while(!q.empty() && nums[i] > nums[q.back()]) {
        q.pop_back();
      }
      q.push_back(i);
    }
    ret.push_back(nums[q.front()]);
    for(int i = 0; i < n-k; i++) {
      if(i >= q.front()) q.pop_front();
      while(!q.empty() && nums[i+k] > nums[q.back()]) {
        q.pop_back();
      }
      q.push_back(i+k);          
      ret.push_back(nums[q.front()]);
    }
    return ret;
  }
};