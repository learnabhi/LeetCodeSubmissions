class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = size(obstacleGrid) , n = size(obstacleGrid[0]);
        
        vector<int> curr(n , 0);
        curr[0] = 1;
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(obstacleGrid[i][j])
                    curr[j] = 0;
                else if(j > 0)
                    curr[j] += curr[j-1];
            }
        }
        
        return curr[n-1];
    }
};