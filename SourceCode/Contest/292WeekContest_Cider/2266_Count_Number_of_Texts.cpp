#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
  int ans[100010];
public:
  int dp(string &pressedKeys, int n) {
    if(n < 0) return 0;
    if(ans[n]) return ans[n];
    char ch = pressedKeys[n-1];
    int cnt = ch == '7' || ch == '9' ? 4 : 3;
    for(int i = n; i > n-cnt; i--) {
      if(pressedKeys[i-1] != ch)
        break;
      ans[n] += dp(pressedKeys, i-1);
      ans[n] %= (1000000007);
    }
    return ans[n];
  } 
  int countTexts(string pressedKeys) {
    memset(ans, 0, sizeof(int) * 100010);
    ans[0] = 1;
    int n = pressedKeys.size();
    return dp(pressedKeys, n); 
  }
};

int main() {
  Solution solution;
  cout << solution.countTexts("222222222222222222222222222222222222");
  return 0;
}