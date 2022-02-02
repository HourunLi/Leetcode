#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int **map = (int**) malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) {
      map[i] = (int*)calloc(m, sizeof(int));
    }

    for(int i = 0; i < n; i++) {
      int cnt = 0;
      for(int j = 0; j < m; j++) {
        if(matrix[i][j] == '1') {
          cnt++;
        }else {
          cnt = 0;     
        }
        map[i][j] = cnt;
      }
    }

    int ret = 0;
    int *left = (int*) malloc(n * sizeof(int));
    int *right = (int*) malloc(n * sizeof(int));
    for(int j = 0; j < m; j++) {
      stack<int> sta;
      // initialize
      memset(left, -1, n * sizeof(int));
      for(int i = 0; i < n; i++) {
        right[i] = n;
      }
      // monotonous stack 
      for(int i = 0; i < n; i++) {
        while(!sta.empty() && map[sta.top()][j] > map[i][j]) {
          right[sta.top()] = i;
          sta.pop();
        }
        left[i] = sta.empty() ? -1 : sta.top();
        sta.push(i);
      }
      int ans;
      for(int i = 0; i < n; i++) {
        ans = map[i][j] * (right[i] - left[i] - 1);
        ret = max(ret, ans);
      }
    }
    return ret;
  }
};