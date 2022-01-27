#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    int *ret = (int*)malloc(n * sizeof(int));
    ret[0] = obstacleGrid[0][0] == 0? 1: 0; 
    for(int i = 1; i < n; i++) {
      if(obstacleGrid[0][i] == 1) {
        ret[i] = 0;
      }else{
        ret[i] = ret[i-1];
      }
    }
    for(int t = 1; t < m; t++) {
      for(int i = 0; i < n; i++) {
        if(obstacleGrid[t][i] == 1) {
          ret[i] = 0;
        }else if(i){
          ret[i] += ret[i-1];
        }
      }
    }
    return ret[n-1];
  }
};