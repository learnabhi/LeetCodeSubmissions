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
        unordered_map<int,int> mapka;
        
        for(int colStart = 0;colStart < n ; colStart++){
            for(int colEnd = colStart ; colEnd < n ; colEnd++){
                    int currSum = 0;
                    mapka = {{0,1}};
                    for(int row = 0 ;row < m ;row++){
                        currSum += matrix[row][colEnd] - (colStart ? matrix[row][colStart - 1] : 0);
                        res += mapka[currSum - target];
                        mapka[currSum]++;
                    }
                }
            }
        
        
        return res;
    }
};