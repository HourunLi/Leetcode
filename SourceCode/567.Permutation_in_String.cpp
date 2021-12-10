#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(n > m) return false;
        int cnt[26], diff = 0;
        memset(cnt, 0 ,sizeof(int)*26);
        for(int i = 0; i < n; i++) {
            cnt[s1[i]-'a']--;
            cnt[s2[i]-'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(cnt[i])
                diff++;
        }

        for(int r = n; r < m; r++) {
            int ind1 = s2[r-n]-'a';
            cnt[ind1]--;
            if(cnt[ind1] == -1) diff++;
            if(cnt[ind1] == 0) diff--;

            int ind2 = s2[r]-'a';
            cnt[ind2]++;
            if(cnt[ind2] == 1) diff++;
            if(cnt[ind2] == 0) diff--;

            if(!diff) return true;           
        }
        return false;
    }
};

int main(){
    Solution s;
    string str1 = "adc";
    string str2 = "dcda";
    cout << s.checkInclusion(str1, str2);
    return 0;
}