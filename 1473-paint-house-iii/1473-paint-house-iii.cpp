class Solution {
public:
    int dp[101][101][21] = {};
    int MAX = 10000001;
    int dfs(vector<int>& houses,vector<vector<int>>& cost,int idx,int target,int last_color,int m,int n)
    {
        if(idx >= m || target < 0){
            return (target == 0) ? 0 : MAX;
        }
        
        if(dp[idx][target][last_color]){
            return dp[idx][target][last_color];
        }
        
        if(houses[idx] != 0){
            return dfs(houses,cost,idx+1,target - (last_color != houses[idx]) , houses[idx],m,n);
        }
        
        int ans = MAX;
        for(int color = 1;color <= n;color++){
            ans = min(ans, cost[idx][color - 1] 
                          + dfs(houses,cost,idx + 1,target - (color != last_color),color,m,n));
        }
        
        return dp[idx][target][last_color] = ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int res = dfs(houses,cost,0,target,0,m,n);
        
        return (res >= MAX ? -1 : res);
    }
};