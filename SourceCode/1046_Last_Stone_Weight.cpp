#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q; //默认是最大的
        for(auto i : stones) 
            q.push(i);

        while(q.size() >= 2) {
            int head1 = q.top(); q.pop();
            int head2 = q.top(); q.pop();
            if(head1 - head2 != 0) {
                q.push(abs(head1 - head2));
            }
        }

        if(q.empty()) return 0;
        return q.top();
    }
};