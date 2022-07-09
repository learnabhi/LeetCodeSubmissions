class Solution {
public:
    int MAX = 1000001;
    int maxDistance(vector<vector<int>>& grid) {
        int n = size(grid) , m = size(grid[0]);
        
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1)
                    continue;
                
                grid[i][j] = MAX;
                if(i - 1 >= 0) grid[i][j] = min(grid[i][j] , grid[i-1][j] + 1);
                if(j - 1 >= 0) grid[i][j] = min(grid[i][j] , grid[i][j-1] + 1);
            }
        }
        
        
        int res = 0;
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(grid[i][j] == 1)
                    continue;
                
                if(i + 1 < m) grid[i][j] = min(grid[i][j] , grid[i+1][j] + 1);
                if(j + 1 < n) grid[i][j] = min(grid[i][j] , grid[i][j+1] + 1);
                
                res = max(res, grid[i][j]);
            }
        }
        
        return (res == MAX) ? -1 : res - 1;
    }
};