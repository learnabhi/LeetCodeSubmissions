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
    bool isValid(TreeNode* root, long minn , long maxx){
        if(!root) return true;
        
        if(root->val <= minn || root->val >= maxx) return false;
        
        return isValid(root->left, minn, root->val) && isValid(root->right, root->val, maxx);
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};