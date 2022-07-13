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
    void dfs(TreeNode* root, int targetSum, unordered_map<int,int>& mapka,long& ans, long sum){
        if(!root) return;
        
        sum += (root->val);
        
        if(mapka.find(sum - targetSum) != mapka.end())
            ans += mapka[sum - targetSum];
        
        mapka[sum]++;
        
        dfs(root->left,targetSum,mapka,ans,sum);
        dfs(root->right,targetSum,mapka,ans,sum);
        
        mapka[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int,int> mapka;
        
        long sum = 0, ans = 0;
        mapka[sum]++;
        
        dfs(root,targetSum,mapka,ans,sum);
        
        return (int)ans;
    }
};