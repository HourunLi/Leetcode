#include<bits/stdc++.h>
using namespace std;
/*solution1*/
class Solution {
private:
  vector<vector<int> > ret;
public:
  void dfs(vector<int>& candidates, int pos, int &n, int target, vector<int> tmp) {
    if(target == 0) {
      ret.push_back(tmp);
    }
    if(pos == n || target < candidates[pos])
      return;

    int t = target / candidates[pos];
    if(pos == n-1) {
      for(int i = 0; i < t; i++) {
        tmp.push_back(candidates[pos]);
      }
      dfs(candidates, pos+1, n, target - t*candidates[pos], tmp);
    }else{
      for(int i = 0; i <= t; i++) {
        dfs(candidates, pos+1, n, target, tmp);
        tmp.push_back(candidates[pos]);
        target -= candidates[pos];
      }
    }
    return;  
  }
  vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    int n = candidates.size();
    vector<int> tmp;
    dfs(candidates, 0, n, target, tmp);
    return ret;
  }
};

/*
 * solution2
 * use & flag to eliminate copy
 */


class Solution {
private:
  vector<vector<int> > ret;
public:
  void dfs(vector<int>& candidates, int pos, int &n, int target, vector<int>& tmp) {
    if(target == 0) {
      ret.push_back(tmp);
      return;
    }
    if(pos == n)
      return;
    dfs(candidates, pos+1, n, target, tmp);
    if(target >= candidates[pos]) {
      target -= candidates[pos];
      tmp.push_back(candidates[pos]);
      //操作尽可能简单，只减去一个数就可以了
      dfs(candidates, pos, n, target, tmp);
      //保持原状态
      tmp.pop_back();
    }
    return;
  }
  vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    // sort(candidates.begin(), candidates.end());
    int n = candidates.size();
    vector<int> tmp;
    dfs(candidates, 0, n, target, tmp);
    return ret;
  }
};