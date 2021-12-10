#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        int size = (1 << n), bucketSize = n/k;
        int *value = (int *)malloc(size*sizeof(int));

        for(int i = 0; i < size; i++)
            value[i] = -1;

        int *sub = (int *)calloc(n+1, sizeof(int));

        for(int subMask = 0; subMask < size; subMask++) {
            if(__builtin_popcount(subMask) != bucketSize) continue;
            for(int i = 0; i < n; i++) {
                int bit = subMask & (1 << i);
                if(!bit) continue;
                sub[nums[i]]++; 
            }
            int flag = 0;
            for(int i = 0; i < n+1; i++) {
                if(sub[i] > 1) {
                    flag = 1;
                    break;
                }
            }
            if(!flag)  {
                int max_ = INT_MIN, min_ = INT_MAX;
                for(int i = 0; i < n+1; i++) {
                    if(sub[i]) {
                        max_ = max(max_, i);
                        min_ = min(min_, i);
                    }
                }
                value[subMask] = max_ - min_;
            }
            memset(sub, 0, sizeof(int)*(n+1));
        }

        int *dp = (int *)malloc(size * sizeof(int));
        for(int i = 0; i < size; i++) {
            dp[i] = -1;
        }
        dp[0] = 0;

        for(int mask = 0; mask < size; mask++) {
            if(__builtin_popcount(mask) % bucketSize) continue;
            for(int subMask = mask; subMask; subMask = (subMask-1) &mask) {
                if(value[subMask] != -1 && dp[mask ^ subMask] != -1) {
                    if(dp[mask] == -1) {
                        dp[mask] = dp[mask ^ subMask] + value[subMask];
                    }else{
                        dp[mask] = min(dp[mask], dp[mask ^ subMask] + value[subMask]);
                    }
                }
            }
        }
        return dp[size-1];
    }
};