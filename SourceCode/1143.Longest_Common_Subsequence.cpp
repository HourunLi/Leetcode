#include<bits/stdc++.h>
using namespace std;
/*普通实现*/
class Solution {
private:
    int **vis;
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vis = (int**) malloc(sizeof(int *) * (n+1));
        for(int i = 0; i <= n; i++) {
            vis[i] = (int *)calloc(m+1, sizeof(int));
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i-1] == text2[j-1]) {
                    vis[i][j] = vis[i-1][j-1] + 1;
                }else{
                    vis[i][j] = max(vis[i-1][j], vis[i][j-1]);
                }
            }
        }

        return vis[n][m];
    }
};
/*滚动数组*/
class Solution {
private:
    int *vis;
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vis = (int *)calloc(m+1, sizeof(int));

        for(int i = 1; i <= n; i++) {
            int tmp = 0;
            for(int j = 1; j <= m; j++) {
                int tmp2 = vis[j];
                if(text1[i-1] == text2[j-1]) {
                    vis[j] = tmp+1;
                }else{
                    vis[j] = max(vis[j-1], vis[j]);
                }
                tmp = tmp2;
                // if(text1[i-1] == text2[j-1]) {
                //     vis[i][j] = vis[i-1][j-1] + 1;
                // }else{
                //     vis[i][j] = max(vis[i-1][j], vis[i][j-1]);
                // }
            }
        }
        return vis[m];
    }
};