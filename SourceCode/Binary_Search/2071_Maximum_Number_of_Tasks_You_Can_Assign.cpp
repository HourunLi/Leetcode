#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

  int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
      int n = tasks.size(), m = workers.size();
      sort(tasks.begin(), tasks.end(), less<int>());
      sort(workers.begin(), workers.end(), greater<int>());

      auto check = [&](int mid) -> bool {
        // cout << mid<<endl;
        int p = pills;
        multiset<int> ws;
        for(int i = 0; i< mid; i++) {
          ws.insert(workers[i]);
        }

        for(int i = mid-1; i >=0; i--) {
          auto it = prev(ws.end());
          // cout << workers[i] << " " << *it << endl;
          if(tasks[i] <= *it) { 
            ws.erase(it);
          }else{
            if(!p) {
              return false;
            }else{
              auto rep = ws.lower_bound(tasks[i] - strength);
              if(rep == ws.end()) {
                return false;
              }
              p--;
              ws.erase(rep);
            }
          }
        }
        // cout << "return true\n";
        return true;
      };

      int l = 0, r = min(m, n), ans = 0;
      while(l <= r) {
        int mid = (l+r) >> 1;
        if(check(mid)) {
          ans = mid;
          l = mid+1;
        }else{
          r = mid-1;
        }
      }
      return ans;
  }
};
// class Solution {
// public:
//     int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
//         int n = tasks.size(), m = workers.size();
//         sort(tasks.begin(), tasks.end());
//         sort(workers.begin(), workers.end());
        
//         auto check = [&](int mid) -> bool {
//             int p = pills;
//             // 工人的有序集合
//             multiset<int> ws;
//             for (int i = m - mid; i < m; ++i) {
//                 ws.insert(workers[i]);
//             }
//             // 从大到小枚举每一个任务
//             for (int i = mid - 1; i >= 0; --i) {
//                 // 如果有序集合中最大的元素大于等于 tasks[i]
//                 if (auto it = prev(ws.end()); *it >= tasks[i]) {
//                     ws.erase(it);
//                 }
//                 else {
//                     if (!p) {
//                         return false;
//                     }
//                     auto rep = ws.lower_bound(tasks[i] - strength);
//                     if (rep == ws.end()) {
//                         return false;
//                     }
//                     --p;
//                     ws.erase(rep);
//                 }
//             }
//             return true;
//         };
        
//         int left = 1, right = min(m, n), ans = 0;
//         while (left <= right) {
//             int mid = (left + right) / 2;
//             if (check(mid)) {
//                 ans = mid;
//                 left = mid + 1;
//             }
//             else {
//                 right = mid - 1;
//             }
//         }
//         return ans;
//     }
// };


