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
    unordered_map<int,int> mapka;
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder ,int& rootIndex, int start, int end){
        if(start > end)
            return NULL;
            
        int idx = mapka[preorder[rootIndex]];
        rootIndex++;
        
        TreeNode* root = new TreeNode(inorder[idx]);
        
        root->left = constructTree(preorder, inorder, rootIndex, start, idx - 1);
        root->right = constructTree(preorder, inorder, rootIndex, idx+1, end);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        mapka.clear();
        
        for(int i = 0;i<n;i++){
            mapka[inorder[i]] = i;
        }
        int rootIndex = 0;
        return constructTree(preorder, inorder,rootIndex, 0 , n-1);
    }
};