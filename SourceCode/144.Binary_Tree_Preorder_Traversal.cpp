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
    void print(vector<int> &ans, TreeNode* root) {
        if(root == NULL) return;
        ans.push_back(root->val);
        print(ans, root->left);
        print(ans, root->right);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        print(ans, root);
        return ans;
    }
};