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

class Solution {
public:
    // 0 for min, 1 for max
    int findMinorMax(TreeNode* root, int mode) {
        TreeNode *ptr;
        if(!mode){
            ptr= root->left;
        }else{
            ptr= root->right;
        }
        if(!ptr) return root->val;
        return findMinorMax(ptr, mode);
    }

    bool isValidBST(TreeNode* root) {
        if (!root){
            return true;
        }
        
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        if(isValidBST(left) && isValidBST(right)) {
            long long  l = left == NULL ? LLONG_MIN : findMinorMax(left, 1);
            long long  r = right == NULL ? LLONG_MAX : findMinorMax(right, 0);
            if(l < root->val && r > root->val) return true;
        }
        return false;
        
    }
};