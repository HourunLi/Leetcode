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
  TreeNode* buildTree(int pl, int pr, int il, int ir, vector<int>& preorder, vector<int>& inorder) {
    if(pl > pr) return nullptr;
    int val = preorder[pl];
    TreeNode* root = new TreeNode(val);
    int ind;
    for(int i = il; i <= ir; i++) {
      if(inorder[i] == val) {
        ind = i;
        break;
      }
    }
    TreeNode* left = buildTree(pl+1, pl+ind-il, il, ind-1, preorder, inorder);
    TreeNode* right = buildTree(pl+ind-il+1, pr, ind+1, ir, preorder, inorder);
    root->left = left;
    root->right = right;
    return root;
  }
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n  = preorder.size();
    return buildTree(0, n-1, 0, n-1, preorder, inorder);
  }
};