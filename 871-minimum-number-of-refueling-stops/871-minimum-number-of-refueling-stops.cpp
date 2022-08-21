class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        
        priority_queue<int> pq;
        
        int curr = startFuel, stops = 0;
        int i = 0;
        
        while(curr < target){
            while(i < n && curr >= stations[i][0]){
                pq.push(stations[i][1]);
                i++;
            }
            
            if(pq.empty())
                return -1;
            
            curr += pq.top();
            pq.pop();
            
            stops++;
        }
        
        return stops;
    }
};