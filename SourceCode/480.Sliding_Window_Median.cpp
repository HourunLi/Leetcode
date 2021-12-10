class Solution {
priority_queue<int, vector<int>, less<int> > q_min;
priority_queue<int, vector<int>, greater<int> > q_max;
map<int, int> map;
public:
    template<typename T>
    void trim(T &q) {
        int top = q.top();
        while(map.find(top) != map.end() && map[top] > 0) {
            map[top]--;
            q.pop();
            top = q.top();
        }
    }
    double getMid(int k) {
        if(k & 1) {
            return q_min.top();
        }else{
            return (q_min.top()*1.0+q_max.top()) / 2.0;
        }
    }
    void kick(int k, int val) {
        if(k&1) {
            if(val == q_min.top()) {
                q_min.pop();
                trim(q_min);
            }else if(val < q_min.top()) {
                map.find(val) == map.end() ? map[val] = 1 : map[val]++;
            }else{
                if(val == q_max.top()) {
                    q_max.pop();
                    trim(q_max);
                }else{
                    map.find(val) == map.end() ? map[val] = 1 : map[val]++;
                }
                q_max.push(q_min.top());
                q_min.pop();
                trim(q_min);
            }
        }else{
            if(val == q_max.top()) {
                q_max.pop();
                trim(q_max);
            }else if(val > q_max.top()) {
                map.find(val) == map.end() ? map[val] = 1 : map[val]++;
            }else{
                if(val == q_min.top()) {
                    q_min.pop();
                    trim(q_min);
                }else{
                    map.find(val) == map.end() ? map[val] = 1 : map[val]++;
                }
                q_min.push(q_max.top());
                q_max.pop();   
                trim(q_max);            
            }
        }
    }
    void add(int k, int val) {
        if(!k){
            q_min.push(val);
            return;
        }
        if(k & 1) {
            if(val <= q_min.top()) {
                q_max.push(q_min.top());
                q_min.pop();
                trim(q_min);
                q_min.push(val);
            }else {
                q_max.push(val);
            }
        }else{
            if(val <= q_max.top()) {
                q_min.push(val);
            }else{
                q_min.push(q_max.top());
                q_max.pop();
                trim(q_max);  
                q_max.push(val);
            }
        }
        return;
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ret;
        for(int i = 0; i < k; i++) {
            add(i, nums[i]);
        }
        ret.push_back(getMid(k));

        int n = nums.size();
        for(int i = 0; i < n- k; i++) {
            kick(k, nums[i]);
            add(k-1, nums[i+k]);
            ret.push_back(getMid(k));
        }
        return ret;
    }
};


/* brute method 没有考虑是否需要减枝
class Solution {
priority_queue<int, vector<int>, less<int> > q_min;
priority_queue<int, vector<int>, greater<int> > q_max;
map<int, int> map;
public:
    void trim(priority_queue<int, vector<int>, greater<int> > &q) {
        int top = q.top();
        while(map.find(top) != map.end() && map[top] > 0) {
            map[top]--;
            q.pop();
            top = q.top();
        }
    }
    void trim(priority_queue<int, vector<int>, less<int> > &q) {
        int top = q.top();
        while(map.find(top) != map.end() && map[top] > 0) {
            map[top]--;
            q.pop();
            top = q.top();
        }
    }
    int mytop(priority_queue<int, vector<int>, less<int> > &q) {
        trim(q);
        return q.top();
    }
    int mytop(priority_queue<int, vector<int>, greater<int> > &q) {
        trim(q);
        return q.top();
    }
    double getMid(int k) {
        if(k & 1) {
            return mytop(q_min);
        }else{
            return (mytop(q_min)*1.0+mytop(q_max)) / 2.0;
        }
    }
    void kick(int k, int val) {
        if(k&1) {
            if(val == mytop(q_min)) {
                q_min.pop();
            }else if(val < mytop(q_min)) {
                map.find(val) == map.end() ? map[val] = 1 : map[val]++;
            }else{
                if(val == mytop(q_max)) {
                    q_max.pop();
                }else{
                    map.find(val) == map.end() ? map[val] = 1 : map[val]++;
                }
                q_max.push(mytop(q_min));
                q_min.pop();
            }
        }else{
            if(val == mytop(q_max)) {
                q_max.pop();
            }else if(val > mytop(q_max)) {
                map.find(val) == map.end() ? map[val] = 1 : map[val]++;
            }else{
                if(val == mytop(q_min)) {
                    q_min.pop();
                }else{
                    map.find(val) == map.end() ? map[val] = 1 : map[val]++;
                }
                q_min.push(mytop(q_max));
                q_max.pop();               
            }
        }
    }
    void add(int k, int val) {
        if(!k){
            q_min.push(val);
            return;
        }
        if(k & 1) {
            if(val <= mytop(q_min)) {
                q_max.push(mytop(q_min));
                q_min.pop();
                q_min.push(val);
            }else {
                q_max.push(val);
            }
        }else{
            if(val <= mytop(q_max)) {
                q_min.push(val);
            }else{
                q_min.push(mytop(q_max));
                q_max.pop();
                q_max.push(val);
            }
        }
        return;
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ret;
        for(int i = 0; i < k; i++) {
            add(i, nums[i]);
        }
        ret.push_back(getMid(k));

        int n = nums.size();
        for(int i = 0; i < n- k; i++) {
            kick(k, nums[i]);
            add(k-1, nums[i+k]);
            ret.push_back(getMid(k));
        }
        return ret;
    }
};

*/