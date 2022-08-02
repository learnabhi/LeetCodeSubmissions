class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        for(int i = 0;i<n;i++){
            for(int val : graph[i])
                adj[i].push_back(val);
        }
        vector<int> color(n , 0);
        vector<bool> visited(n ,  false);
        
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                if(!dfs(adj,visited,color,i,1))
                    return false;
            }
        }
        
        return true;
    }
    bool dfs(vector<int> adj[], vector<bool>& visited, vector<int>& color, int src, int c){
       color[src] = c;
       visited[src] = true;
        
        for(auto neigh : adj[src]){
            if(!visited[neigh]){
                if(!dfs(adj,visited, color,neigh, c ^ 1))
                    return false;
            }else if(color[neigh] == color[src])
                return false;
        }
        
        return true;
    }
};