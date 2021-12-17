#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX/2
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int *vis;
        vis = (int *)malloc((amount + 1)*sizeof(int));
        for(int i = 1; i <= amount; i++)
            vis[i] = INF;
        vis[0] = 0;
        int n = coins.size();
        for(int i = 0; i < n; i++) {
            for(int j = coins[i]; j<= amount; j++) {
                vis[j] = min(vis[j], vis[j-coins[i]]+1);
            }
        }
        return vis[amount] >= INF ? -1 : vis[amount];
    }
};