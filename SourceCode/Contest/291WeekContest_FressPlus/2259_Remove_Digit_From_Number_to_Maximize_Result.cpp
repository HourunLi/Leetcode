#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.length();
        string ret = "0", tmp;
        for(int i = 0; i < n; i++) {
            if(number[i] == digit) {
                tmp = number;
                tmp.replace(i, 1, "");
                if(ret < tmp) {
                    ret = tmp;
                }
            }
        }
        return ret;
    }
};