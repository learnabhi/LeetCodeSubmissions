class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n < 1) return 0;
        
        int maxProd = nums[0];
        int minProd = nums[0];
        
        int res = maxProd;
        
        for(int i = 1;i< n ;i++){
            if(nums[i] >= 0){
                maxProd = max(maxProd * nums[i] , nums[i]);
                minProd = min(minProd * nums[i] , nums[i]);
            }else{
                int temp = maxProd;
                
                maxProd = max(minProd * nums[i] , nums[i]);
                minProd = min(temp * nums[i] , nums[i]);
            }
            
            res = max(res,  maxProd);
        }
        
        return res;
    }
};