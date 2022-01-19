/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *  
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *    
 *    
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class NestedIterator {
public:
  vector<int> vec;
  int now, n;
  void init(vector<NestedInteger>& nestedList) {
    for(NestedInteger &item : nestedList) {
      if(item.isInteger()) {
        // cout << "k\n";
        vec.emplace_back(item.getInteger());
      }else{
        init(item.getList());
      }
    }
    return;
  }
  NestedIterator(vector<NestedInteger> &nestedList) {
    init(nestedList);
    now = 0;
    n = vec.size();
    // cout << n << endl;
  }
    
  int next() {
    return vec[now++];
  }
  
  bool hasNext() {
    return now < n;
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */