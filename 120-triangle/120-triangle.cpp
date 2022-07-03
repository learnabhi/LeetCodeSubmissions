class Solution {
public:
    int minimumTotal(vector<vector<int>>& nums) {
        int n = nums.size();
        
        for(int i = n-2;i>=0;i--){
            for(int j = 0;j<nums[i].size();j++){
                nums[i][j] += min(nums[i+1][j],nums[i+1][j+1]);
            }
        }
        
        return nums[0][0];
    }
};