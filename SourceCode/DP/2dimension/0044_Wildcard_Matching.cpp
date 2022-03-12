#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    bool **dp = new bool *[n+1]; 
    for(int i = 0; i <= n; i++) {
      dp[i] = new bool[m+1]();
    }

    dp[0][0] = true;
    for(int i = 1; i <= n; i++) {
      if(p[i-1] != '*') {
        dp[i][0] = false;
      }else{
        dp[i][0] |= dp[i-1][0];
      }
    }

    for(int i = 1; i <= n; i++) {
      for(int j = 1;j <= m; j++) {
        if(s[j-1] == p[i-1] || p[i-1] == '?') {
          dp[i][j] |= dp[i-1][j-1];
        }
        if(p[i-1]== '*') {
          dp[i][j] |= dp[i-1][j] || dp[i][j-1];
        }
      }
    }

    // for(int i = 0; i < )
    return dp[n][m];
  }
};

