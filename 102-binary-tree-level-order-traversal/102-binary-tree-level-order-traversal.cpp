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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            while(size--){
                TreeNode* frontNode = q.front();
                q.pop();
                if(frontNode->left) 
                    q.push(frontNode->left);
                if(frontNode->right)
                    q.push(frontNode->right);
                
                level.push_back(frontNode->val);
            }
            ans.push_back(level);
        }
        
        return ans;
    }
};