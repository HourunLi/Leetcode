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
/* solution1 */
class Solution {
public:
    bool dfs(TreeNode* p1, TreeNode* p2) {
        if(!p1 || !p2) {
            return p1 == p2;
        }
        if(p1->val != p2->val) 
            return false;
        return dfs(p1->left, p2->right) && dfs(p1->right, p2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left, root->right);
    }
};
/* solution2 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()) {
            TreeNode*t1 = q.front(); q.pop();
            TreeNode* t2 = q.front(); q.pop();
            if(!t1 && !t2) {
                continue;
            }
            if((!t1 || !t2) ||t1->val != t2->val) 
                return false;
            q.push(t1->left);
            q.push(t2->right);

            q.push(t2->left);
            q.push(t1->right);
        }
        return true;
    }
};