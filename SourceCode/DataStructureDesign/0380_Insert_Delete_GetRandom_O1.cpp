#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
private:
  int size;
  vector<int> vec;
  unordered_map<int, int> mmap;
public:
  RandomizedSet() {
    srand(0);
    size = 0;
    return;
  }
  
  bool insert(int val) {
    if(mmap.find(val) != mmap.end()) {
      return false;
    }
    vec.push_back(val);
    mmap[val] = size++;
    return true;
  }
  
  bool remove(int val) {
    if(mmap.find(val) == mmap.end()) {
      return false;
    }
    int pos = mmap[val];
    int tail = vec[size-1];
    mmap[tail] = pos;
    vec[pos] = tail;
    vec.pop_back();
    mmap.erase(val);
    size--;
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
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */