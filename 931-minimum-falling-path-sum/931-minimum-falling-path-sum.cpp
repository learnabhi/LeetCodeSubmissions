class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = size(matrix);
        
        int res = INT_MAX;
        
        for(int i = 1;i<n;i++){
            for(int j = 0;j<n;j++){
                int leftUP = (j == 0) ? INT_MAX : matrix[i-1][j-1];
                int rightUP = (j == n - 1) ? INT_MAX : matrix[i-1][j+1];
                int UP = matrix[i-1][j];
                matrix[i][j] += min({leftUP, rightUP , UP});
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i = 0;i<n;i++){
            res = min(res , matrix[n-1][i]);
        }
        
        return res;
    }
};