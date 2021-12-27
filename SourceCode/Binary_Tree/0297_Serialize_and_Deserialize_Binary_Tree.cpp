#include<bits/stdc++.h>
using namespace std;
// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    queue<TreeNode*> q;
    string ret;
    q.push(root);
    while(!q.empty()) {
      TreeNode *top = q.front();
      q.pop();
      if(top == NULL) {
        ret = ret + ',';
        continue;
      }
      q.push(top->left);
      q.push(top->right);
      ret = ret + to_string(top->val) + ',';
    }
    ret.erase(ret.find_last_not_of(",")+2);
    cout << ret << endl;
    return ret;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    vector<TreeNode *> vec;
    int begin = 0, end = 0;
    while((end=data.find(',',begin)) != string::npos) {
      string substr = data.substr(begin, end-begin);
      if(substr == "") {
        // cout << "null\n";
        vec.push_back(nullptr);
      }else{
        int val = stoi(substr);
        // cout << val << endl;
        vec.emplace_back(new TreeNode(val));
      }
      begin = end+1;
    }
    // cout << vec.size() << endl;
    int l = 0, r = 0;
    int n = vec.size();
    for(l = 0; l < n; l++){
      if(vec[l] == nullptr) continue;
      if(++r >= n) break;
      vec[l]->left = vec[r];
      if(++r >= n) break;
      vec[l]->right = vec[r];
    }
    return vec[0];
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));