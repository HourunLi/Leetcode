#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size(), m = nums2.size();
    int begin = max(k-m, 0), end = min(n, k);
    vector<int> ret;

    for(int i = begin; i <= end; i++) {
      vector<int> maxSubSequence1 = maxSubSequence(nums1, i);
      vector<int> maxSubSequence2 = maxSubSequence(nums2, k-i);
      vector<int> mergeSeq = merge(maxSubSequence1, maxSubSequence2);
      if(compare(mergeSeq, 0, ret, 0)) {
        ret = mergeSeq;
      }
    } 
    return ret;
  }
  vector<int> maxSubSequence(vector<int>& nums, int k) {
    int len = nums.size();
    int residual = len-k, ele = 0;
    vector<int> ret(k, 0);
    for(int i = 0; i < len; i++) {
      while(ele && ret[ele-1] < nums[i] && residual) {
        ele--;
        residual--;
      }

      if(ele < k) {
        ret[ele++] = nums[i];
      }else{
        residual--;
      }
    }
    return ret;
  }

  bool compare(vector<int>& nums1, int ind1, vector<int>&nums2, int ind2) {
    int n = nums1.size(), m = nums2.size();
    if(n == ind1) {
      return false;
    }else if(m == ind2) {
      return true;
    }

    if(nums1[ind1] == nums2[ind2]) {
      return compare(nums1, ind1+1, nums2, ind2+1);
    }
    return nums1[ind1] > nums2[ind2];
  }

  vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    if(!n || !m) {
      return !n ? nums2 : nums1;
    }
    vector<int> ret(n+m);
    int ind1 = 0, ind2 = 0;
    for(int i = 0; i < n + m; i++) {
      if(compare(nums1, ind1, nums2, ind2)) {
        ret[i] = nums1[ind1++];
      }else{
        ret[i] = nums2[ind2++];
      }
    }
    return ret;
  }

};