#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(auto i : stones)
            sum += i;
        
        int c = sum/2;
        int *vis = (int*) calloc((c+1), sizeof(int));

        int n = stones.size();
        for(int i = stones[0]; i <= c; i++) {
            vis[i] = stones[0];
        } 
        for(int i = 1; i < n; i++) {
            for(int j = c; j >=0; j--) {
                if(j >= stones[i])
                    vis[j] = max(vis[j], vis[j-stones[i]] + stones[i]);
            }
        }
        return sum - 2*vis[c];
    }
};

/*方法2*/
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(auto i : stones)
            sum += i;
        
        int c = sum/2;
        bool *vis = (bool*) calloc((c+1), sizeof(bool));

        int n = stones.size();
        if(stones[0] <= c)
        vis[0] =1;
        for(int i = 0; i < n; i++) {
            for(int j = c; j >=stones[i]; j--) {
                    vis[j] = vis[j] || vis[j-stones[i]];
            }
        }
        for(int i = c; i>=0; i--)
            if(vis[i])
                return sum - 2*i;
        return sum;
    }
};