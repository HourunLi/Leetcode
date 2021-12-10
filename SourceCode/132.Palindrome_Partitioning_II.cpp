class Solution {
private:
    bool flag[2000][2000];
    int ret[2001];
public:
    int dp(int k) {
        if(ret[k] != INT_MAX) return ret[k];
        for(int i = k-1; i >= 0; i--) {
            if(flag[i][k-1]) {
                ret[k] = min(dp(i) + 1, ret[k]);
            }
        }
        return ret[k];
    }
    int minCut(string s) {
        memset(flag, 1, sizeof(bool) *2000*2000);
        int n = s.size();
        for(int i = n-1; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                flag[i][j] = (s[i] == s[j]) && flag[i+1][j-1];
            }
        }
        for(int i = 0; i <= n; i++) {
            ret[i] = INT_MAX;
        }
        ret[0] = -1;
        return dp(n);
    }
};