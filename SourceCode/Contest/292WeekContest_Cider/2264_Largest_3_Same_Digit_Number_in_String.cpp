#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  string largestGoodInteger(string num) {
    int n = num.size();
    string ret = "";
    for(int i = 0; i <= n-3; i++) {
      if(num[i] == num[i+1] && num[i+1] == num[i+2]) {
        string tmp = num.substr(i, 3);
        if(tmp > ret) ret = tmp;
      }
    }
    return ret;
  }
};