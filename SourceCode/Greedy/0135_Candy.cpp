#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int candy(vector<int>& ratings) {
    int n = ratings.size();
    int* l = new int[n](), *r = new int[n]();
    int cnt = 1, ret = 0;
    for(int i = 1; i < n; i++) {
      if(ratings[i] > ratings[i-1]) {
        cnt++;
      }else{
        cnt = 1;
      }
      l[i] = cnt;
    }

    cnt = 1;
    for(int i = n-2; i >= 0; i--) {
      if(ratings[i] > ratings[i+1]) {
        cnt++;
      }else{
        cnt = 1;
      }
      r[i] = cnt;
    }
    l[0] = r[n-1] = 1;
    for(int i = 0; i < n; i++) {
      ret += max(l[i], r[i]);
    }
    return ret; 
  }
};