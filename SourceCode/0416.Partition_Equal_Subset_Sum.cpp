#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto i : nums) {
            sum += i;
        }
        if(sum & 1) return false;
        int goal = sum/2;

        bool *vis = (bool *)calloc(goal+1, sizeof(bool));
        vis[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = goal; j >= nums[i]; j--) {
                vis[j] = vis[j] | vis[j-nums[i]]; 
            }
        }
        return vis[goal];
    }
};