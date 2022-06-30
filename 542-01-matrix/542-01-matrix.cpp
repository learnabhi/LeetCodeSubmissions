class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = size(mat) , n = size(mat[0]) , INF = m + n;
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] == 0) continue;
                int left = INF , top = INF;
                if(j - 1 >= 0) left = mat[i][j-1];
                if(i-1 >= 0) top = mat[i-1][j];
                
                mat[i][j] = min(left, top) + 1;
            }
        }
        
        for(int i = m-1 ;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(mat[i][j] == 0) continue;
                int right = INF , bottom = INF;
                if(i + 1 < m) bottom = mat[i+1][j];
                if(j + 1 < n) right = mat[i][j+1];
                
                mat[i][j] = min(mat[i][j] , min(right, bottom) + 1);
            }
        }
        
        return mat;
    }
};