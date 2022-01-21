#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int *visited;
  int ret= 1;
public:
  int dfs(vector<int>& arr, int pos, const int &d, const int &size) {
    if(visited[pos] != -1) {
      return visited[pos];
    }
    int ret = 1, height = arr[pos];
    //right
    for(int i = 1; i <= d; i ++) {
      if(pos+i >=size) break;
      if(arr[pos+i] >= height) break;
      ret = max(ret, dfs(arr, pos+i, d, size)+1);
    }
    //left 
    for(int i = 1; i <= d; i ++) {
      if(pos - i < 0) break;
      if(arr[pos - i] >= height) break;
      ret = max(ret, dfs(arr, pos-i, d, size)+1);
    }
    visited[pos] = ret;
    return ret;
  }
  int maxJumps(vector<int>& arr, int d) {
    int size = arr.size();
    visited = (int*) malloc(size * sizeof(int));
    memset(visited, -1, sizeof(int)*size);
    for(int i = 0; i < size; i++) {
      if(visited[i] != -1) {
        ret = max(ret, visited[i]);
        continue;
      }
      visited[i] = dfs(arr, i, d, size);
      ret = max(ret, visited[i]);
    }
    return ret;
  }
};