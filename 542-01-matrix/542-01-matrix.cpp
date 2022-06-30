class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = size(mat) , n = size(mat[0]);
        
        queue<pair<int,int>> q;
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] == 0)
                    q.push({i,j});
                else 
                    mat[i][j] = -1;
            }
        }
        
        vector<int> dir = {1,0,-1,0,1};
        
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            
            for(int i = 0;i<4;i++){
                int xx = x + dir[i];
                int yy = y + dir[i+1];
                
                if(isSafe(xx,yy,m,n) && mat[xx][yy] == -1){
                    q.push({xx,yy});
                    mat[xx][yy] = 1 + mat[x][y];
                }
            }
        }
        
        return mat;
    }
    bool isSafe(int x, int y, int m, int n){
        return (x >= 0 && x < m && y >=0 && y < n);
    }
};