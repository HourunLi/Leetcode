#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long mypower(int x, int y) {
        long long ret =1;
        for(int i = 0 ; i <y; i++) {
            ret *= x;
        }
        return ret;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int N = digits.size();
        int bits = log10(n);
        int *dp = new int[bits+2]();
        if(N == 1) {
            dp[0] += bits; 
        }else{
            dp[0] += ((mypower(N, bits)-1) / (N-1)) * N;
        }

        dp[bits+1] = 1; 
        string x = to_string(n);
        for(int i = bits; i >=0; i--) {
            int x_i = x[i]-'0';
            for(auto j : digits){
                int j_i = atoi(j.c_str());
                if(x_i > j_i) {
                    dp[i] += mypower(N, bits-i);
                }else if(x_i == j_i) {
                    dp[i] += dp[i+1];
                }
            }
        }
        //技巧：把N转换为字符串，那么就可以直接处理开头
        //字符串和数字的最大差别就是处理的顺序不同。

        return dp[0];
    }
};