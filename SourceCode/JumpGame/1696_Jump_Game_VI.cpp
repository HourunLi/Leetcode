#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  deque<int> q;
  void addElement(vector<int>& nums, int pos) {
    while(!q.empty() && nums[pos] > nums[q.back()]) {
      q.pop_back();
    }
    q.push_back(pos);
    return;   
  }
public:
  int maxResult(vector<int>& nums, int k) {
    int size = nums.size();
    q.push_back(0);
    /// init deque
    for(int i = 1; i < k && i < size; i++) {
      nums[i] += nums[q.front()];
      addElement(nums, i);
    }
    for(int i = k; i < size; i++) {
      nums[i] += nums[q.front()];
      if(i-k >= q.front()) q.pop_front();
      addElement(nums, i);
    }
    return nums[size-1];
  }
};