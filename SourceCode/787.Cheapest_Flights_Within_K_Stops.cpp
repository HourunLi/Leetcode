class Solution {
public:
    bool relax(vector<int> &ans, vector<int> &tem, int &from, int &to, int &weight) {
        int res = ans[from] == INT_MAX ? ans[to] : ans[from] + weight;
        res = res < ans[to] ? res : ans[to];
        if(res == INT_MAX) return false;
        if(res < tem[to]) {
            tem[to] = res;
            return true;
        }
        return false;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> ans(n, INT_MAX);
        ans[src] = 0;
        for(int t = 0; t < k+1; t++) {
            vector<int> tem(n, INT_MAX);
            for(auto &item : flights) {
                int from = item[0], to = item[1], weight = item[2];
                relax(ans, tem, from, to, weight);
            }
            ans = move(tem);
        }
        return ans[dst] == INT_MAX ? -1 : ans[dst];
    }
};