#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        int *vis = (int*)calloc(target+1, sizeof(int));
        vis[0]=1;
        for(int i = 0 ; i <= target; i++) {
            for(int j = 0; j < n; j++) {
                if(nums[j] > i || INT_MAX-vis[i] < vis[i-nums[j]]) continue;
                vis[i] += vis[i-nums[j]];
            }
        }
        return vis[target];
    }
};