#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l <= r) {
            if(nums[l] == nums[r]) {
                l++;
                continue;
            }
            int mid = (l+r) >> 1;
            if(nums[mid] == target) return true;
            bool flag1 = nums[mid] >= nums[l], flag2 = target >= nums[l];
            if(nums[mid] > target) {
                if(flag1 && flag2 || !flag1 && !flag2) r = mid-1;
                else if(flag1) {
                    l = mid +1;
                }else if (flag2){
                    cout << "error\n";
                    return false;
                }
            } else{
                if(flag1 && flag2 || !flag1 && !flag2) l = mid+1;
                else if(flag1) {
                    cout << "error\n";
                    return false;
                }else{
                    r = mid-1;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> x {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    cout << solution.search(x, 2) << endl;
    return 0;
 }
 /*
[1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1]
2
*/