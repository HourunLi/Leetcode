#include<bits/stdc++.h>
using namespace std;
//TLE
class Solution {
private:
  bool *visited;
public:
  bool canReach(string s, int minJump, int maxJump) {
    int size =s.size();
    visited = (bool*) calloc(size, sizeof(bool));
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while(!q.empty()) {
      int top = q.front(); q.pop();
      if(top == size-1) return true;
      int begin = top + minJump;
      int end = min(top + maxJump, size-1);
      for(int i = begin; i <= end; ++i) {
        if(s[i] == '0' && visited[i] == 0) {
          visited[i] = 1;
          q.push(i);
        }
      }
    }
    return false;
  }
};

class Solution {
public:
  bool canReach(string s, int minJump, int maxJump) {
    int size = s.size();
    bool *canReach = (bool *)calloc(size, sizeof(bool));
    int *pre = (int *)calloc(size, sizeof(int));
    canReach[0] = 1;
    pre[0]=1;
    for(int i = 1; i < size; i++) {
      if(s[i] == '1') {
        pre[i] = pre[i-1];
      }else{
        int l = i - maxJump > 0 ? pre[i - maxJump-1] : 0;
        int r = i - minJump >= 0 ? pre[i - minJump] : 0;
        if(r-l) {
          canReach[i] = true;
          pre[i] = pre[i-1]+1;
        }else{
          pre[i] = pre[i-1];
        }
      }
    }
    return canReach[size-1];
  }
};
