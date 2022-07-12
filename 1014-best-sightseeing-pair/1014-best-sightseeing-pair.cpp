class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        
        int startGain = values[0] + 0;
        
        int maxProfit = 0;
        
        for(int i = 1;i<n;i++){
            startGain = max(startGain , values[i-1] + i - 1);
            maxProfit = max(maxProfit , startGain + (values[i] - i));
        }
        return maxProfit;
    }
};