#include<bits/stdc++.h>
using namespace std;
// #define DEBUG
class Solution {
public:
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int m = nums1.size(), n = nums2.size();
    int *ret = NULL;
    if(m > n) {
      return maxNumber(nums2, nums1, k);
    }
    // make sure that m is smaller than or equal to m
    int begin = max(0, k-n);
    int end = min(m, k);
    for(int i = begin; i <= end; i++) {
      int *maxSub1 = maxSubsequence(nums1, i);
      int *maxSub2 = maxSubsequence(nums2, k - i);
      #ifdef DEBUG
      cout << i << "---------------------------\n";
      dump(maxSub1, i);
      dump(maxSub2, k-i);
      cout << "-------------------------\n";
      #endif
      int *maxSub = merge(maxSub1, i, maxSub2, k-i);
      ret = comapreAndSwap(ret, maxSub, k);
    }
    return vector<int>(ret, ret + k);
  }
  void dump(int *sub, int size) {
    for(int i = 0; i < size; i++) {
      cout << sub[i] << " ";
    }
    cout << endl;
    return;
  }
  int *maxSubsequence(vector<int> &nums, int k) {
    int n = nums.size();
    int discard = n-k;
    int *ret = (int *)malloc(k * sizeof(int));
    int top = 0;
    for(auto i : nums) {
      while(top > 0 && ret[top-1] < i && discard > 0) {
        discard--;
        top--;
      }

      if(top < k) {
        ret[top++] = i;
      }else{
        discard--;
      }
    }
    return ret;
  }

  int *merge(int *sub1, int size1, int *sub2, int size2) {
    int idx1 = 0, idx2 = 0;
    int *ret = (int *)malloc((size1 + size2) * sizeof(int));
    for(int i = 0; i < size1 + size2; i++) {
      if(compare(sub1, size1, idx1, sub2, size2, idx2)) {
        ret[i] = sub1[idx1++];
      }else{
        ret[i] = sub2[idx2++];
      }
    }
    free(sub1);
    free(sub2);
    return ret;
  }

  int *comapreAndSwap(int *ret, int *sub, int k) {
    if(compare(ret, k, 0, sub, k, 0)) {
      free(sub);
      return ret;
    }else{
      free(ret);
      return sub;
    }
  }

  int compare(int *sub1, int size1, int idx1, int *sub2, int size2, int idx2) {
    if(size1 == idx1 || sub1 == NULL) {
      return 0;
    }else if(size2 == idx2) {
      return 1;
    }

    if(sub1[idx1] > sub2[idx2]) {
      return 1;
    }else if(sub1[idx1] < sub2[idx2]){
      return 0;
    }else{
      return compare(sub1, size1, idx1+1, sub2, size2, idx2+1);
    }
  }
};
