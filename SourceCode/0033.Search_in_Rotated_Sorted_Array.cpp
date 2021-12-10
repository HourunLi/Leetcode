class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = nums[0];
        bool flag1 = (target >= pivot);
        int l = 0, r = nums.size()-1;
        while(l <= r) {
            int mid = (l+r)/2;
            bool flag2 = (nums[mid] >= pivot);
            if(flag1 == flag2) {
                if(nums[mid] == target) return mid;
                if(nums[mid] < target) l = mid+1;
                else r = mid - 1;
            }else if(flag1) {
                r = mid-1; 
            }else{
                l= mid+1;
            }
        }
        return -1;
    }
};