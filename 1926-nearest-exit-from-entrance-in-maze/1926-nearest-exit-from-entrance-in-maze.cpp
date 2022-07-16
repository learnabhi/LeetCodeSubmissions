class Solution {
public:
    bool atBorder(int x, int y , int m ,int n){
        return (x*y == 0 || x == m - 1 || y == n - 1);
    }
    bool isValid(int x , int y, int m, int n){
        return (x >= 0 && y >= 0 && x < m && y < n);
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = size(maze) , n = size(maze[0]);
        
        int startRow = entrance[0] , startCol = entrance[1];
        
        queue<pair<int,int>> q;
        q.push({startRow,startCol});
        maze[startRow][startCol] = '+';
        int steps = 0;
        
        int dir[4][2] = {{1,0} , {0,1} , {-1,0} , {0,-1}};
        while(!q.empty()){
            int size = q.size();
            steps++;
            while(size--){
                auto [x, y] = q.front();
                q.pop();
                
                for(int i = 0;i<4;i++){
                    int xx = x + dir[i][0];
                    int yy = y + dir[i][1];
                    
                    if(!isValid(xx,yy,m,n) || maze[xx][yy] == '+')
                        continue;
                    
                    if(atBorder(xx,yy,m,n))
                        return steps;
                    
                        q.push({xx,yy});
                        maze[xx][yy] = '+';
                }
            }
        }
        
        return -1;
    }
};