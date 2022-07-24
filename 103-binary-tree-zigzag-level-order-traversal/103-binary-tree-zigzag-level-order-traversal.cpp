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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool flag = true;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            for(int i = 0;i< size;i++){
                TreeNode* frontNode = q.front();
                q.pop();
                
                if(flag)
                    level[i] = frontNode->val;
                else
                    level[size - i - 1] = frontNode->val;
                
                
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
            
            flag = !flag;
            ans.push_back(level);
        }
        
        return ans;
    }
};