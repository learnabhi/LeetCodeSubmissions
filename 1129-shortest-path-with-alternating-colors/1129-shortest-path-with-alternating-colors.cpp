class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> red_graph(n) , blue_graph(n);
        vector<int> distR(n, INT_MAX) , distB(n, INT_MAX);
        
        distR[0] = distB[0] = 0;
        
        for(auto& edge : redEdges){
            red_graph[edge[0]].push_back(edge[1]);
        }
        
        for(auto& edge : blueEdges){
            blue_graph[edge[0]].push_back(edge[1]);
        }
        
        
        queue<pair<int,char>> q;
        q.push({0 , '\0'});
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            if(node.second != 'r'){
                for(auto& neigh : red_graph[node.first]){
                    if(distR[neigh] > distB[node.first] + 1){
                        q.push({neigh , 'r'});
                        distR[neigh] = distB[node.first]  + 1;
                    }
                }
            }
            
            if(node.second != 'b'){
                for(auto& neigh : blue_graph[node.first]){
                    if(distB[neigh] > distR[node.first] + 1){
                        q.push({neigh , 'b'});
                        distB[neigh] = distR[node.first] + 1;
                    }
                }
            }
        }
        
        for(int i = 0;i<n;i++){
            distR[i] = min(distR[i] , distB[i]);
            if(distR[i] == INT_MAX)
                distR[i] = -1;
        }
        
        return distR;
    }
};