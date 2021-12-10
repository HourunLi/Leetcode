/*recursive*/
int edit(char *word1, char *word2, int **ans, int l, int r) {
    if(l == -1) return r+1;
    if(r == -1) return l+1;
    if(ans[l][r] != -1) return ans[l][r];
    if(word1[l] == word2[r]) {
        ans[l][r] = edit(word1, word2, ans, l-1, r-1);
    } else{
        int k1 = edit(word1, word2, ans, l-1, r);
        int k2 = edit(word1, word2, ans, l, r-1);
        int k3 = edit(word1, word2, ans, l-1, r-1);
        int min1 = k1 < k2 ? k1 : k2;
        int min2 = min1 < k3 ? min1 : k3;
        ans[l][r] = min2+1;
    }
    return ans[l][r];
}
int minDistance(char * word1, char * word2){
    int n = strlen(word1), m = strlen(word2);
    if(!n) return m;
    if(!m) return n;
    int **ans = (int **)malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++) {
        ans[i] = (int *)malloc(sizeof(int) * m);
        memset(ans[i], -1, sizeof(int)*m);
    }
    edit(word1, word2, ans, n-1, m-1);
    return ans[n-1][m-1];
}

/*iterate*/
int minDistance(char * word1, char * word2) {
    int n = strlen(word1), m = strlen(word2);
    if(!n) return m;
    if(!m) return n;
    int **ans = (int **)malloc(sizeof(int*) * (n+1));
    for(int i = 0; i <= n; i++) {
        ans[i] = (int *)malloc(sizeof(int) * (m+1));
    }
    for(int i = 0; i <= n; i++) {
        ans[i][0] = i;
    }
    for(int j = 0; j <= m; j++) {
        ans[0][j] = j;
    }
    for(int i = 1; i <= n ; i++) {
        for(int j = 1; j <= m; j++){
            int l = ans[i][j-1];
            int a = ans[i-1][j];
            int la = ans[i-1][j-1];
            int tem = l < a ? l : a;
            int min = tem < la ? tem : la;
            if(word1[i-1] == word2[j-1]) 
                ans[i][j] = la;
            else
                ans[i][j] = min + 1;
        }
    }
    return ans[n][m];
}
/*

    for(int i = 0; i<= n; i++) 
        ans[n][i] = i;
    for(int j  0; j <= m; j++)
        ans[0][j] = j;
*/