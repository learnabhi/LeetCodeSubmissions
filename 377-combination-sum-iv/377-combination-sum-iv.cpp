class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int dp[target + 1];
        memset(dp , -1, sizeof dp);
        dp[0] = 1;
        
        return findCombinationSum(nums,target, dp);
    }
    int findCombinationSum(vector<int>& nums, int target, int dp[]){
        if(dp[target] != -1)
            return dp[target];
        
        int res = 0;
        
        for(int i = 0;i<nums.size();i++){
            if(target >= nums[i]){
                res += findCombinationSum(nums, target - nums[i] , dp);
            }
        }
        
        return dp[target] = res;
    }
};