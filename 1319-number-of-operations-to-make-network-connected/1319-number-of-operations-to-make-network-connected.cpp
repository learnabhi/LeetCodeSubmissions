class Solution {
public:
    vector<int> parent;
    int find(int x){
        return (parent[x] == x) ? x : find(parent[x]);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int wires = connections.size();
        if(wires < n - 1)
            return -1;
        
        parent.resize(n);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
        
        
        int components = n;
        for(int i = 0;i< wires;i++){
            int x = find(connections[i][0]);
            int y = find(connections[i][1]);
            
            if(x != y){
                parent[y] = x;
                components--;
            }
        }
        
        return components - 1;
    }
};