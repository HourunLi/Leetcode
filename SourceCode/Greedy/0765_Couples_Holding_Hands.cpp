#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
  int ret;
  int *position;
public:
  void swap(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    return;
  }
  int getPartner(int t) {
    int base = t/2;
    return t & 1 ? 2*base : 2*base + 1;
  }
  void dfs(vector<int>& row, int pos, int cnt) {
    if(!pos) {
      ret = min(cnt, ret);
      return;
    }
    int left = row[pos-2], right = row[pos-1];
    if(right/2 == left/2) {
      dfs(row, pos - 2, cnt);
      return;
    }
    int leftPartner = getPartner(left);
    swap(row[position[leftPartner]], row[pos-1]);
    swap(position[leftPartner], position[right]);
    dfs(row, pos - 2, cnt+1);
    swap(row[position[leftPartner]], right);
    swap(position[leftPartner], position[right]);
    return;
  }
  int minSwapsCouples(vector<int>& row) {
    int n = row.size();
    position = new int[n];
    for(int i = 0; i < n; i ++) {
      position[row[i]] = i;
    }
    ret = INT_MAX;
    dfs(row, n, 0);
    return ret == INT_MAX ? 0 : ret;
  }
};