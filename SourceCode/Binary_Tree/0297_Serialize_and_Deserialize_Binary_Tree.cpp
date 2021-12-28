#include<bits/stdc++.h>
using namespace std;
// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Codec {
private: 
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    int n = 0;
    queue<TreeNode*> q;
    string ret;
    q.push(root);
    while(!q.empty()) {
      TreeNode *top = q.front();
      q.pop();
      if(top == NULL) {
        ret = ret + ',';
        n++;
        continue;
      }
      q.push(top->left);
      q.push(top->right);
      n++;
      ret = ret + to_string(top->val) + ',';
    }
    ret += to_string(n);
    // cout << ret << endl;
    return ret;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    int pos = data.find_last_of(",");
    string sub = data.substr(pos+1);
    int n = stoi(sub);
    data.erase(pos+1);
    // cout << data << endl << n << endl;
    TreeNode **vec = (TreeNode **) malloc(n * sizeof(TreeNode *));
    int ptr = 0;
    int begin = 0, end = 0;
    while((end=data.find(',',begin)) != string::npos) {
      string substr = data.substr(begin, end-begin);
      if(substr == "") {
        vec[ptr++] = nullptr;
      }else{
        int val = stoi(substr);
        vec[ptr++] = new TreeNode(val);
      }
      begin = end+1;
    }
    // cout << "here" << endl;
    int l = 0, r = 0;
    for(l = 0; l < n; l++){
      TreeNode *root = vec[l];
      if(root == nullptr) continue;
      if(++r >= n) break;
      root->left = vec[r];
      if(++r >= n) break;
      root->right = vec[r];
    }
    return vec[0];
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


// class Codec {
// public:
//     void rserialize(TreeNode* root, string& str) {
//         if (root == nullptr) {
//             str += "None,";
//         } else {
//             str += to_string(root->val) + ",";
//             rserialize(root->left, str);
//             rserialize(root->right, str);
//         }
//     }

//     string serialize(TreeNode* root) {
//         string ret;
//         rserialize(root, ret);
//         return ret;
//     }

//     TreeNode* rdeserialize(list<string>& dataArray) {
//         if (dataArray.front() == "None") {
//             dataArray.erase(dataArray.begin());
//             return nullptr;
//         }

//         TreeNode* root = new TreeNode(stoi(dataArray.front()));
//         dataArray.erase(dataArray.begin());
//         root->left = rdeserialize(dataArray);
//         root->right = rdeserialize(dataArray);
//         return root;
//     }

//     TreeNode* deserialize(string data) {
//         list<string> dataArray;
//         string str;
//         for (auto& ch : data) {
//             if (ch == ',') {
//                 dataArray.push_back(str);
//                 str.clear();
//             } else {
//                 str.push_back(ch);
//             }
//         }
//         if (!str.empty()) {
//             dataArray.push_back(str);
//             str.clear();
//         }
//         return rdeserialize(dataArray);
//     }
// };
