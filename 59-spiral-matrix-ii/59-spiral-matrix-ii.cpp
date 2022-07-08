class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        
        int left = 0 , right = n - 1;
        int top = 0 , bottom = n - 1;
        
        int operation = 0, val = 1;
        while(left <= right && top <= bottom){
            if(operation == 0){
                for(int i = left;i<=right;i++){
                    ans[top][i] = val++;
                }
                top++;
            }else if(operation == 1){
                for(int i = top;i<=bottom;i++){
                    ans[i][right] = val++;
                }
                right--;
            }else if(operation == 2){
                for(int i = right;i>=left;i--){
                    ans[bottom][i] = val++;
                }
                bottom--;
            }else{
                for(int i = bottom;i>=top;i--){
                    ans[i][left] = val++;
                }
                left++;
            }
            
            operation = (operation + 1)%4;
        }
        
        return ans;
    }
};