class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        
        for(int i = 0;i<n-1;i++){
            adj[connections[i][0]].push_back({connections[i][1] , 1});
            adj[connections[i][1]].push_back({connections[i][0], -1});
        }
        int res = 0;
        dfs(adj,0,-1,res);
        
        
        return res;
    }
    void dfs(vector<vector<pair<int,int>>>& adj, int src, int par, int& res){
        for(auto neigh : adj[src]){
            if(par == neigh.first)
                continue;
            
            if(neigh.second > 0)
                res++;
            
            dfs(adj,neigh.first,src,res);
        }
    }
};