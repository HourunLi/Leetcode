#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    short *dp;
    bool* value;
    int size;
public:
    bool dfs(int mask) {
        if(dp[mask] != -1) return dp[mask];
        for(int sub = (~mask)&(size - 1); sub; sub = (sub-1)&(~mask)) {
            if(value[sub]) {
                if(dp[mask] == -1)
                    dp[mask] = dfs(mask ^ sub);
                else if(dp[mask] == 0) {
                    dp[mask] |= dfs(mask ^ sub);
                } 
            }
        }
        dp[mask] = dp[mask]>=1;
        return dp[mask];
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto i : nums) {
            sum += i;
        }
        int target = sum/k;
        if(target * k  != sum) return false;
        int n = nums.size();
        size = (1 << n);
        dp = (short *)malloc(size*sizeof(short));
        value = (bool *)calloc(size, sizeof(bool));
        for(int i = 0; i < size; i++) 
            dp[i] = -1;
        dp[size-1] = 1;

        for(int sub = 1; sub < size; sub++) {
            int tmp = 0;
            for (int i = 0; i < n; i++){
                if(sub&(1<<i)) {
                    tmp += nums[i];
                }
            }
            if(tmp != target) continue;
            value[sub]=1;
        }

        return dfs(0);
    }
};

class Solution {
private:
    // short *dp;
    map<int, int> memo;
    set<int> value;
    int size;
public:
    bool dfs(int mask) {
        if(memo.find(mask) != memo.end()) return memo[mask];
        for(int sub = (~mask)&(size - 1); sub; sub = (sub-1)&(~mask)) {
            if(value.count(sub)) {
                if(memo.find(mask) == memo.end())
                    memo[mask] = dfs(mask ^ sub);
                else
                    memo[mask] |= dfs(mask ^ sub);
            }
        }
        return memo[mask];
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto i : nums) {
            sum += i;
        }
        int target = sum/k;
        if(target * k  != sum) return false;
        int n = nums.size();
        size = (1 << n);
        memo[size-1] = 1;

        for(int sub = 1; sub < size; sub++) {
            int tmp = 0;
            for (int i = 0; i < n; i++){
                if(sub&(1<<i)) {
                    tmp += nums[i];
                }
            }
            if(tmp != target) continue;
            value.insert(sub);
        }

        return dfs(0);
    }
};

class Solution {
private:
    short *dp;
    set<int> value;
    int size;
public:
    bool dfs(int mask) {
        if(dp[mask] != -1) return dp[mask];
		for(auto sub : value) {
			if(sub & mask) continue;
			if(dp[mask] == -1)
				dp[mask] = dfs(mask ^ sub);
			else if(dp[mask] == 0) {
				dp[mask] |= dfs(mask ^ sub);
			} 
		}
        dp[mask] = dp[mask]>=1;
        return dp[mask];
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto i : nums) {
            sum += i;
        }
        int target = sum/k;
        if(target * k  != sum) return false;
        int n = nums.size();
        size = (1 << n);
        dp = (short *)malloc(size*sizeof(short));
        for(int i = 0; i < size; i++) 
            dp[i] = -1;
        dp[size-1] = 1;

        for(int sub = 1; sub < size; sub++) {
            int tmp = 0;
            for (int i = 0; i < n; i++){
                if(sub&(1<<i)) {
                    tmp += nums[i];
                }
            }
            if(tmp != target) continue;
            value.insert(sub);
        }

        return dfs(0);
    }
};