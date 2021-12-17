#include<bits/stdc++.h>
using namespace std;
/*time optimized*/
class Solution {
public:
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    int *ret = (int*)calloc((n), sizeof(int));
    for(auto &item : bookings) {
      int begin = item[0], end = item[1], num = item[2];
      ret[begin-1] += num;
      if(end < n)
        ret[end] -= num;
    }
    for(int i = 1; i < n; i++) {
      ret[i] += ret[i-1];
    }
    vector<int> retVec(ret, ret+n);
    return retVec;
  }
};
/* space optimized */
class Solution {
public:
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> ret(n, 0);
    for(auto &item : bookings) {
      int begin = item[0], end = item[1], num = item[2];
      ret[begin-1] += num;
      if(end < n)
        ret[end] -= num;
    }
    for(int i = 1; i < n; i++) {
      ret[i] += ret[i-1];
    }
    return ret;
  }
};
