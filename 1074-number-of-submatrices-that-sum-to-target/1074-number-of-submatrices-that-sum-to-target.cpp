class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m  = size(matrix) , n = size(matrix[0]);
        
        for(int i = 0;i<m;i++){
            for(int j = 1;j<n;j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        int res = 0;
        for(int colStart = 0;colStart < n ; colStart++){
            for(int colEnd = colStart ; colEnd < n ; colEnd++){
                for(int rowStart = 0 ;rowStart < m ; rowStart++){
                int sum = 0;
                for(int rowEnd = rowStart ; rowEnd < m; rowEnd++){
                    sum += matrix[rowEnd][colEnd] - (colStart ? matrix[rowEnd][colStart - 1] : 0);
                    if(sum == target)
                        res++;
                }
                    
                }
            }
        }
        
        return res;
    }
};