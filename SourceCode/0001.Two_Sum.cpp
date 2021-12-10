#include <vector>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/*brute method*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        for(int i = 0; i < size; i ++) {
            for(int j = 0; j < size; j++) {
                if(i == j) continue;
                if(nums[i] + nums[j] == target) 
                    return {i, j};
            }
        }
        return {};
    }
};

/*hash method -- unordered_map*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int size = nums.size();
        int tem;
        for(int i = 0; i < size; i ++) {
            tem = target - nums[i];
            auto it = map.find(tem);
            if(it != map.end()) {
                return {i, it->second};
            }
            map.insert(pair<int, int> (nums[i], i));
        }
        return {};
    }
};

/*hash method -- map*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> map;
        int size = nums.size();
        int tem;
        for(int i = 0; i < size; i ++) {
            tem = target - nums[i];
            auto it = map.find(tem);
            if(it != map.end()) {
                return {i, it->second};
            }
            map.insert(pair<int, int> (nums[i], i));
        }
        return {};        
    }
};