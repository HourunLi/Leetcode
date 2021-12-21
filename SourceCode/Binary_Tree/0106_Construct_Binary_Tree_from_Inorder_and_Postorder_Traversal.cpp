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
public:
  TreeNode* buildTree(int pl, int pr, int il, int ir, vector<int>& postorder, vector<int>& inorder) {
    if(pl > pr) return nullptr;
    int val = postorder[pr];
    TreeNode* root = new TreeNode(val);
    int ind;
    for(int i = il; i <= ir; i++) {
      if(inorder[i] == val) {
        ind = i;
        break;
      }
    }
    TreeNode* left = buildTree(pl, pl+ind-il-1, il, ind-1, postorder, inorder);
    TreeNode* right = buildTree(pl+ind-il, pr-1, ind+1, ir, postorder, inorder);
    root->left = left;
    root->right = right;
    return root;
  }
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n  = inorder.size();
    return buildTree(0, n-1, 0, n-1, postorder, inorder);
  }
};