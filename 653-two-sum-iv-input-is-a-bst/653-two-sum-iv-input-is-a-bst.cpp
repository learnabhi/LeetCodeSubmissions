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
    bool dfs(TreeNode* root, unordered_set<int>& st, int k){
        if(!root) return false;
        if(st.count(k -root->val) > 0) return true;
        
        st.insert(root->val);
        
        return dfs(root->left,st,k) || dfs(root->right,st,k);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return dfs(root,st,k);
    }
};