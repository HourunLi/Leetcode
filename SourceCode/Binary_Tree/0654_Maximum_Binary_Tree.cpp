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
  TreeNode *build(int l, int r, vector<int>& nums) {
    if(l > r) return nullptr;
    int ind = -1, max = INT_MIN;
    for(int i = l; i <= r; i++) {
      if(nums[i] > max) {
        ind = i;
        max = nums[i];
      }
    }
    TreeNode *root = new TreeNode(max);
    TreeNode *left = build(l, ind-1, nums);
    TreeNode *right = build(ind+1, r, nums);
    root->left = left;
    root->right = right;
    return root;
  }
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    int n = nums.size();
    return build(0, n-1, nums);
  }
};