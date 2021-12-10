// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int l = 1, r = n;
        int pos;
        while(l <= r) {
            int mid = (l+r)>>1;
            if(isBadVersion(mid)) {
                pos = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return pos;
    }
};