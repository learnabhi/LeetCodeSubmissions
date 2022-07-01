class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin() , boxTypes.end() , [](auto& p1, auto& p2){
            return p1[1] > p2[1];
        });
        
        long long maxUnits = 0;
        
        int i = 0;
        while(truckSize > 0 && i < n){
            maxUnits += min(truckSize , boxTypes[i][0])*boxTypes[i][1];
            truckSize -= boxTypes[i][0];
            i++;
        }
        
        return (int)maxUnits;
    }
};