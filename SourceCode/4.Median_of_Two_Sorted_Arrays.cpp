#include<bits/stdc++.h>
using namespace std;
/*log(m+n),utilize the attribute of median*/
/*
int getKElement(int *nums1, int offset1, int nums1Size, int *nums2, int offset2, int nums2Size, int k) {
    if(offset1 == nums1Size) {
        // cout << "nums2[" << k-1+offset2 << "]\n";
        return nums2[k-1+offset2];
    }
        
    if(offset2 == nums2Size) {
        // cout << "nums1: " << k-1+offset1 << "]\n";
        return nums1[k-1+offset1];
    }
    if(k == 1) {
        if(nums1[offset1] <= nums2[offset2]){
            // cout << "nums1[" << offset1 << "]\n";
            return  nums1[offset1];           
        }else{
            // cout << "nums2[" << offset2 << "]\n";
            return  nums2[offset2];               
        }
    }
    if(k/2-1+ offset1 >= nums1Size) {
        if(nums1[nums1Size-1] <= nums2[k/2-1+ offset2])
            return getKElement(nums1, nums1Size, nums1Size, nums2, offset2, nums2Size, k-(nums1Size-offset1));
        else
            return getKElement(nums1, offset1, nums1Size, nums2, offset2 + k/2, nums2Size, k-k/2);
    }else if (k/2-1+ offset2 >= nums2Size){
        if(nums2[nums2Size-1] <= nums1[k/2-1+ offset1])
            return getKElement(nums1, offset1, nums1Size, nums2, nums2Size, nums2Size, k-(nums2Size-offset2));
        else
            return getKElement(nums1, offset1 + k/2, nums1Size, nums2, offset2, nums2Size, k-k/2);   
    }else if(nums1[k/2-1+ offset1] <= nums2[k/2-1+ offset2]) {
        return getKElement(nums1, offset1 + k/2, nums1Size, nums2, offset2, nums2Size, k-k/2);
    }else{
        return getKElement(nums1, offset1, nums1Size, nums2, offset2 + k/2, nums2Size, k-k/2); 
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int size = (nums1Size + nums2Size);
    if(size&1) {
        return getKElement(nums1, 0, nums1Size, nums2, 0, nums2Size, (size+1)/2);
    }else{
        return (getKElement(nums1, 0, nums1Size, nums2, 0, nums2Size, size/2) + getKElement(nums1, 0, nums1Size, nums2, 0, nums2Size, size/2+1))/2.0;
    }
}
*/

/*log(min(m,n)), optimized, binary search*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if(len1 > len2) return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = len1;
        int lmax, rmin;
        while(l <= r) {
            int i = (l+r) / 2, j = (len1+len2+1) / 2 - i;
            int lmax1 = i == 0 ? INT_MIN : nums1[i-1];
            int lmax2 = j == 0 ? INT_MIN : nums2[j-1];
            int rmin1 = i == len1 ? INT_MAX : nums1[i];
            int rmin2 = j == len2 ? INT_MAX : nums2[j];

            if(lmax1 <= rmin2) {
                lmax = lmax1 > lmax2 ? lmax1 : lmax2;
                rmin = rmin1 < rmin2 ? rmin1 : rmin2;
                l = i + 1;
            }else{
                r = i - 1;
            }
        } 
        if((len1+len2)&1) return lmax;
        else return (lmax+rmin)/2.0;
    }
};

int main(){
    int A[] = {4};
    int B[] = {1,2,3,5,6};
    cout << findMedianSortedArrays(A, 1, B, 5);
    return 0;
}