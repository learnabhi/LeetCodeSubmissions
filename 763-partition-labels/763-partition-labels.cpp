class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mapka;
        
        int n = s.length();
        
        for(int i = 0;i<n;i++){
            mapka[s[i]] = i;
        }
        
        int last = 0 , start = 0;
        vector<int> ans;
        for(int i = 0;i<n;i++){
            last = max(last , mapka[s[i]]);
            if(last == i){
                ans.push_back(i - start + 1);
                start = i + 1;
            }
        }
        
        return ans;
    }
};