class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> mapka;
        
        for(int val : nums1){
            mapka[val]++;
        }
        
        for(int val : nums2){
            if(mapka[val] > 0){
                ans.push_back(val);
                mapka[val]--;  
            }
        }
        
        return ans;
    }
};