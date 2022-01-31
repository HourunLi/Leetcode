#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int *left = (int*)malloc(sizeof(int) * n);
    int *right = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++) {
      right[i] = n;
    }

    stack<int> sta;
    for(int i = 0; i < n ; i++) {
      while(!sta.empty() && heights[sta.top()] >= heights[i]) {
        right[sta.top()] = i;
        sta.pop();
      }
      left[i] = sta.empty() ? -1 : sta.top();
      sta.push(i);
    }

    int ret = -1;
    for(int i = 0; i < n; i++) {
      ret = max(ret, (right[i] - left[i] - 1) * heights[i]);
    }

    return ret;
  }
};