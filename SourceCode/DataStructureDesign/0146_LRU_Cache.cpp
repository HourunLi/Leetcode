#include<bits/stdc++.h>
using namespace std;

/*c++ malloc and free is too slow*/
/*
class LRUCache {
private:
  struct Node {
    int key, val;
    Node *pre, *next;
    Node(int key, int val) : key(key), val(val) {
      pre = nullptr;
      next = nullptr;
    }
  };
  int cap, size;
  Node *head, *tail;
  unordered_map<int, Node *> mmap;
public:
  LRUCache(int capacity) {
    cap = capacity;
    size = 0;
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->pre = head;
  }

  Node *getNode(int key) {
    if(mmap.find(key) == mmap.end()) {
      return nullptr;
    }
    return mmap[key];
  }

  void linkInsert(int key, int value) {
    Node *newNode = new Node(key, value);
    Node *nextNode  = head->next;
    mmap[key] = newNode;
    head->next = newNode;
    newNode->pre = head;
    nextNode->pre = newNode;
    newNode->next = nextNode;
    return;
  }

  void linkDelete(Node *ptr) {
    //  if(ptr == nullptr || ptr == head || ptr == tail) {
    //   std::cerr << "ERROR\n";
    //   return;
    // }
    Node *preNode = ptr->pre, *nextNode = ptr->next;
    preNode->next = nextNode;
    nextNode->pre = preNode;
    mmap.erase(ptr->key);
    delete(ptr);
    return;
  }

  int get(int key) {
    Node *ptr = getNode(key);
    if(ptr == nullptr) {
      return -1;
    }
    int value = ptr->val;
    linkDelete(ptr);
    linkInsert(key, value);
    return value;
  }
  
  void put(int key, int value) {
    Node *ptr = getNode(key);
    if(ptr) {
      linkDelete(ptr);
      linkInsert(key, value);
    }else{
      if(size < cap) {
        size++;
        linkInsert(key, value);
        return;
      }else{
        linkDelete(tail->pre);
        linkInsert(key, value);
      }
    }
    return;
  }
};

*/

class LRUCache {
private:
  struct Node {
    int key, val;
    Node *pre, *next;
    Node(int key, int val) : key(key), val(val) {
      pre = nullptr;
      next = nullptr;
    }
  };
  int cap, size;
  Node *head, *tail;
  unordered_map<int, Node *> mmap;
public:
  LRUCache(int capacity) {
    cap = capacity;
    size = 0;
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->pre = head;
  }

  Node *getNode(int key) {
    if(mmap.find(key) == mmap.end()) {
      return nullptr;
    }
    return mmap[key];
  }

  void linkInsert(int key, int value) {
    Node *newNode = new Node(key, value);
    Node *nextNode  = head->next;
    mmap[key] = newNode;
    head->next = newNode;
    newNode->pre = head;
    nextNode->pre = newNode;
    newNode->next = nextNode;
    return;
  }

  void linkDelete(Node *ptr) {
    //  if(ptr == nullptr || ptr == head || ptr == tail) {
    //   std::cerr << "ERROR\n";
    //   return;
    // }
    Node *preNode = ptr->pre, *nextNode = ptr->next;
    preNode->next = nextNode;
    nextNode->pre = preNode;
    mmap.erase(ptr->key);
    delete(ptr);
    return;
  }

  void linkMoveToHead(Node *ptr) {
    Node *preNode = ptr->pre, *nextNode = ptr->next;
    preNode->next = nextNode;
    nextNode->pre = preNode;

    nextNode = head->next;
    head->next = ptr;
    ptr->pre = head;
    nextNode->pre = ptr;
    ptr->next = nextNode;
    return;
  }

  int get(int key) {
    Node *ptr = getNode(key);
    if(ptr == nullptr) {
      return -1;
    }
    int value = ptr->val;
    linkMoveToHead(ptr);
    return value;
  }
  
  void put(int key, int value) {
    Node *ptr = getNode(key);
    if(ptr) {
      ptr->val = value;
      linkMoveToHead(ptr);
    }else{
      if(size < cap) {
        size++;
        linkInsert(key, value);
        return;
      }else{
        Node *tail_ = tail->pre;
        mmap.erase(tail_->key);
        mmap[key] = tail_;
        tail_->key = key;
        tail_->val = value;
        linkMoveToHead(tail_);
      }
    }
    return;
  }
};
