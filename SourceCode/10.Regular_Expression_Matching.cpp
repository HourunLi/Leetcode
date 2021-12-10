#include<bits/stdc++.h>
/*法1*/
/*
class Solution {
private:
    int **vis;
public:
    bool getAns(string s, int l, string p, int r) {
        if(vis[l][r] != -1) return vis[l][r];
        if(l < 0) return 0;
        if(p[r-1] == '.') {
            if(!l) return 0;
            vis[l][r] = getAns(s, l-1, p, r-1);
        }else if(p[r-1] == '*') {
            if(l == 0 || s[l-1] != p[r-2] && p[r-2] != '.') {
                vis[l][r] =  getAns(s, l, p, r-2);
            }else{
                vis[l][r] =  getAns(s, l-1, p, r) | getAns(s, l, p, r-2);
            }
        }else{
            if(l == 0 || s[l-1] != p[r-1]) {
                vis[l][r] =0;         
            }else{
                vis[l][r] =  getAns(s, l-1, p, r-1);
            }
        }
        return vis[l][r];
    }
    bool isMatch(string s, string p) {
        int len1 = s.size()+1;
        int len2 = p.size()+1;
        vis = (int **)malloc(sizeof(int *)*len1);
        for(int i = 0; i < len1; i++) {
            vis[i] = (int *)malloc(sizeof(int)*len2);
            for(int j = 0; j < len2; j++) {
                vis[i][j] = -1;
            }
        } 
        vis[0][0]=1;
        for(int i = 1; i <len1; i++) vis[i][0]=0;
        return getAns(s, len1-1, p, len2-1);
    }
};
*/

class Solution {
private:
    int **vis;
public:
    bool isMatch(string s, string p) {
        int len1 = s.size();
        int len2 = p.size();
        vis = (int **)malloc(sizeof(int*)*(len1+1));
        for(int i = 0; i <= len1; i++) {
            vis[i] = (int *)calloc(len2+1, sizeof(int));
        }
        auto match = [&](int i, int j) {
            if(i == 0) return false;
            if(p[j-1] == '.') return true;
            return s[i-1] == p[j-1];
        };

        vis[0][0] = 1;
        for(int i = 0; i <= len1; i++) {
            for(int j = 1; j <= len2; j++) {
                if(p[j-1] == '*') {
                    if(match(i, j-1)) {
                        vis[i][j] |= vis[i-1][j];
                    }
                    vis[i][j] |= vis[i][j-2];
                }else if(match(i, j)){
                    vis[i][j] |= vis[i-1][j-1];
                }
            }
        }
        return vis[len1][len2];
    }
};