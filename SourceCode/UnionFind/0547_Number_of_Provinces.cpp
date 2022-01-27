#include<bits/stdc++.h>
using namespace std;
/*DFS*/
class Solution {
public:
  void dfs(vector<vector<int>>& map, vector<int> &vis, int n, int from) {
    vis[from] = 1;
    for(int to = 0; to < n; to++) {
      if(map[from][to] && !vis[to]) {
        dfs(map, vis, n, to);
      }
    }
    return;
  }
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size(), ans = 0;
    vector<int> vis(n, 0);
    for(int i = 0; i < n; i++) {
      if(vis[i]) continue;
      ans++;
      dfs(isConnected, vis, n, i);
    }
    return ans;
  }
};

/*BFS*/
class Solution {
public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size(), ans = 0;
    vector<int> vis(n, 0);
    queue<int> q;
    for(int i = 0; i < n; i++) {
      if(vis[i]) continue;
      ans++;
      q.push(i);
      while(!q.empty()) {
        int from = q.front();
        q.pop();
        for(int to = 0; to < n; to++) {
          if(isConnected[from][to] && !vis[to]) {
            vis[to] = 1;
            q.push(to);
          }
        }
      }
    }
    return ans;
  }
};

/*Union Find*/
class Solution {
public:
  int Find(int index, vector<int> &parent) {
    if(parent[index] == index) return index;
    parent[index] = Find(parent[index], parent);
    return parent[index];
  }
  void Union(int i, int j, vector<int> &parent) {
    parent[Find(i, parent)] = Find(j, parent);
  }
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size(), ans = 0;
    vector<int> parent(n);
    for(int i = 0; i < n; i++) 
      parent[i] = i;
    
    for(int i = 0; i < n; i++) 
      for(int j = 0; j < n; j++) 
        if(isConnected[i][j] && parent[i] != parent[j]) 
          Union(i, j, parent);

    for(int i = 0; i < n; i++) 
      if(parent[i] == i) 
        ans++;
    return ans;
  }
};