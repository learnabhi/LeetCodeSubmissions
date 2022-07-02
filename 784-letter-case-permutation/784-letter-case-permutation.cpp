class Solution {
public:
    void backtrack(string& s, vector<string>& ans, int idx){
        if(idx == s.length()){
            ans.push_back(s);
            return;
        }
        backtrack(s,ans,idx+1);
        if(isalpha(s[idx])){
            s[idx] = islower(s[idx]) ? toupper(s[idx]) : tolower(s[idx]);
            backtrack(s,ans,idx+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        backtrack(s,ans,0);
        
        return ans;
    }
};