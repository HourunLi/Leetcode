#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int *container = new int[1000005]();
        int l = 0, r = 0;
        int ret = INT_MAX;
        int n = cards.size();
        bool flag = false;
        for(r = 1; r <= n; r++) {
            int card_r = cards[r-1];
            container[card_r]++;
            if(container[card_r] == 2) {
                while(l < r) {
                    int card_l = cards[l++]; 
                    container[card_l]--; 
                    if(container[card_l] == 1) {
                        ret = min(ret, r-l+1);
                        break;
                    }
                }

            }
        }
        return ret == INT_MAX ? -1 : ret;
    }
};