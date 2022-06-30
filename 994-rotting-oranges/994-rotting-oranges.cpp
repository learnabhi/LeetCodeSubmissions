class Solution {
public:
    bool isSafe(int x, int y, int m, int n){
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = size(grid) , n = size(grid[0]);
        
        int fresh = 0;
        
        queue<pair<int,int>> q;
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    fresh++;
                }else if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        
        int time = -1;
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto front = q.front(); q.pop();
                
                int xx = front.first;
                int yy = front.second;
                
                for(int i = 0;i<4;i++){
                    int x = xx + dx[i];
                    int y = yy + dy[i];
                    
                    if(isSafe(x,y,m,n) && grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x,y});
                        fresh--;
                    }
                }
            }
            time++;
        }
        
        if(fresh > 0 ) return -1;
        
        return (time == -1 ? 0 : time);
    }
};