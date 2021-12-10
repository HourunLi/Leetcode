/*original method*/
int lengthOfLongestSubstring(char * s){
    int ans = 0;
    int size = strlen(s);
    for(int l = 0; l < size; l ++) {
        int hash[200] = {0};
        int tem = 0;
        for(int r = l; r < size; r++) {
            if(!hash[s[r]]) {
                hash[s[r]] = 1;
                tem++;
            }else{
                break;
            }
        }
        if(tem > ans) ans = tem;
    }
    return ans;
}

/*optimized method*/
int lengthOfLongestSubstring(char * s){
    int ans = 0, r = 0, l = 0;
    int size = strlen(s);
    int hash[200] = {0};
    for(; l < size; l ++) {
        if(l) {
            hash[s[l-1]] = 0;
        }
        while(r < size && !hash[s[r]]) {
            hash[s[r]] = 1;
            r++;
        }
        ans = ans > (r-l) ? ans : (r-l);
    }
    return ans;
}

/*10.5二刷*/
int max(int a, int b) {
    return a < b ? b : a;
}
int lengthOfLongestSubstring(char * s){
    int l = 0, r = 0;
    int n = strlen(s);
    int ret = 0, maxmium = 0;
    bool hash[256];
    memset(hash, 0, sizeof(bool)*256);
    for(; l < n; l++){
        if(l) {
            hash[s[l-1]] = 0;
        }
        while(r < n && !hash[s[r]]) {
            hash[s[r++]] = 1;
        }
        ret = max(ret, r-l);
    }
    return ret;
}