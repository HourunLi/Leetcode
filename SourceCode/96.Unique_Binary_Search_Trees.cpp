class Solution {
public:
    int dp(int n, int *ans) {
        if(ans[n] != -1) return ans[n];
        int ret = 0;
        for(int i = 1; i <= n; i++) {
            ret += dp(i-1, ans) * dp(n-i, ans); 
        }
        ans[n] = ret;
        return ret;
    }

    int numTrees(int n) {
        if(n == 0) return 0;
        int *ans = new int[n+1];
        memset(ans, -1, sizeof(int)*(n+1));
        ans[0] = 1;
        ans[1] = 1;
        return dp(n, ans);
    }
};