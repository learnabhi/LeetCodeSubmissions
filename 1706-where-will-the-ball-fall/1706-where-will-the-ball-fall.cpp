class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            int currRow = 0 , currCol = i;
            while(currRow < m){
                if(grid[currRow][currCol] == 1 
                   && (currCol + 1 < n && grid[currRow][currCol + 1] == 1)){
                   currRow++ , currCol++; 
                }else if(grid[currRow][currCol] == -1
                    && (currCol - 1 >= 0 && grid[currRow][currCol - 1] == -1)){
                    currRow++ , currCol--;
                }else{
                    break;
                }
            }
            ans[i] = (currRow == m) ? currCol : -1;
        }
        
        return ans;
    }
};