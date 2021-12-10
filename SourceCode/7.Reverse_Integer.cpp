class Solution {
public:
    int reverse(int x) {
        bool flag = (x < 0);
        x = flag ? -x : x;
        int ret = 0;
        while(x) {
            ret = ret*10+ (x%10);
            x = x/10;
        }
        if(flag) return -ret;
        return ret;
    }
};