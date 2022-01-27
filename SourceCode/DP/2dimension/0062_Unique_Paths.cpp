#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    int *ret = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
      ret[i] = 1;
    }
    for(int t = 1; t < m; t++) {
      for(int i = 1; i < n; i++) {
        ret[i] += ret[i-1];
      }
    }
    return ret[n-1];
  }
};