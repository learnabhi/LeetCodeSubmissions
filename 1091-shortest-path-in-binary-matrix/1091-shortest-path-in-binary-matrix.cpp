class Solution {
public:
    bool isValid(int x,int y,int n){
        return (x >= 0 && y >= 0 && x < n && y < n);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = size(grid);
        
        queue<pair<int,int>> q;
        
        if(grid[0][0] == 1)
            return -1;
        
        q.push({0,0});
        grid[0][0] = 1;
        
        
        int res = 0;
        int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        
        while(!q.empty()){
            int size = q.size();
            res++;
            while(size--){
                auto [x , y] = q.front();
                q.pop();
                
                if(x == n - 1 && y == n - 1){
                    return res;
                }
                
                for(int i = 0;i<8;i++){
                    int xx = x + dir[i][0];
                    int yy = y + dir[i][1];
                    
                    if(isValid(xx,yy,n) && grid[xx][yy] == 0){
                        q.push({xx,yy});
                        grid[xx][yy] = 1;
                    }
                }
            }
        }
        
        return -1;
    }
};