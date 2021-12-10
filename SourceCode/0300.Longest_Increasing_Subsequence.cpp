/*DP*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j ++) {
                if(nums[j] > nums[i]) 
                    ans[j] = ans[i] + 1 > ans[j] ? ans[i]+1 : ans[j];
            }
        }
        return *max_element(ans.begin(), ans.end());
    }
};


/*bisearch and greedy 1*/
class Solution {
public:
    //return true if insert, else false
    void bisearch(vector<int>& ans, int val, int &n) {
        if(n && val < ans[0]) {
            ans[0] = val;
            return;
        }
        if(!n){
            ans.push_back(val);
            n++;
            return;
        }
        int l = 0, r = n-1;
        int pos = -1;
        while(l <= r) {
            int mid = (l+r)/2;
            if(ans[mid] < val) {
                pos = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        if(pos == n-1) {
            ans.push_back(val);
            n++;
        }else{
            ans[pos+1] = val;
        }
        return;
    } 
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int size = 0;
        for(auto i : nums) {
            bisearch(ans, i, size);
        }
        return ans.size();
    }
};

/*bisearch and greedy 2*/
class Solution {
public:
    //return true if insert, else false
    void bisearch(vector<int>& ans, int val, int &n) {
        if(n && val > ans[n-1] || !n) {
            ans.push_back(val);
            n++;
            return;
        }
        int l = 0, r = n-1;
        int pos = n-1;
        while(l <= r) {
            int mid = (l+r) >> 1;
            if(ans[mid] < val) {
                l = mid+1;
            }else{
                pos = mid;
                r = mid-1;
            }
        }
        ans[pos] = val;
        return;
    } 
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int size = 0;
        for(auto i : nums) {
            bisearch(ans, i, size);
        }
        return size;
    }
};

