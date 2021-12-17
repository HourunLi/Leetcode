class Solution {
private:
    vector<int> parent;
    vector<int> rank;
public:
    struct EDGE{
        int len, x, y;
        EDGE(int len, int x, int y) : len(len), x(x), y(y) {

        }
    };

    int manhattan(vector<int> &a, vector<int> &b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    static bool cmp(const EDGE &a, const EDGE &b) {
        return a.len < b.len;
    }

    int Find(int index) {
        return index == parent[index] ? index : parent[index] = Find(parent[index]);
    }

    void Union(int x, int y) {
        if(rank[x] > rank[y]) 
            swap(x, y);
        parent[Find(x)] = parent[Find(y)];
        rank[Find(y)] += rank[Find(x)];
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<EDGE> edges;
        int n = points.size(), ans = 0;
        
        parent.resize(n);
        rank.resize(n,1);
        for(int i = 0; i < n; i++) 
            parent[i] = i;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                //调用构造函数
                edges.emplace_back(manhattan(points[i], points[j]), i, j);
            }
        }
        sort(edges.begin(), edges.end(), cmp);
        int size = edges.size(), cnt = 0;
        for(int k = 0; k < size; k++) {
            EDGE &t = edges[k];
            if(Find(t.x) == Find(t.y))
                continue;
            Union(t.x, t.y);
            cnt++;
            Union(t.x, t.y);
            ans += t.len;
            if(cnt == size)
                break;
        }
        return ans;
    }
};