class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mapka;
        
        int m = size(matrix) , n = size(matrix[0]);
        for(int i = 0;i<m;i++){
            string key = "";
            int first = matrix[i][0];
            for(int j = 1;j<n;j++){
                if(matrix[i][j] == first)
                    key += '1';
                else
                    key += '0';
            }
            mapka[key]++;
        }
        
        int maxx = 0;
        for(auto& [key,val] : mapka){
            maxx = max(maxx , val);
        }
        
        return maxx;
    }
};