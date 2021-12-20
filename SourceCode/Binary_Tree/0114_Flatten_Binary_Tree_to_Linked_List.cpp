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
/*naive*/
class Solution {
public:
  void flatten(TreeNode* root) {
    if(root == nullptr) return;
    flatten(root->left);
    TreeNode *ptr = getTail(root->left);
    flatten(root->right);
    // ptr->left = nullptr;
    if(ptr) {
      ptr->right = root->right;
      root->right = root->left;
      root->left = nullptr;
    }
    return;
  }
  TreeNode *getTail(TreeNode *ptr) {
    if(ptr == nullptr) return nullptr;
    while(ptr->right != nullptr){
      ptr = ptr->right;
    }
    return ptr;
  }
};

/*optimized*/

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
  void flatten(TreeNode* root) {
    if(root == nullptr) return;
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    flatten(left);
    flatten(right);
    root->left = nullptr;
    root->right = left;
    while(root->right) {
      root = root->right;
    }
    root->right = right;
    return;
  }
};