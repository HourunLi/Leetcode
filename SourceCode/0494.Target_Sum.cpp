#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0; 
        for(auto i : nums)
            sum += i;
        int tar = sum - target;
        if(tar < 0  || target & 1) 
            return 0;
        tar = tar >> 1;
        int n = nums.size();
        int *vis = (int *) calloc(tar+1, sizeof(int));
        vis[0]=1;
        for(int i = 0; i < n ; i ++) {
            for(int j = tar; j >= nums[i]; j--) {
                vis[j] = vis[j] + vis[j-nums[i]];
            }
        }
        return vis[tar];
    }
};
