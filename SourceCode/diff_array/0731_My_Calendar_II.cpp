#include<bits/stdc++.h>
using namespace std;

// 插旗算法
class MyCalendarTwo {
private:
  map<int, int> mmap;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
      if(mmap.find(start) != mmap.end()) {
        mmap[start]++;
      }else{
        mmap[start] = 1;
      }

      if(mmap.find(end) != mmap.end()) {
        mmap[end]--;
      }else{
        mmap[end] = -1;
      }

      int active = 0;
      for(auto iter : mmap) {
        active += iter.second;
        if(active >= 3) {
          mmap[start]--;
          mmap[end]++;
          return false;
        }
      }
      return true;
    }
};
