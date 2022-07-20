class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = size(mat) , n = size(mat[0]);
        
        vector<vector<int>> sum(m + 1 , vector<int>(n + 1 , 0));
        
        
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                sum[i][j] = mat[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }
        
        vector<vector<int>> ans(m, vector<int>(n));
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int row1 = max( 0 , i - k) , col1 = max(0 , j - k);
                int row2 = min(m - 1, i + k) , col2 = min(n - 1, j + k);
                
                ans[i][j] = sum[row2 + 1][col2 + 1] - sum[row2 + 1][col1] - sum[row1][col2 + 1] + sum[row1][col1];
            }
        }
        
        return ans;
    }
};