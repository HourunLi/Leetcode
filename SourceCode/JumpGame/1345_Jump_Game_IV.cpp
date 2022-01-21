#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minJumps(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, list<int> > graph;
    for(int i = 0; i < n; i++) {
      int value = arr[i];
      auto iter = graph.find(value);
      if(iter == graph.end()) {
        auto ptr = new list<int>();
        ptr->push_front(i);
        graph[value] = *ptr;
      }else{
        (iter->second).push_front(i);
      }
    }
    int* visit = new int[n];
    memset(visit, -1, sizeof(int)*n);
    visit[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
      int head = q.front();
      if(head == n-1) return visit[head];
      q.pop();
      if(head >=1 && visit[head-1] == -1) {
        visit[head-1] = visit[head] + 1;
        q.push(head-1);
      }
      if(head < n-1 && visit[head+1] == -1) {
        visit[head+1] = visit[head] + 1;
        q.push(head+1);              
      }
      auto iter = graph.find(arr[head]);
      if(iter == graph.end()) continue;
      for(auto it = (iter->second).begin(); it != (iter->second).end(); it++) {
        int next = *it;
        if(visit[next] == -1){
          visit[next] = visit[head] + 1;
          q.push(next); 
        }    
      }
      graph.erase(iter);
    }
    return -1;
  }
};