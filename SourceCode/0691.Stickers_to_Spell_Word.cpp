#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX/2
class Solution {
public:
    map<string, int> memo;
    int **pool;
    int dfs(int* needs, int &n) {
        // for(auto i:needs){
        //     cout << i << " ";
        // }
        // cout << endl;
        string str = vector2string(needs);
        if(memo.find(str) != memo.end()) 
            return memo[str];

        int minNum = INF;
        memo[str] = INF;
        int curNeeds[26] = {0};
        for(int i = 0; i < n; i++) {
            bool flag = false;
            for(int j = 0; j < 26; j++) {
                if(!needs[j]) continue;
                if(!pool[i][j]) 
                    flag = true;
                break;
            }
            if(flag) continue;
            for(int j = 0; j < 26; j++) {
                curNeeds[j] = needs[j] - pool[i][j];
                curNeeds[j] = curNeeds[j] <= 0 ? 0 : curNeeds[j];
            }
            minNum = min(minNum, dfs(curNeeds, n)+1);
        }
        memo[str] = minNum;
        return minNum;
    }
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        pool = (int**)calloc(n, sizeof(int*));
        for(int i = 0; i < n; i++) {
            string str = stickers[i];
            pool[i] = (int*) calloc(26, sizeof(int));
            for(auto ch : str) {
                pool[i][ch-'a']++;
            } 
            // for(int j = 0; j < 26; j++){
            //     cout << pool[i][j] << " ";
            // }
            // cout << endl;
        }
        int needs[26] = {0};
        memo[string(26,'a')] = 0;
        // cout << memo[vector<int> {0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0}] << endl;
        for(auto ch : target) {
            // if(ch)
            needs[ch-'a']++;
        }

        for(int j = 0; j < 26; j++) {
            if(!needs[j]) continue;
            bool tmp = false;
            for(int i = 0; i < n; i++) {
                tmp |= pool[i][j];
            }
            if(!tmp) return -1;
        }
        // cout << "start\n";
        int res = dfs(needs, n);
        return res >= INF ? -1 : res;
    }

    inline string vector2string(int* vec) {
        string str(26,'a');
        for(int i = 0; i < 26; i++) {
            str[i] += vec[i];
        }
        return str;
    }
};

// int main() {
//     Solution s;
//     vector<string> vec{"indicate","why","finger","star","unit","board","sister",
//         "danger","deal","bit","phrase","caught","if","other","water","huge","general",
//         "read","gold","shall","master","men","lay","party","grow","view","if","pull",
//         "together","head","thank","street","natural","pull","raise","cost","spoke",
//         "race","new","race","liquid","me","please","clear","could","reply","often","huge","old","nor"};
    
//     cout << s.minStickers(vec, "fhhfiyfdcwbycma");
//     return 0;
// }