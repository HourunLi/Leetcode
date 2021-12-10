class Solution {
public:
    void print(vector<vector<int>> &ans, vector<int> &c, map<int, int> &hashtable, vector<int> &value, int k, int n) {
        if(k == n) {
            ans.push_back(c);
            return;
        }
        int size = value.size();
        for(int i = 0; i < size; i++) {
            if(hashtable[value[i]] == 0) continue;
            hashtable[value[i]]--;
            c.push_back(value[i]);
            print(ans, c, hashtable, value, k+1, n);
            c.pop_back();
            hashtable[value[i]]++;
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        map<int, int> hashtable;
        vector<vector<int>> ans;
        vector<int> value, c;
        for(int i = 0; i < n; i++) {
            if(hashtable.find(nums[i]) == hashtable.end()) {
                hashtable[nums[i]] = 1;
                value.push_back(nums[i]);
            }else{
                hashtable[nums[i]]++;
            }
        }
        print(ans, c, hashtable, value, 0, n);
        return ans;
    }
};