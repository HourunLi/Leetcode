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
    int size =s.size();
    int flag = false;
    int begin = minJump, end = maxJump;
    if(size==1) 
      return true;
    if(s[size-1] != '0') 
      return false;

    while(begin < size) {
      if(end >= size-1)
        return true;
      flag = false;
      for(int pos = begin; pos <= end; ++pos) {
        if(s[pos] == '0') {
          begin = pos;
          end = pos + maxJump;
          flag = true;
          break;
        }
      }
      if(!flag) {
        return false;
      }
    }
    return false;
  }
};