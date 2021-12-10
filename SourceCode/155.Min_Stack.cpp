class MinStack {
private:
    stack<int> sta;
    stack<int> min_sta;
public:
    MinStack() {
        min_sta.push(INT_MAX);
    }
    
    void push(int val) {
        sta.push(val);
        if(val <= min_sta.top()) {
            min_sta.push(val);
        }
    }
    
    void pop() {
        if(sta.top() == min_sta.top()) {
            min_sta.pop();
        }
        sta.pop();
    }
    
    int top() {
        return sta.top();
    }
    
    int getMin() {
        return min_sta.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */