/*
class Solution {
public:
    vector<int> div(const vector<int>& s) {
        int flag = 0, cnt= 0, size = s.size();
        vector<int> ret;
        if(s[0]==1) {
            cnt = 1;
            flag = 1;
        }
        while(cnt < size) {
            int c = s[cnt++];
            int tem = (flag*10+c);
            flag = tem&1;
            ret.push_back(tem/2);
        }
        return ret;
    }
    int superPow(int a, vector<int> b) {
        if(b.size() == 1 && b[0] == 0) return 1;
        if(b.size() == 1 && b[0] == 1) return a%1337;
        int t = superPow(a, div(b));
        if(b.back()&1) return (((t*t)%1337)*(a%1337))%1337;
        else return t*t%1337;
    }
};

*/
/*optimize*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int>& div(vector<int>& s) {
        int flag = 0;
        if(s[0]==1) {
            flag = 1;
            s.erase(s.begin());
        }
        for(int& c : s){
            int tem = (flag*10+c);
            flag = tem&1;
            c = tem/2;
        }
        return s;
    }
    int superPow(int a, vector<int>& b) {
        if(b.size() == 1 && b[0] == 0) return 1;
        if(b.size() == 1 && b[0] == 1) return a%1337;
        bool flag = b.back()&1;
        int t = superPow(a, div(b));
        if(flag) return (((t*t)%1337)*(a%1337))%1337;
        else return (t*t)%1337;
    }
};


int main() {
    Solution solution;
    int a = 2147483647;
    vector<int> b = {2,0,0};
    cout << solution.superPow(a, b);
    return 0;
}