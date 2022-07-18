class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res = 0;
        
        for(int i = 0;i<n;i++){
            if(i == headID)
                continue;
            res = max(res,  dfs(i,manager,informTime));
        }
        
        return res;
    }
    int dfs(int v, vector<int>& manager, vector<int>& informTime){
        if(manager[v] != -1){
            informTime[v] += dfs(manager[v] , manager, informTime);
            manager[v] = -1;
        }
        
        return informTime[v];
    }
};