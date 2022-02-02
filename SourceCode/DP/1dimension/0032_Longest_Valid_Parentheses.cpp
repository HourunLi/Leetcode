#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    int n = s.size();
    int *ret = (int*)calloc(n,  sizeof(int)); 
    int ans = 0;
    stack<int> sta;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
      char ch = s[i];
      if(ch == '(') {
        sta.push(i);
        ret[i] = 0;
        cnt = 0;
      }else {
        if(sta.empty() || s[sta.top()] == ')') {
          sta.push(i);
          cnt = 0;
          ret[i] = 0;
        }else{
          cnt += 2;
          ret[i] = sta.top() == 0 ? cnt : cnt + ret[sta.top()-1];
          cnt = ret[i];
          sta.pop();
          ans = max(ans, ret[i]);
        }
      }
    }
    return ans;
  }
};