#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int lo = 0, hi = 1e9;
    int mid;
    while(lo <= hi) {
      mid = (lo+hi) >> 1;
      if(possble(piles, mid, h)) {
        hi = mid-1;
      }else{
        lo = mid+1;
      }
    }
    return lo;
  }

  bool possble(vector<int>& piles, int k, int H) {
    int t = 0;
    for(int &i : piles){
      t += (i - 1)/k + 1;
    }
    if(t > H) return false;
    return true; 
  }
};