#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
      return a.second < b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp)> q(cmp);

    vector<int> dots;
    for(auto &building:buildings) {
      dots.emplace_back(building[0]);
      dots.emplace_back(building[1]);
    }
    sort(dots.begin(), dots.end());

    vector<vector<int> > ret;
    int n = buildings.size(), idx = 0;
    for(auto dot : dots) {
      while(idx < n && buildings[idx][0] <= dot) {
        q.emplace(buildings[idx][1], buildings[idx][2]);
        idx++;
      }

      while(!q.empty() && q.top().first <= dot) {
        q.pop();
      }

      int maxn = q.empty() ? 0 : q.top().second;
      if(ret.size() == 0 || maxn != ret.back()[1]) {
        ret.push_back({dot, maxn});
      }
    }
    return ret;
  }
};