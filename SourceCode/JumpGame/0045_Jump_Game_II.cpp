#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int jump(vector<int>& nums) {
    int size = nums.size();
    int pos = 0, maxRange = 0, range = 0, num = 0;
    while(pos < size-1) {
      maxRange = max(nums[pos]+pos, maxRange);
      if(pos >= range) {
        num++;
        range = maxRange;
      }
      pos++;
    }
    return num;
  }
};