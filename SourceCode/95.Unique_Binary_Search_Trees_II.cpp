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
    vector<TreeNode*> generate(int l, int r) {
        vector<TreeNode*> ans;
        if(l > r) {
            ans.push_back(nullptr);
            return ans;
        }
        if(l == r) {
            TreeNode *ptr = new TreeNode(l, nullptr, nullptr);
            ans.push_back(ptr);
            return ans;
        }
        for(int k = l; k <= r; k++) {
            vector<TreeNode*> left = generate(l, k-1);
            vector<TreeNode*> right = generate(k+1, r);
            
            for(TreeNode* lptr: left) {
                for(TreeNode* rptr : right) {
                    TreeNode *root = new TreeNode(k, lptr, rptr);
                    // root->right = rptr;
                    // root->left = lptr;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};