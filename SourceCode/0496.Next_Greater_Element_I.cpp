class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        map<int, int> ans;
        int n = nums2.size();
        stack<int> q;
        for(auto i : nums2) {
            while(!q.empty() && i > q.top()) {
                int front = q.top();
                ans[front] = i;
                q.pop();
            }
            q.push(i);
        }

        for(auto i : nums1) {
            if(ans.find(i) == ans.end()) {
                ret.push_back(-1);
            }else{
                ret.push_back(ans[i]);
            }
        }
        return ret;
    }
};