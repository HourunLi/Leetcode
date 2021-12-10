#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int *vis = (int*) calloc(target+1, sizeof(int));
        vis[0]=1;
        for(int i = 1; i <= d; i++) {
            for(int j = target; j >= 0; j--) {
                int cnt = 0;
                for(int k = 1; k <=f; k++) {
                    if(j >= k) {
                        cnt += vis[j-k];
                        cnt %= MOD;
                    }
                }
                vis[j] = cnt;
            }
        }
        return vis[target];
    }
};