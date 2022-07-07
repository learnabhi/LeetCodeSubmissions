class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin() , intervals.end());
        
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1;i<n;i++){
            vector<int> temp = ans.back();
            
            if(temp[1] >= intervals[i][0]){
                ans.pop_back();
                int start = temp[0];
                int end = max(temp[1] , intervals[i][1]);
                
                ans.push_back({start,end});
            }else{
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
    }
};