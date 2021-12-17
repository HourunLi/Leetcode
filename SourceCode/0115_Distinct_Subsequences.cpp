#include<bits/stdc++.h>
using namespace std;
/*solution1*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = t.size(), m = s.size();
        int **vis = (int**)calloc(n+1, sizeof(int*));
        for(int i = 0; i <= n; i++) 
            vis[i] = (int*) calloc(m+1, sizeof(int));
        
        for(int i = 0; i <= m; i++) 
            vis[0][i] = 1;
        for(int i = 1; i <=n; i++) {
            for(int j = 1; j <= m; j++) {
                if(t[i-1] == s[j-1]) {
                    if(INT_MAX - vis[i-1][j-1] < vis[i][j-1]) continue;
                    vis[i][j] = vis[i-1][j-1] + vis[i][j-1];
                }else{
                    vis[i][j] = vis[i][j-1];
                }
            }
        }
        return vis[n][m];
    }
};

/*solution2*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = t.size(), m = s.size();
        int *vis = (int*)calloc(m+1, sizeof(int*));
        for(int i = 0; i <=m; i++)
            vis[i]=1;
        for(int i = 1; i <=n; i++) {
            int tmp = vis[0];
            for(int j = 0; j <= m; j++) {
                int tmp2 = vis[j];
                if(!j) {
                    vis[j]=0;
                }else if(t[i-1] == s[j-1]) {
                    if(INT_MAX - tmp < vis[j-1]) continue;
                    vis[j] = tmp + vis[j-1];
                }else{
                    vis[j] = vis[j-1];
                }
                tmp = tmp2;
            }
        }
        return vis[m];
    }
};