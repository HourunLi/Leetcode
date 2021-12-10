class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        while(r < n) {
            if(nums[r]) {
                nums[l] = nums[r];
                l++;
                r++;
            }else{
                r++;
            }
        }
        while(l < n) {
            nums[l] = 0;
            l++;
        }
        return;
    }
};