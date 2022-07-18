class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> ans, visited(n,0);
        
        for(int i = 0;i<n;i++){
            if(dfs(i,graph,visited) == 1)
                ans.push_back(i);
        }
        
        return ans;
    }
    
    int dfs(int i, vector<vector<int>>& graph, vector<int>& visited){
        if(visited[i] != 0)
            return visited[i];
        
        visited[i] = -1;
        
        for(auto neigh : graph[i])
            if(dfs(neigh, graph, visited) == -1)
                return -1;
        
        
        return visited[i] = 1;
    }
};