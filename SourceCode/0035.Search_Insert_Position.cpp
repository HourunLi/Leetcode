class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        long long int l = 0, r = nums.size()-1;
        int pos;
        if(target > nums[r]) return r+1;
        while(l <= r) {
            int mid = (l+r) >> 1;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) {
                l = mid+1;
            }else{
                pos = mid;
                r = mid-1;
            }
        }
        return pos;
    }
};