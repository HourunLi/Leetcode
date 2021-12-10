#include<bits/stdc++.h>
using namespace std;
#define JUDGE(a, b) !((a)%(b))
class Solution {
private:
    int ret;
    bool *vis;
public:
    void dfs(int k, int n) {
        if(!k) {
            ret++;
            return;
        }
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            if(JUDGE(k, i+1) || JUDGE(i+1, k)) {
                vis[i] = 1;
                dfs(k-1, n);
                vis[i] = 0;
            }
        }
        return;
    }
    int countArrangement(int n) {
        vis = (bool *)calloc(n, sizeof(bool));
        ret = 0;
        dfs(n, n);
        return ret;
    }
};

/*solution2*/
class Solution {
public:
    int countArrangement(int n) {
        int size = (1<<n);
        int *dp = (int*)calloc(size,  sizeof(int));
        dp[0]=1;
        for(int mask = 1; mask < size; mask++) {
            int num = __builtin_popcount(mask);
            for(int i = 0; i < n; i++) {
                if((1 << i) & mask) {
                    if(JUDGE(i+1, num) || JUDGE(num, i+1)) {
                        dp[mask] += dp[mask ^ (1 << i)];
                    }
                }
            }
        }
        return dp[size-1];
    }
};