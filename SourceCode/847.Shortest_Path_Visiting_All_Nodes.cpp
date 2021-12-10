#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX/2
class Solution {
public:
    int dfs(vector<int>& state, vector<vector<int>>& graph, int &n, map<vector<int>, int> &memo) {
        map<vector<int>, int>::iterator it = memo.find(state);
        if(it != memo.end()) {
            return it->second;
        }
        for(auto i : state) {
            cout << i << " ";
        }
        cout << endl;
        memo[state] = INF;
        int ret = INF;
        int pos = state[n];
        for(auto i : graph[pos]) {
            if(i == pos) 
                continue;
            int flag = state[i];
            state[i] = 1;
            state[n] = i;
            ret = min(ret, dfs(state, graph, n, memo)+1);
            state[i] = flag;
            state[n] = pos;
        }
        memo[state] = ret;
        return ret;
    }
    void initialMap(map<vector<int>, int> &memo, int &n) {
        vector<int> state(n+1, 1);
        for(int i = 0; i < n; i++) {
            state[n] = i;
            memo[state] = 0;
        }
        return;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n+1, 0);
        int ret = INF;
        for(int i = 0; i < n; i++) {
            map<vector<int>, int> memo;
            initialMap(memo, n);
            state[i] = 1;
            state[n] = i;
            int tmp = dfs(state, graph, n, memo);
            ret = min(ret, tmp);
            cout << i << ": " << tmp << endl; 
            state[i] = 0;
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<vector<int>> graph = {{2,3,4,8},{8},{0},{0,8},{0,5,6},{4,7},{4},{5},{0,3,1}};
    cout << s.shortestPathLength(graph);
}
