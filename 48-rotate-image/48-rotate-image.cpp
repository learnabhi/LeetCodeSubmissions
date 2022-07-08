class Solution {
public:
    void rotate(vector<vector<int>>& ans) {
        int m = size(ans) , n = size(ans[0]);
        
        for(int i = 0;i<m;i++){
            for(int j = i+1;j<n;j++){
                swap(ans[i][j] , ans[j][i]);
            }
        }
        
        for(int i = 0;i<m;i++){
            reverse(ans[i].begin(),ans[i].end());
        }
        
    }
};