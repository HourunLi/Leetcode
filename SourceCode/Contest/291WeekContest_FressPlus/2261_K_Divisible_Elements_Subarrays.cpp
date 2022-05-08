#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_set<string> ans;
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        for(int l = 0; l < n; l++) {
            int cnt = 0;
            string str;
            for(int r = l; r < n; r++) {
                int cond = nums[r] % p;
                if(cond) {
                    str = str + "#" + to_string(nums[r]);
                    ans.insert(str);
                } else if(cnt < k){
                    cnt++;
                    str = str + "#" + to_string(nums[r]);
                    ans.insert(str);
                } else {
                    break;
                }
            }
        }
        return ans.size();
    }
};

// int main() {
//     Solution s;
//     vector<int> input = {2,3,3,2,2};
//     cout << s.countDistinct(input, 2,2);
//     return 0;
// }