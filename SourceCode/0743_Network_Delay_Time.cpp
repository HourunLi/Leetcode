/*Bellman Ford algorithm*/
class Solution {
private:
    vector<int> weight;
public:
    void relax(int u, int v, int w) {
        if(weight[u-1] == INT_MAX) return;
        weight[v-1] = weight[u-1] + w < weight[v-1] ? weight[u-1] + w : weight[v-1];
    } 
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        weight.resize(n, INT_MAX);
        weight[k-1] = 0;
        for(int i = 0; i < n-1; i++)
            for(auto &edge : times) 
                relax(edge[0], edge[1], edge[2]);
        
        int ret = -1;
        // for(auto &val : weight) 
        //     ret = val > ret ? val : ret;
        ret = *max_element(weight.begin(), weight.end());
        // if(ret == INT_MAX) return -1;
        // return ret;
        return ret == INT_MAX ? -1 : ret;
    }
};

/*Adjecent Matrix*/
class Solution {
private:
    vector<int> weight;
public:
    void relax(int u, int v, int w) {
        if(weight[u] == INT_MAX || w == INT_MAX) return;
        weight[v] = weight[u] + w < weight[v] ? weight[u] + w : weight[v];
    } 
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        weight.resize(n, INT_MAX);
        weight[k-1] = 0;
        vector<vector<int>> edges(n, vector<int>(n, INT_MAX));
        for (auto &edge : times) {
            int x = edge[0] - 1, y = edge[1] - 1;
            edges[x][y] = edge[2];
        }

        vector<int> used(n);
        weight[k-1] = 0;
        for(int i = 0; i < n; i++) {
            int from = -1;
            //确定距离里最近的点
            for(int j = 0; j < n; j++) {
                if(!used[j] && (from == -1 || weight[j] < weight[from])) {
                    from = j;
                }
            }
            used[from] = 1;
            for(int to = 0; to < n; to++) {
                if(!used[to]){
                    relax(from, to, edges[from][to]);
                }
            }
        }

        int ret = *max_element(weight.begin(), weight.end());
        // if(ret == INT_MAX) return -1;
        // return ret;
        return ret == INT_MAX ? -1 : ret;   
    }
};

/*Dijkstra*/

/*Dijkstra*/
class Solution {
private:
    vector<int> weight;
public:
    //if relax, return true, else false;
    bool relax(int u, int v, int w) {
        if(weight[u] == INT_MAX || w == INT_MAX) return false;
        if(weight[u] + w < weight[v]) {
            weight[v] =weight[u] + w;
            return true;
        }
        return false;
    } 

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >q;
        weight.resize(n, INT_MAX);
        weight[k-1] = 0;
        q.emplace(0, k-1);
        vector<vector<pair<int, int> > > edges(n);
        for(auto &item : times) 
            edges[item[0]-1].emplace_back(item[1]-1, item[2]);

        while(!q.empty()) {
            auto head = q.top();
            q.pop();
            if(weight[head.second] < head.first) continue;
            int ind = head.second;
            for(auto &i : edges[ind]){
                if(relax(head.second, i.first, i.second)) {
                    q.emplace(weight[i.first], i.first);
                }
            }
        }

        int ret = *max_element(weight.begin(), weight.end());
        return ret == INT_MAX ? -1 : ret; 
    }
};