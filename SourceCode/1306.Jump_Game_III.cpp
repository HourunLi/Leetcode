/*BFS*/
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int size = arr.size();
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int head = q.front(), value = arr[head];
            q.pop();
            if(!value) return true;
            arr[head] = -1;
            //push left pos
            if(head-value >= 0   && arr[head-value] != -1) q.push(head - value);
            //push right pos
            if(head+value < size && arr[head+value] != -1) q.push(head + value);
        }    
        return false;
    }
};
/*DFS*/
class Solution {
public:
    bool dfs(vector<int>& arr, int start, int size){
        int value = arr[start];
        bool flag=false;
        if (!value) return true;
        arr[start] = -1;
        if(start-value >= 0 && arr[start-value] != -1) {
            flag = dfs(arr, start-value, size);
        } 
        if(flag) return true;
        if(start+value < size && arr[start+value] != -1) return dfs(arr, start+value, size);
        arr[start] = value;
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        int size = arr.size();
        return dfs(arr, start, size);
    }
};