class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int longestStreak = 0;
        
        for(auto& val : nums){
            if(st.count(val - 1) > 0)
                continue;
            
            int startStreak = 1;
            while(st.count(val + startStreak) > 0){
                startStreak++;
            }
            
            longestStreak = max(longestStreak , startStreak);
        }
        
        return longestStreak;
    }
};