class Solution {
public:
    bool isValid(int i, int j, vector<vector<char>>& grid){
        return (i >= 0 && i < grid.size() && j >= 0 && j< grid[0].size() && grid[i][j]  == '1');
    }
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(!isValid(i,j,grid)) return ;
        
        grid[i][j] = '0';
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = size(grid) , n = size(grid[0]);
        
        int count = 0;
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        
        return count;
    }
};