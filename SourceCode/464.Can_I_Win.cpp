#include<bits/stdc++.h>
using namespace std;
/*solution1*/
class Solution {
private:
    int *dp;
    int maxNum;
public:
    int dfs(int mask, int total) {
        if(dp[mask] != -1) return dp[mask];
        for(int i = maxNum-1; i >= 0 ; i--) {
            if((1 << i) & mask) continue;
            if(i+1 >=total) {
                dp[mask] = 1;
                return dp[mask];
            }
            if(dp[mask] == -1) {
                dp[mask] = !dfs(mask ^ (1 << i), total - i - 1);
            }else{
                dp[mask] |= !dfs(mask ^ (1 << i), total - i - 1);
            }
        }
        dp[mask] = dp[mask] >=1;
        return dp[mask];
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger*(maxChoosableInteger + 1) / 2 < desiredTotal) return 0;
        int size = 1 << maxChoosableInteger;
        maxNum = maxChoosableInteger;
        dp = (int *) malloc(size * sizeof(int));
        for(int i = 0; i < size; i++) 
            dp[i] = -1;
        return dfs(0, desiredTotal);
    }
};

/*solution2*/
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger*(maxChoosableInteger + 1) / 2 < desiredTotal) return 0;
        int size = 1 << maxChoosableInteger;
        char *dp = (char *) calloc(size, sizeof(char));
        for(int mask = size-1; mask >=0; mask--) {
            int total = desiredTotal;
            for(int sub = maxChoosableInteger-1; sub >=0; sub--) {
                if(mask & (1<<sub)) 
                    total = total- sub-1;
            }

            for(int sub = maxChoosableInteger-1; sub >=0; sub--){
                if(mask & (1<<sub)) continue;
                if(sub+1 >= total || !dp[mask ^ (1<<sub)])
                    dp[mask] = 1;
            }
        }
        return dp[0];
    }
};

class Solution {
public:

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if((1+maxChoosableInteger)*maxChoosableInteger/2<desiredTotal) return false;
        int state_max = 1<<maxChoosableInteger;
        vector<char> dp(state_max,0);
        
        int i,j,k;
        for(i=state_max-1;i>=0;i--){
            int total = desiredTotal;
            for(k=0;k<maxChoosableInteger;k++){
                if((1<<k)&i) total -= k+1;
            }
            for(k=0;k<maxChoosableInteger;k++){
                if((1<<k)&i) continue;
                if(k+1>=total || !dp[(1<<k)|i]) {  //玩家游戏时都表现最佳是指先手选择一个数字后后手必输
                    dp[i] = 1;
                }
            }
        }
        return dp[0];
    }
};
