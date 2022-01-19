#include<bits/stdc++.h>
using namespace std;
class RandomizedCollection {
private:
  int size;
  vector<int> vec;
  unordered_map<int, unordered_set<int>* >mmap;
public:
  RandomizedCollection() {
    srand(0);
    size = 0;
    return;
  }
  
  bool insert(int val) {
    vec.push_back(val);
    //already exists
    if(mmap.find(val) != mmap.end()) {
      mmap[val]->insert(size++);
      return false;
    }

    auto ptr = new unordered_set<int>;
    mmap[val] = ptr;
    ptr->insert(size++);
    return true;
  }
  
  bool remove(int val) {
    // not exists
    if(mmap.find(val) == mmap.end()) {
      return false;
    }
    
    int tail = vec[size-1];
    if(val == tail) {
      mmap[val]->erase(size-1);
    }else{
      int pos = *(mmap[val]->begin());
      vec[pos] = tail;
      mmap[tail]->erase(size-1);
      mmap[tail]->insert(pos);
      mmap[val]->erase(pos);
    }

    size--;
    vec.pop_back();
    if(mmap[val]->empty()) {
      delete(mmap[val]);
      mmap.erase(val);
      return true;
    }
    return true;
  }
  
  int getRandom() {
    int offset = rand() % size;
    if(size > RAND_MAX) {
      cout << "WARNING\n";
    }
    return vec[offset]; 
  }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// remove 1 3
// 3 1 0 
// 1 1 2 2 2 
// 1 0 
// remove 2 3
// 3 4 2 
// 1 1 2 2 
// 2 
// remove 2 2
// 2 
// 1 1 2 
