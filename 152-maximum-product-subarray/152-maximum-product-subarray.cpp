class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int l = 0 , r = 0;
        int res = nums[0];
        
        for(int i = 0;i<n;i++){
            l = (l ? l*nums[i] : nums[i]);
            r = (r ? r * nums[n - i - 1] : nums[n - i -1]);
            
            res = max(res, max(l,r));
        }
        
        return res;
    }
};