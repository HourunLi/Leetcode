class Solution {
public:
    void print(vector<vector<int>> &ans, vector<int>& c, vector<int>& nums, int k, int n) {
        /*直接push_back是传入的拷贝而非实参*/
        if(k == n) {
            ans.push_back(c);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(c[i] != -20) continue;
            c[i] = nums[k];
            print(ans, c, nums, k + 1, n);
            c[i] = -20;
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> c(n, -20);
        print(ans, c, nums, 0, n);
        return ans;
    }
};