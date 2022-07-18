class Solution {
public:
    bool isValid(int i, int j, int n){
        return (i >= 0 && i < n && j >= 0 && j < n );
    }
    void dfs(int i, int j, int n, vector<vector<int>>& grid){
        if(!isValid(i,j,n) || grid[i][j] != 1) 
            return ;
        
        grid[i][j] = 2;
        
        dfs(i+1,j,n,grid);
        dfs(i-1,j,n,grid);
        dfs(i,j+1,n,grid);
        dfs(i,j-1,n,grid);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = size(grid);
        
        bool firstGroup = false;
        queue<pair<int,int>> q;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(!firstGroup && grid[i][j] == 1){
                    dfs(i,j,n,grid);
                    firstGroup = true;
                }
                if(firstGroup && grid[i][j] == 1){
                    // cout<<i<<" "<<j<<endl;
                    q.push({i,j});
                }
            }
        }
        
        // for(int i = 0;i<n;i++){
        //     for(int j = 0;j<n;j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<q.size()<<endl;
        int steps = 0;
        int dir[4][2] = {{1,0} , {0,1} , {-1,0} , {0,-1}};
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x , y] = q.front();
                q.pop();
                
                for(int i = 0;i<4;i++){
                    int xx = x + dir[i][0];
                    int yy = y + dir[i][1];
                    
                    if(!isValid(xx,yy,n) || grid[xx][yy] == 1)
                        continue;
                    else if(grid[xx][yy] == 2){
                        return steps;
                    }else{
                        q.push({xx,yy});
                        grid[xx][yy] = 1;
                    }
                }
            }
            steps++;
        }
        
        return -1;
        
    }
};