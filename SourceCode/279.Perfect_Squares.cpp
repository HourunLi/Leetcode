#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX/2
class Solution {
public:
    int numSquares(int n) {
        int *vis = (int *)malloc(sizeof(int) * (n+1));
        vis[0] = 0;
        for(int i = 1; i <=n; i++) 
            vis[i] = INF;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j*j <= i; j++) {
                vis[i] = min(vis[i-j*j]+1, vis[i]);
            }
        }
        return vis[n];
    }
};