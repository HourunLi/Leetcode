#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
  vector<string> ret;
public:
  void dfs(int l, int r, string s) {
    if(!l && ! r){
      ret.push_back(s);
    }
    if(l) {
      dfs(l-1, r, s+"(");
    }
    if(l < r) {
      dfs(l, r-1, s+")");
    }
    return;
  }
  vector<string> generateParenthesis(int n) {
    dfs(n, n, "");
    return ret;
  }
};