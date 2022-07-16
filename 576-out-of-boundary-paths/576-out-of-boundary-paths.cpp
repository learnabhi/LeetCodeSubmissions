class Solution {
public:
    int dp[51][51][51];
    int dir[4][2] = {{1,0} , {0,1} , {-1,0} , {0,-1}};
    int mod = 1e9 + 7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof dp);
        return findPathUtils(m,n,maxMove,startRow,startColumn);
    }
    bool outOfBound(int m,int n,int x, int y){
        return (x < 0 || y < 0 || x >= m || y >= n);
    }
    int findPathUtils(int m,int n,int maxMove,int startRow,int startColumn){
        if(outOfBound(m,n,startRow,startColumn))
            return 1;
        if(maxMove == 0)
            return 0;
        
        if(dp[startRow][startColumn][maxMove] != -1)
            return dp[startRow][startColumn][maxMove]%mod;
        
        dp[startRow][startColumn][maxMove] = 0;
        
        for(int i = 0;i<4;i++){
            dp[startRow][startColumn][maxMove] = (dp[startRow][startColumn][maxMove] + findPathUtils(m,n,maxMove - 1, startRow + dir[i][0] , startColumn + dir[i][1]))%mod;
                
        }
        
        return dp[startRow][startColumn][maxMove]%mod;
    }
};