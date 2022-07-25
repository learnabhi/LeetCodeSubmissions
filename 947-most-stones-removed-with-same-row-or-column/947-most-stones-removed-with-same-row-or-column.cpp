class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        parent.resize(n);
        size.resize(n);
        
        for(int i = 0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }
        
        int components = n;
        for(int i = 0;i<n;i++){
            for(int j = i +1;j<n;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    union_set(i,j, components);
            }
        }
        
        
        return n - components;
    }
    void union_set(int i, int j, int& components){
        i = find(i);
        j = find(j);
        
        if(i == j)
            return;
        
        if(size[i]  < size[j])
            swap(i, j);
        
        parent[j] = i;
        components--;
        size[i] += size[j];
    }
    
    int find(int x){
        if(x == parent[x])
            return x;
        
        return parent[x] = find(parent[x]);
    }
};