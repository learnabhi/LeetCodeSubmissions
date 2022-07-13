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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        int maxx = 0;
        dfs(root,maxx);
        
        return maxx;
    }
    int dfs(TreeNode* root, int& maxx){
        if(!root) return 0;
        
        int left = dfs(root->left, maxx);
        int right = dfs(root->right,maxx);
        
        maxx = max(maxx , left + right);
        
        
        return max(left, right) + 1;
    }
};