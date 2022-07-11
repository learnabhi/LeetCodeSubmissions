class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 1) return 0;
        
        int maxSum = nums[0] , currMax = nums[0];
        int minSum = nums[0] , currMin = nums[0];
        int totalSum = nums[0];
        for(int i = 1;i<n;i++){
            currMax = max(nums[i] , currMax + nums[i]);
            maxSum = max(currMax , maxSum);
            
            currMin = min(nums[i] , currMin + nums[i]);
            minSum = min(currMin , minSum);
            
            totalSum += nums[i];
        }
        
        return (maxSum > 0) ? max(maxSum , totalSum - minSum) : maxSum;
    }
};