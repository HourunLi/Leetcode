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
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
  map<string, int> memo;
  vector<TreeNode*> ret;
public:
  string traversal(TreeNode *root) {
    if(root == nullptr) return "#";
    string left = traversal(root->left);
    string right = traversal(root->right);
    //must add delimiters
    string tree = left + "," + right + "," + to_string(root->val);
    memo[tree]++;
    if(memo[tree] == 2) {
      ret.push_back(root);
    }
    return tree;
  }
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    if(root == nullptr) return {};
    traversal(root);
    return ret;
  }
};