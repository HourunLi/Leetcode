/*bisearch*/
class Solution {
public:
    int mySqrt(int x) {
        int ret;
        int l = 0, r = 32768;
        while(l <= r) {
            int mid = (l+r)/2;
            int powMid = mid*mid;
            if(powMid == x) return mid;
            else if(powMid < x){
                l = mid+1;
                ret = mid;
            }else {
                r = mid-1;
            }
        }
        return ret;
    }
};

/*Newton iteration*/
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        double C = x, x0 = x;
        while (true) {
            double xi = 0.5 * (x0 + C / x0);
            if (fabs(x0 - xi) < 1e-7) {
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }
};

#include<bits/stdc++.h>
using namespace std;
int main() {

}