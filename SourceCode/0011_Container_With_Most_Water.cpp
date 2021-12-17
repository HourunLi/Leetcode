#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int h = min(height[l], height[r]);
        int ret = h * (r-l);

        while(l < r) {
            if(height[l] <= height[r]) 
                l++;
            else
                r--;
            int tmp = min(height[l], height[r]);
            if(h < tmp) {
                h = tmp;
                ret = max(ret, h * (r-l));
            }
        }
        return ret;
    }
};