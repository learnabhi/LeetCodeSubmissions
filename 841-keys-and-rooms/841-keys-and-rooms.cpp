class Solution {
public:
    void dfs(vector<vector<int>>& rooms,int src,vector<bool>& visited){
        visited[src] = true;
        
        for(auto& neigh : rooms[src]){
            if(!visited[neigh])
                dfs(rooms,neigh,visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        vector<bool> visited(n,false);
        
        dfs(rooms,0,visited);
        
        for(int i = 0;i<n;i++){
            if(!visited[i])
                return false;
        }
        
        return true;
    }
};