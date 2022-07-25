class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>> stops_to_bus_mapping;
        for(int i = 0;i<routes.size();i++){
            for(auto stops : routes[i])
                stops_to_bus_mapping[stops].push_back(i);
        }
        
        unordered_set<int> visited = {source};
        
        queue<pair<int,int>> q;
        q.push({source, 0});
        
        
        while(!q.empty()){
            auto stop = q.front().first;
            auto bus = q.front().second;
            
            q.pop();
            
            if(stop == target)
                return bus;
            
            for(auto nextBus : stops_to_bus_mapping[stop]){
                for(auto nextStop : routes[nextBus]){
                    if(!visited.count(nextStop)){
                        visited.insert(nextStop);
                        q.push({nextStop , bus + 1});
                    }
                }
                routes[nextBus].clear();
            }
        }
        
        return -1;
    }
};