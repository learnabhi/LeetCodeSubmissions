class Solution {
public:
    bool isValid(int x, int y,int m,int n){
        return (x >= 0 && y >= 0 && x < m && y < n);
    }
    int maxDistance(vector<vector<int>>& grid) {
        int m = size(grid) , n = size(grid[0]);
        
        queue<pair<int,int>> q;
        
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1)
                    q.push({i,j});
            }
        }
        
        if(q.size() == n*m) 
            return -1;
        
        int dist = 0;
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        
        while(!q.empty()){
            int size = q.size();
            dist++;
            
            while(size--){
                auto [x, y] = q.front();
                q.pop();
                
                for(int i = 0;i<4;i++){
                    int xx = x + dx[i];
                    int yy = y + dy[i];
                    
                    if(isValid(xx,yy,m,n) && grid[xx][yy] == 0){
                        q.push({xx,yy});
                        grid[xx][yy] = 1;
                    }
                }
            }
        }
        
        return dist - 1;
    }
};