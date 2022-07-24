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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(root, targetSum , paths, path);
        
        return paths;
    }
    void dfs(TreeNode* root, int targetSum , vector<vector<int>>& paths, vector<int>& path){
        if(!root) return ;
        
        path.push_back(root->val);
        
        if(!root->left && !root->right && root->val == targetSum)
        {
            paths.push_back(path);
        }
        
        dfs(root->left, targetSum - root->val, paths, path);
        dfs(root->right, targetSum - root->val, paths, path);
        
        path.pop_back();
    }
};