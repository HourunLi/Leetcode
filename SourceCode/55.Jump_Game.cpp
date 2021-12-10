#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int> nums) {
        int range = 0, len = nums.size()-1, cnt = -1, tem;
        if(len == 0) return true;
        while(++cnt <= range) {
            tem = nums[cnt] + cnt;
            if(tem > range) {
                range = tem;
                if(range >= len) return true;
            }  
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.canJump({3,5,2,4,3,0,0,0,2,3});
}