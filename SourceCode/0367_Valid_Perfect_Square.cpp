class Solution {
public:
    bool isPerfectSquare(int num) {
        double x_ = num, x;
        while(true) {
            x = (x_+num/x_)/2.0;
            if(fabs(x-x_) < 1e-6) break;
            x_ = x;
        }
        return int(x)*int(x) == num;
    }
};