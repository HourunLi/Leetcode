#include<bits/stdc++.h>
using namespace std;

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

class Ret {
public:
  int num, sum, cnt;
  Ret():num(0), sum(0), cnt(0){

  }

  Ret(int a, int b, int c):num(a), sum(b), cnt(c){

  }
  Ret operator +(const Ret &b){
    return Ret(this->num+b.num, this->sum+b.sum, this->cnt+b.cnt);
    }
};

class Solution {
public:
  Ret dfs(TreeNode* root) {
    if(root == nullptr) {
      return Ret(0, 0, 0);
    }

    Ret left = dfs(root->left), right = dfs(root->right);

    Ret ret = Ret(left.num + right.num + 1, left.sum + right.sum + root->val, left.cnt + right.cnt);
    if((left.sum + right.sum + root->val) / (left.num + right.num + 1) == root->val) {
      ret.cnt++;
    }

    return ret;
  }

  int averageOfSubtree(TreeNode* root) {
    struct Ret result= dfs(root);
    return result.cnt;
  }
};