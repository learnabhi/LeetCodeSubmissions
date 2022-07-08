class Solution {
public:
    bool isValid(int i, int j, int m,int n){
        return (i >= 0 && j >= 0 && i < m && j < n);
    }
    void dfs(int i,int j,int m,int n,vector<vector<int>>& grid1, vector<vector<int>>& grid2,bool& flag){
        if(!isValid(i,j,m,n) || grid2[i][j] == 0) return ;
        
        if(grid2[i][j] == 1 && grid1[i][j] == 0){
            flag = false;
            return ;
        }
        
        grid2[i][j] = 0;
        
        dfs(i+1,j,m,n,grid1,grid2,flag);
        dfs(i-1,j,m,n,grid1,grid2,flag);
        dfs(i,j+1,m,n,grid1,grid2,flag);
        dfs(i,j-1,m,n,grid1,grid2,flag);
        
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = size(grid2) , n = size(grid2[0]);
        
        int ans = 0;
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid2[i][j] == 1){
                    bool flag = true;
                    dfs(i,j,m,n,grid1,grid2,flag);
                    ans += flag;
                }
            }
        }
        
        return ans;
    }
};