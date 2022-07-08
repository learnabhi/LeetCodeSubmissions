class Solution {
public:
    bool isValid(int i, int j, int m,int n,vector<vector<int>>& grid){
        return (i >= 0 && i < m && j >= 0 && j< n && grid[i][j] == 1);
    }
    bool isBoundary(int i, int j, int m,int n){
        return (i*j == 0 || i == m - 1 || j == n -1);
    }
    void dfs(int i, int j,int m,int n,vector<vector<int>>& grid){
        if(!isValid(i,j,m,n,grid)) return ;
        
        grid[i][j] = 0;
        
        dfs(i+1,j,m,n,grid);
        dfs(i-1,j,m,n,grid);
        dfs(i,j-1,m,n,grid);
        dfs(i,j+1,m,n,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = size(grid) , n = size(grid[0]);
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(isBoundary(i,j,m,n) && grid[i][j] == 1){
                    dfs(i,j,m,n,grid);
                }
            }
        }
        
        int count = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1)
                    count++;
            }
        }
        
        return count;
    }
};