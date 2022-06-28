class Solution {
public:
    bool valid(int x, int y, int m, int n){
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = size(image) , n = size(image[0]);
        if(image[sr][sc] == color) return image;
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        
        int oldColor = image[sr][sc];
        image[sr][sc] = color;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            int xx = front.first;
            int yy = front.second;
            
            for(int i = 0;i<4;i++){
                int x = xx + dx[i];
                int y = yy + dy[i];
                
                if(valid(x,y,m,n) && image[x][y] == oldColor){
                    q.push({x,y});
                    image[x][y] = color;
                }
            }
            
        }
        
        return image;
    }
};