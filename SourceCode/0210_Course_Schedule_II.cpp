/*DFS*/
class Solution {
private:
    vector<vector<int> > map;
    vector<int> visited;
    vector<int> ret;
public:
    //judge if there is a cycle;
    bool dfs(int ind) {
        if(visited[ind] == 2) return false;
        if(visited[ind] == 1) return true;
        visited[ind] = 1;
        for(auto &i : map[ind]) {
            if(dfs(i)) return true;
        }
        visited[ind] = 2;
        ret.emplace_back(ind);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map.resize(numCourses);
        visited.resize(numCourses, 0);
        for(auto &i : prerequisites) 
            map[i[1]].emplace_back(i[0]);
        for(int i = 0; i < numCourses; i++) {
            if(visited[i]) continue;
            if(dfs(i)) return {};
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

/*BFS*/
class Solution {
private:
    vector<vector<int> > map;
    vector<int> deg;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ret;
        map.resize(numCourses);
        deg.resize(numCourses, 0);
        queue<int> q;
        for(auto &i : prerequisites) {
            map[i[1]].emplace_back(i[0]);
            deg[i[0]]++;
        }
        for(int i = 0; i < numCourses; i++) 
            if(!deg[i]) 
                q.push(i);

        while(!q.empty()) {
            int head = q.front();
            q.pop();
            ret.emplace_back(head);
            for(auto &i : map[head]){
                deg[i]--;
                if(!deg[i])
                    q.push(i);
            }
        }
        if(ret.size() == numCourses)
            return ret;
        ret.resize(0);
        return ret;
    }
};