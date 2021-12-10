#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<pair<int, int>> q;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n ; j++) {
                while(!q.empty() && q.top().first < nums[j]) {
                    auto item = q.top();
                    q.pop();
                    ans[item.second] = nums[j];
                }
                q.push(make_pair(nums[j], j));
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> vec = {1,2,1};
    s.nextGreaterElements(vec);
    return 0;
}