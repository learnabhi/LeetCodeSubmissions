class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int leftSum = 0 , sum = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
        }
        
        for(int i = 0;i<n;i++){
            int rightSum = sum - nums[i] - leftSum;
            if(leftSum == rightSum){
                return i;
            }
            leftSum += nums[i];
        }
        
        return -1;
    }
};