class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    bool isBoundary(int i, int j, int m, int n){
        return (i*j == 0 || i == m - 1 || j == n -1);
    }
    bool dfs(int i, int j, int m, int n, vector<vector<int>>& grid){
        if(isValid(i,j,m,n) && grid[i][j] != 0) return true;
        else if(isBoundary(i,j,m,n) && grid[i][j] == 0) return false;
        
        grid[i][j] = 1;
        
        bool left = dfs(i,j-1,m,n,grid);
        bool right = dfs(i,j+1,m,n,grid);
        bool up = dfs(i - 1,j,m,n,grid);
        bool down = dfs(i+1,j,m,n,grid);
        
        return left && right && up && down;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = size(grid) , n = size(grid[0]);
        int count = 0;
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 0){
                    if(dfs(i,j,m,n,grid))
                        count++;
                }
            }
        }
        
        return count;
    }
};