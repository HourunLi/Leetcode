#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int shipWithinDays(vector<int>& weights, int days) {
    int lo = 1, hi = 25000000;
    int mid;
    while(lo <= hi) {
      mid = (lo+hi) >>1;
      if(possible(weights, mid, days)) {
        hi = mid-1;        
      }else{
        lo = mid+1;
      }
    }
    return lo;
  }

  bool possible(vector<int>& weights, int k, int days) {
    int ret = 0;
    int now = 0;
    for(int &i : weights) {
      if(i > k) return false;
      now += i;
      if(now > k) {
        ret ++;
        now = i;
      }
    }
    ret++;
    return ret <= days;
  }
};