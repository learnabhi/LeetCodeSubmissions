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
    int countGoodNodes(TreeNode* root, int maxx){
        if(!root) return 0;
        
        if(root->val < maxx){
            return countGoodNodes(root->left, maxx) + countGoodNodes(root->right, maxx);
        }else{
            maxx = max(maxx , root->val);
            return 1 + countGoodNodes(root->left, maxx) + countGoodNodes(root->right, maxx);
        }
        
        return 0;
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        return 1 + countGoodNodes(root->left, root->val) + countGoodNodes(root->right, root->val);
    }
};