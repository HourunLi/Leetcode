#include<bits/stdc++.h>
using namespace std;
/*solution1*/
class Solution {
private:
    int len, edge, size;
    bool *value;
    int *dp;
public:
    bool dfs(int mask, vector<int>& matchsticks) {
        if(dp[mask] != -1) return dp[mask];
        for(int sub = size-1; sub; sub =(sub-1)&(~mask)) {
            if(value[sub]) {
                if(dp[mask] == -1) {
                    dp[mask] = dfs(mask^sub, matchsticks);
                }else{
                    dp[mask] |= dfs(mask^sub, matchsticks);
                }
            }
        }
        dp[mask] = dp[mask] >=1;
        return dp[mask];
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(auto i : matchsticks) {
            sum+= i;
        }
        edge = sum/4;
        if(edge * 4 != sum) return false;
        len = matchsticks.size();
        size = 1 << len;
        dp = (int *)malloc(size*sizeof(int));
        value = (bool *)calloc(size, sizeof(bool));

        for(int i = 0; i < size; i++) {
            dp[i] = -1;
        }
        dp[size-1] = 1;

        for(int sub = 0; sub < size; sub++) {
            int tmp = 0;
            for(int i = 0; i < len; i++) {
                if(sub & (1 << i)) {
                    tmp += matchsticks[i];
                }
            }
            if(tmp == edge) {
                value[sub] = 1;
            }
        }

        dfs(0, matchsticks);
        return dp[0];
    }
};
/*solution2*/
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(auto i : matchsticks) {
            sum+= i;
        }
        int edge = sum/4;
        if(edge * 4 != sum) return false;

        int n = matchsticks.size();
        int size = 1<<n;
        bool *dp = (bool*)calloc(sizeof(bool), size);
        bool *value = (bool*)calloc(sizeof(bool), size);
        dp[size-1] = 1;


        for(int sub = 0; sub < size; sub++) {
            int tmp = 0;
            for(int i = 0; i < n; i++) {
                if(sub & (1 << i)) {
                    tmp += matchsticks[i];
                }
            }
            if(tmp == edge) {
                value[sub] = 1;
            }
        }

        for(int mask = size-1; mask>=0; mask--) {
            for(int sub = (size-1)&(~mask); sub; sub =(sub-1)&(~mask)) {
                if(value[sub])
                    dp[mask] |= dp[mask^sub];
            }
        }

        return dp[0];
    }
};

/*solution3*/
//TIME LIMITED
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(auto i : matchsticks) {
            sum+= i;
        }
        int edge = sum/4;
        if(edge * 4 != sum) return false;

        int n = matchsticks.size();
        int size = 1<<n;
        // bool *dp = (bool*)calloc(sizeof(bool), size);
        bitset<(1<<15)> dp;
        // bool *value = (bool*)calloc(sizeof(bool), size);
        bitset<(1<<15)> value;
        dp[size-1] = 1;


        for(int sub = 0; sub < size; sub++) {
            int tmp = 0;
            for(int i = 0; i < n; i++) {
                if(sub & (1 << i)) {
                    tmp += matchsticks[i];
                }
            }
            if(tmp == edge) {
                value[sub] = 1;
            }
        }

        for(int mask = size-1; mask>=0; mask--) {
            for(int sub = (size-1)&(~mask); sub; sub =(sub-1)&(~mask)) {
                if(value[sub])
                    dp[mask] = dp[mask] | dp[mask^sub];
            }
        }

        return dp[0];
    }
};

/*dfs*/
class Solution {
private:
    int size[4];
public:
    bool dfs(vector<int>& matchsticks, int index, int target, int n) {
        if(index == -1) {
            if(size[0] == size[1] && size[1] == size[2] && size[2] == size[3]) {
                return true;
            }
            return false;
        }
        for(int i = 0; i < 4; i++) {
            if(size[i]+matchsticks[index]>target || i > 0 && size[i] == size[i-1] || index == n-1 && i)
                continue;
            size[i] += matchsticks[index];
            if(dfs(matchsticks, index-1, target, n)) {
                return true;
            }
            size[i] -= matchsticks[index];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(auto i : matchsticks) {
            sum+= i;
        }
        int edge = sum/4;
        if(edge * 4 != sum) return false;

        int n = matchsticks.size();
        for(int i =0; i< 4; i++)
            size[i] =0;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());

        return dfs(matchsticks, n-1, edge, n);
    }
};