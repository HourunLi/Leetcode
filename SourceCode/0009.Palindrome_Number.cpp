#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        char buffer[20];
        sprintf(buffer, "%d", x);
        int index = 0;
        while(x) {
          int tail = x % 10;
          x /= 10;
          if(buffer[index]-'0' != tail)
            return false;
          index++;
        }
        return true;
    }
};