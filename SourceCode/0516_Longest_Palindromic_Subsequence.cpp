#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int ** vis;
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vis = (int**) malloc(sizeof(int *) * (n));
        for(int i = 0; i < n; i++) {
            vis[i] = (int *)calloc(n, sizeof(int));
        }
        
        auto get = [&](int i, int j) {
            if(i == j+2) return -1;
            else if(i == j + 1) return 0;
            else return vis[i][j];
        };

        for(int i = n-1; i >=0; i--) {
            for(int j = i; j < n; j++) {
                if(s[i] == s[j])
                    vis[i][j] = get(i+1, j-1) + 2;
                else 
                    vis[i][j] = max(get(i+1, j), get(i, j-1));
            }   
        }
        return vis[0][n-1];
    }
    
};