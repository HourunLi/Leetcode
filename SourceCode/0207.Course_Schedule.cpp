/*DFS*/
class Solution {
private:
    vector<vector<int> > map;
    vector<int> visited;
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
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map.resize(numCourses);
        visited.resize(numCourses, 0);
        for(auto &i : prerequisites) 
            map[i[1]].emplace_back(i[0]);
        for(int i = 0; i < numCourses; i++) {
            if(visited[i]) continue;
            if(dfs(i)) return false;
        }
        return true;
    }
};

/*BFS*/
class Solution {
private:
    vector<vector<int> > map;
    vector<int> deg;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map.resize(numCourses);
        deg.resize(numCourses, 0);
        queue<int> q;
        int ret = 0;
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
            ret++;
            for(auto &i : map[head]){
                deg[i]--;
                if(!deg[i])
                    q.push(i);
            }
        }
        return (ret == numCourses);
    }
};