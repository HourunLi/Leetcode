#include<bits/stdc++.h>
using namespace std;
class NumArray {
private:
  int *tree;
  int n;
public:
  NumArray(vector<int>& nums) {
    n = nums.size();
    tree = new int[2*n]();
    for(int i = n; i < 2*n; i++) {
      tree[i] = nums[i-n];
    }
    for(int i = n-1; i > 0; i--) {
      tree[i] = tree[i*2] + tree[i*2+1];
    }
  }
  
  void update(int index, int val) {
    int pos = index + n;
    tree[pos] = val;
    while(pos) {
      int l = pos, r = pos;
      if(pos & 1) {
        l = pos-1;
      }else{
        r = pos+1;
      }
      pos /= 2;
      tree[pos] = tree[l] + tree[r];
      
    }
    return;
  }
  
  int sumRange(int left, int right) {
    int l = left + n, r = right + n;
    int sum = 0;
    while(l <= r) {
      if(l & 1) {
        sum += tree[l];
        l++;
      }

      if(!(r & 1)) {
        sum += tree[r];
        r--;
      }
      l /= 2;
      r /= 2;
    }
    return sum;
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */