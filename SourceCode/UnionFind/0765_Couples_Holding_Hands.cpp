#include<bits/stdc++.h>
using namespace std;
class UnionFind  {
private:
  int size;
  int *arr;
public:
  UnionFind(int size) : size(size) { 
    arr = new int[size];
    for(int i = 0; i < size; i++)  {
      arr[i] = i;
    }
  }
  int find(int x) {
    if(x != arr[x]) {
      arr[x] = find(arr[x]);
    }
    return arr[x];
  }
  void Union(int a, int b) {
    int pa = find(a), pb = find(b);
    if(pa != pb) {
      arr[pa] = pb; 
      size--;
    }
    return;
  }
  int getSize() {
    return size;
  }
};
class Solution {
private:
  int ret;
  int *position;
public:
  int minSwapsCouples(vector<int>& row) {
    int n = row.size();
    int base = n >>1;
    UnionFind unionFind = UnionFind(base);
    for(int i = 0; i < n; i+=2) {
      unionFind.Union(row[i]/2, row[i+1]/2);
    }
    return base - unionFind.getSize();
  }

};