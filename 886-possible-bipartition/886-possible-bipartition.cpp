class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        for(int i = 0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> color(n + 1 , 0);
        vector<bool> visited(n + 1,  false);
        
        for(int i = 1;i<=n;i++){
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