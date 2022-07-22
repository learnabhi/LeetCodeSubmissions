class Solution {
public:
    int dp[301][301];
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        memset(dp , -1, sizeof dp);
        
        return maxCoinsUtil(nums,0,n-1);
    }
    
    int maxCoinsUtil(vector<int>& nums, int start, int end){
        if(start > end)
            return 0;
        
        if(dp[start][end] != -1)
            return dp[start][end];
        
        int maxx = nums[start];
        
        for(int i = start;i<=end;i++){
            int val = maxCoinsUtil(nums,start, i-1) 
                      + get(nums, i)*get(nums, start -1 )*get(nums,end+1)
                      + maxCoinsUtil(nums,i+1,end);
            
            maxx = max(maxx , val);
        }
        
        return dp[start][end] = maxx;
    }
    int get(vector<int>& nums, int i){
        if(i < 0 || i >= nums.size())
            return 1;
        
        return nums[i];
    }
};