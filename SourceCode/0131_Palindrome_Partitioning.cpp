/*method 1直接调用，形式比较优美*/
#include<bits/stdc++.h>
using namespace std;
// int flag[20][20];
// class Solution {
// public:
//     bool isPan(int l, int r, string &str) {
//         if(l > r) return 1;
//         if(flag[l][r]) return flag[l][r] + 1; 
//         if(str[l] == str[r]) {
//             flag[l][r] = isPan(++l, --r, str);
//         }else{
//             flag[l][r] = -1;
//         }
//         return flag[l][r] + 1; 
//     }
//     vector<vector<string>> partition(string s) {
//         int n = s.size();
//         // cout << n <<endl;
//         if(n == 0) {
//             return {{}};
//         }
//         if(n == 1) {
//             return {{s}};
//         }
//         vector<vector<string>> ret;
//         for(int i = n-1; i >= 0; i--) {
//             string tmp = s.substr(i);
//             if(isPan(i, n-1, s)) {
//                 vector<vector<string>> vec = partition(s.substr(0, i));
//                 for(auto &i : vec) {
//                     i.push_back(tmp);
//                     ret.push_back(i);
//                 }
//             }
//         }
//         return ret;
//     }
// };


/*优化版本，比较快*/
/*注意需要一个数组来记录回文字符，否则其实会导致许多重复计算*/
class Solution {
private:
    bool flag[20][20];
    vector<vector<string>> ret;
    vector<string> tmp;
public:
    void dfs(string &s, int k, int &size) {
        // cout << k << endl;
        if(k == size) {
            ret.push_back(tmp);
            return;
        }
        for(int i = k; i < size; i++) {
            if(flag[k][i]) {
                tmp.push_back(s.substr(k, i-k+1));
                dfs(s, i+1, size);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        memset(flag, 1, sizeof(bool) *400);
        int n = s.size();
        // cout << "here\n";
        for(int i = n-1; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                flag[i][j] = (s[i] == s[j]) && flag[i+1][j-1];
            }
        }
        // cout << "here\n";
        dfs(s, 0, n);
        return ret;
    }
};

int main() {
    Solution s;
    vector<vector<string>> ret = s.partition("bba");
    for(auto i : ret) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    // system("pause");
    cout << "over\n";
    return 0;
}