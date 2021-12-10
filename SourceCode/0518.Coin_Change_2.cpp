#include<bits/stdc++.h>
using namespace std;

/*solution1*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int *vis = (int *)calloc(amount +1, sizeof(int));
        vis[0] = 1;
        int n = coins.size();
        for(int i = 0; i < n; i++) {
            for(int j = amount; j >= coins[i]; j--) {
                int t = j / coins[i];
                for(int k = 1; k <= t; k++) {
                    if(INT_MAX - vis[j-coins[i]*k] < vis[j]) continue;
                    vis[j] += vis[j-coins[i]*k];
                }
            }
        }
        return vis[amount];
    }
};

/*solution2*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int *vis = (int *)calloc(amount +1, sizeof(int));
        vis[0] = 1;
        int n = coins.size();
        for(int i = 0; i < n; i++) {
            for(int j = coins[i]; j <= amount; j++) {
                vis[j] += vis[j-coins[i]];
            }
        }
        return vis[amount];
    }
};
