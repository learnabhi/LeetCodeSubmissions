class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        int start = 0 , end = 0;
        
        int minLength = INT_MAX;
        
        int sum = 0;
        while(end < n){
            sum += nums[end];
            end++;
            
            while(sum >= target){
                minLength = min(minLength , end - start);
                sum -= nums[start];
                start++;
            }
        }
        
        return (minLength == INT_MAX ? 0 : minLength);
    }
};