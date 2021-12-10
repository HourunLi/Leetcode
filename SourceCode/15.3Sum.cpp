#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int first = 0; first < n; first++) {
            if(first > 0 && nums[first] == nums[first-1]) {
                continue;
            }
            int target = -nums[first];
            int third = n-1;
            for(int second = first + 1; second <n; second++) {
                if(second > first+1 && nums[second] == nums[second-1]){
                    continue;
                }
                
                while(second < third && nums[second]+nums[third] > target) {
                    third--;
                }
                if(second >= third) break;
                if(nums[second]+nums[third] == target) {
                    ret.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ret;
    }
};