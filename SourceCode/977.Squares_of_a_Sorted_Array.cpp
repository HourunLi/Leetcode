class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ret;
        int cnt, n = nums.size();
        for(int i = 0; i < n; i++) {
            nums[i] = abs(nums[i]);
            if(nums[i] >= 0) break;
        }      
        
        vector<int>::iterator pos;
        pos = distance(nums.begin(), min_element(nums.begin(), nums.end()));
        vector<int>::iterator l = pos, r = pos++;
        while(cnt < n) {
            int lnum, rnum;
            lnum = l < 0 ? INT_MAX : nums[l];
            rnum = r >= n? INT_MAX : nums[r];
            if(lnum < rnum) {
                ret.push_back(lnum *lnum);
                l--;
            }else{
                ret.push_back(rnum *rnum);
                r--;               
            }
            cnt++;
        }
        return ret;
    }
};