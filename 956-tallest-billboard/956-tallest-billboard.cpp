class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        
        int sum = accumulate(rods.begin() , rods.end() , 0);
        
        int limit = 2*sum + 1;
        int dp[n+1][limit];
        memset(dp,-1,sizeof dp);
        dp[0][sum] = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<limit;j++){
                if(j - rods[i-1] >= 0 && dp[i-1][j-rods[i-1]] != -1)
                    dp[i][j] = max(dp[i][j] , dp[i-1][j - rods[i-1]] + rods[i-1]);
                
                if(j + rods[i-1] < limit && dp[i-1][j + rods[i-1]] != -1)
                    dp[i][j] = max(dp[i][j] , dp[i-1][j + rods[i-1]]);
                
                if(dp[i-1][j] != -1)
                    dp[i][j] = max(dp[i][j] , dp[i-1][j]);
            }
        }
        
        return dp[n][sum];
    }
};