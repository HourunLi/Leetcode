#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int *lastMerge, *ans;
public:
    long long appealSum(string s) {
        int n = s.size();
        long long int ret = 1;
        ans = new int[n]();
        lastMerge = new int[26]();
        memset(lastMerge, -1, sizeof(int) * 26);
        ans[0] = 1;
        lastMerge[s[0]-'a'] = 0;
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i-1] + i - lastMerge[s[i]-'a'];
            lastMerge[s[i]-'a'] = i;
            ret += ans[i];
        }
        return ret;
    }
};

// int main() {
//     Solution s;
//     cout << s.appealSum("ktttt");
//     return 0;
// }