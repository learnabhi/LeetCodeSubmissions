class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = size(grid) , n = size(grid[0]);
        
        int ans = 0;
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    ans = max(ans, bfs(i,j,grid));
                }
            }
        }
        
        return ans;
    }
    int bfs(int x, int y, vector<vector<int>>& grid){
         int m = size(grid) , n = size(grid[0]);
        
         grid[x][y] = 0;
         queue<pair<int,int>> q;
        
         q.push({x,y});
        
        int ans = 0;
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            ans++;
            
            for(int i = 0;i<4;i++){
                int xx = front.first + dx[i];
                int yy = front.second + dy[i];
                
                if(isValid(xx,yy,m,n) && grid[xx][yy] != 0){
                    q.push({xx,yy});
                    grid[xx][yy] = 0;
                }
            }
        }
        
        return ans;
    }
    bool isValid(int x, int y, int m,int n){
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
};