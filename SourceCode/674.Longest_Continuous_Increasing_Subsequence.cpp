class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0, cnt = 0;
        int start = INT_MIN;
        for(auto i : nums) {
            if(i > start) {
                cnt ++;
            }else{
                ans = cnt > ans ? cnt : ans;
                cnt = 0;
            }
            start = i;
        }
        return ans;
    }
};