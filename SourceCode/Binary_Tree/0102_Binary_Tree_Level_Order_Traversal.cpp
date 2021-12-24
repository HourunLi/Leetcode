/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
  vector<vector<int>> ret;
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    if(root == nullptr) return {};
    queue<pair<int, TreeNode*>> q;
    q.push(make_pair(0, root));
    while(!q.empty()) {
      auto top = q.front(); q.pop();
      int num = top.first;
      TreeNode *ptr = top.second;
      if(ret.size() >  num) {
        ret[num].push_back(ptr->val);
      } else{
        ret.push_back({});
        ret[num].push_back(ptr->val);
      }
      if(ptr->left) {
        q.push(make_pair(num+1, ptr->left));
      }
      if(ptr->right) {
        q.push(make_pair(num+1, ptr->right));
      }
    }
    return ret;
  }
};