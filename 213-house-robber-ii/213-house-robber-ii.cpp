class Solution {
public:
    int rob(vector<int>& nums,int start,int end){
        int curr = 0 , pre =0;
        for(int i = start;i<end;i++){
            int temp = max(pre + nums[i] , curr);
            pre = curr;
            curr = temp;
        }
        
        return curr;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0] , nums[1]);
        
        return max(rob(nums,0,n-1) , rob(nums,1,n));
    }
};