/*堆*/
class Solution {
public:
    int nthUglyNumber(int n) {
        typedef long long int LLI;
        priority_queue<LLI, vector<LLI>, greater<LLI>> q;
        q.push(1L);
        int head = 0;
        for(int i = 0; i < n-1;) {
            int top = q.top(); q.pop();
            cnt --;
            if(head == top) {
                continue;
            }
            head = top;
            q.push(top*2LL); q.push(top*3LL); q.push(top*5LL);
            i++;
        }
        while(head == q.top()) q.pop();
        return q.top();
    }
};
/*DP*/
class Solution {
public:
    int nthUglyNumber(int n) {
        int *dp = new int[n+1];
        int p1 = 1, p2 = 1, p3 = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            int num1 = dp[p1]*2, num2 = dp[p2]*3, num3 = dp[p3]*5;
            dp[i] = min({num1, num2, num3});
            if(dp[i] == num1) {
                p1++;
            }
            if(dp[i] == num2) {
                p2++;
            }
            if(dp[i] == num3){
                p3++;
            }
        }
        return dp[n];
    }
};

/*DP*/

// #include<bits/stdc++.h>
// using namespace std;

//     int nthUglyNumber(int n) {
//         priority_queue<int, vector<int>, greater<int>> q;
//         q.push(1);
//         int head = 0;
//         for(int i = 0; i < n-1;) {
//             int top = q.top(); q.pop();
//             if(head == top) {
//                 continue;
//             }
//             head = top;
//             q.push(top*2); q.push(top*3); q.push(top*5);
//             i++;
//         }
//         while(head == q.top()) q.pop();
//         return q.top();
//     }

//     int main(){
//         int ret = nthUglyNumber(10);
//         return 0;

//     }