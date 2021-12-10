#include<bits/stdc++.h>
using namespace std;
#define MINI 1e-6
/*solution1 TLE*/
class Solution {
public:
    int sum, n;
    float target;
    inline bool equal(float operand1, float operand2) {
        return fabs(operand1 - operand2) < MINI;
    }
    bool dfs(int now, int pos, int k, vector<int>& nums) {
        float mean = ((float)now) / k;
        if(mean > target + MINI) 
            return false;
        if(pos == n) 
            return equal(mean, target) && k!=n;
    
            // return ((float)now)/k == target && k!=n;

        for(int i = pos; i < n; i++) {
            int ret = dfs(now+nums[i], i+1, k+1, nums);
            if(ret)
                return true;
        }
        return false;
    }
    bool splitArraySameAverage(vector<int>& nums) {
        sum = 0;
        n = nums.size();
        sort(nums.begin(),nums.end());
        for(auto i : nums) 
            sum += i;
        target = sum*1.0/n;
        return dfs(0, 0, 0, nums);
    }

};


/*solution2 TLE*/
class Solution {
public:
    int sum, n;
    float target;
    inline bool equal(float operand1, float operand2) {
        return fabs(operand1 - operand2) < MINI;
    }
    bool dfs(int now, map<int, int>::iterator pos, int k, map<int, int>& mmap) {
        float mean = ((float)now) / k;
        if(mean > target + MINI) 
            return false;
        if(pos == mmap.end()) 
            return equal(mean, target) && k!=n;
    
            // return ((float)now)/k == target && k!=n;

        // for(auto i = pos; i != mmap.end(); i++) {
        auto next = pos;
        next++;
        for(int j = 0; j <= pos->second; j++) {
            bool ret = dfs(now + j*pos->first, next, k+j, mmap);
            if(ret)
                return true;
        }
        // }
        return false;
    }
    bool splitArraySameAverage(vector<int>& nums) {
        map<int, int> mmap;
        sum = 0;
        n = nums.size();
        sort(nums.begin(),nums.end());
        for(auto i : nums) {
            sum += i;
            if(mmap.find(i) == mmap.end()) {
                mmap[i] = 1;
            }else{
                mmap[i]++;
            }
        }
        auto ptr = mmap.begin();
        target = sum*1.0/n;
        return dfs(0, ptr, 0, mmap);
    }
};

/*solution3*/
// class Solution {
// public:
//     int sum, n;
//     double target;
//     inline bool equal(double operand1, double operand2) {
//         return fabs(operand1 - operand2) < MINI;
//     }

//     bool dfs(double sum, int num, int bp, int sp, int bsize, int ssize) {
//         bool flag1 = bp == bsize;
//         bool flag2 = sp == ssize;
//         double mean = sum/num;
//         if(flag1 && flag2) {
//             return equal(mean, target) && num!=(bsize + ssize);
//         }else if(flag1) {
//             if(mean < target) return false;
//         }else if(flag2) {
//             if(mean > target) return false;
//         }


//     }
//     bool splitArraySameAverage(vector<int>& nums) {
//         map<int, int> mmap;
//         sum = 0;
//         n = nums.size();
//         vector<int> smaller;
//         vector<int> bigger;
//         for(auto i : nums) {
//             sum += i;
//         }
//         target = sum*1.0/n;
//         for(auto i: nums) {
//             if(equal(i, target)){
//                 return true;
//             }else if(i > target) {
//                 bigger.push_back(i);
//             }else {
//                 smaller.push_back(i);
//             }
//         }
//         return dfs(0, 0, 0, 0, bigger.size(), smaller.size());
//     }
// };


class Solution {
public:
    int sum, n;
    bool *vis;
    double target;
    map<string, bool> memo;

    inline bool equal(double operand1, double operand2) {
        return fabs(operand1 - operand2) < MINI;
    }

    bool dfs(double sum, int num, int k, vector<int>& nums) {
        double mean = num == 0 ? -1 : sum/num;
        bool flag = equal(mean, target) && num !=n;
        string str = makeStr(num, sum);
        if(memo.find(str) != memo.end())
            return memo[str];
        if(n == k || flag) {
            memo[str]=flag;
            return flag;
        }
        bool flag2 = mean > target;
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            if(flag2 && nums[i] > target) continue;
            else if(!flag2 && nums[i] < target) continue;
            vis[i]=1;
            bool tmp = dfs(sum + nums[i], num+1, k+1, nums);
            if(tmp) {
                return true;
            }
            vis[i]=0;
        }
        memo[str] = false;
        return false;


    }
    string makeStr(int a, double b) {
        string str;
        char ch = 50+a;
        str = str + ch + to_string(b);
        return str;
    }
    bool splitArraySameAverage(vector<int>& nums) {
        sum = 0;
        n = nums.size();
        vis = (bool *)calloc(n, sizeof(bool));
        for(auto i : nums) {
            sum += i;
        }
        target = sum*1.0/n;
        return dfs(0, 0, 0, nums);
    }
};

class Solution {
public:
    int sum, n;
    bool *vis;
    double target;
    map<pair<int, double>, bool> memo;

    inline bool equal(double operand1, double operand2) {
        return fabs(operand1 - operand2) < MINI;
    }

    bool dfs(double sum, int num, int k, vector<int>& nums) {
        pair<int, double> pair = make_pair(num, sum);
        double mean = sum / num;
        if(memo.find(pair) != memo.end())
            return memo[pair];
        if(k == n) {
            return equal(mean, target); 
        }
        bool ret = false;
        if(mean == target) return true;
        bool flag = mean > target;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 1) continue;
            if(flag && nums[i] > target) continue;
            if(!flag && nums[i] < target) continue;
            vis[i] = 1;
            ret |= dfs(sum + nums[i], num + 1, k + 1, nums);
            if(ret)
                return true;
            vis[i] = 0;
        }
        ret |= dfs(sum, num, k + 1, nums);
        memo[pair] = ret;
        return memo[pair];
    }

    bool splitArraySameAverage(vector<int>& nums) {
        sum = 0;
        n = nums.size();
        vis = (bool *)calloc(n, sizeof(bool));
        for(auto i : nums) {
            sum += i;
        }
        memo[make_pair(n, sum)] = false;
        target = sum*1.0/n;
        return dfs(0, 0, 0, nums);
    }
};


