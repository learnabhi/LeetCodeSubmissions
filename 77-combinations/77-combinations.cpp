class Solution {
public:
    void backtrack(vector<vector<int>>& ans, int start, int end, int k , vector<int>& temp){
        if(k == 0){
            ans.push_back(temp);
            return ;
        }
        
        for(int i = start;i<=end-k + 1;i++){
            temp.push_back(i);
            backtrack(ans,i+1,end,k-1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(ans,1,n,k, temp);
        
        return ans;
    }
};