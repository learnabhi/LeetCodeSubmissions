class Solution {
private:    
    bool solve(int i,vector<int>&nums,int k,int sum,int req_sum,vector<bool>&vis){
        if(k == 1) return true;
        if(i == nums.size()) return false;
        if(sum == req_sum) return solve(0,nums,k-1,0,req_sum,vis);
        
        
        if(!vis[i] and sum + nums[i] <= req_sum){
            vis[i] = true;
            if(solve(i+1,nums,k,sum + nums[i],req_sum,vis)) return true;
            vis[i] = false;
        }
        
        return solve(i+1,nums,k,sum,req_sum,vis);            
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(n < k or sum % k != 0) return false;
        int req_sum = sum/k;
        sort(nums.begin(),nums.end(),greater<int>());
        vector<bool> vis(nums.size());
        return solve(0,nums,k,0,req_sum,vis);
    }
};