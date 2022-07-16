class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        
        vector<int> subset;
        vector<vector<int>> totalSubset;
        
        backtrack(subset,totalSubset,nums,0);
        
        return totalSubset;
    }
    
    void backtrack(vector<int>& subset, vector<vector<int>>& totalSubset, vector<int>& nums,int idx){
        totalSubset.push_back(subset);
        
        for(int i = idx ;i< nums.size();i++){
            if(i == idx || (nums[i] != nums[i-1])){
            subset.push_back(nums[i]);
            backtrack(subset,totalSubset,nums,i+1);
            subset.pop_back();
                
            }
            
        }
    }
};