class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xxor = 0;
        
        for(int& val : nums){
            xxor ^= val;
        }
        
        return xxor;
    }
};