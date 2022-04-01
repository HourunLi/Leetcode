#include <bits/stdc++.h>
using namespace std;
// by using lower_bound function in STL
// prev function
class MyCalendar {
private:
  set<pair<int, int>> ans;
public:
  MyCalendar() {
      
  }
  
  bool book(int start, int end) {
    auto iter = ans.lower_bound({end, INT_MIN});
    if(iter == ans.begin() || prev(iter)->second <= start) {
      ans.insert({start, end});
      return true;
    }
    return false;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */