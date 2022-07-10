class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        auto myComp = [](const vector<int>& a1, const vector<int>& a2){
            return a1[1] < a2[1];
        };
        sort(intervals.begin() , intervals.end() , myComp);
        
        vector<int>& prev = intervals[0];
        int count = 0;
        for(int i = 1;i<n;i++){
            if(intervals[i][0] < prev[1]){
                count++;
                continue;
            }
            prev = intervals[i];
        }
        
        return count;
    }
};