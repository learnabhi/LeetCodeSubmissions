class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        if(n < 10) return {};
        
        int end = 0;
        
        unordered_map<string,int> mapka;
        vector<string> ans;
        while(end + 9 < n){
            string temp = s.substr(end, 10);
            mapka[temp]++;
            end++;
        }
        
        for(auto it : mapka){
            if(it.second > 1)
                ans.push_back(it.first);
        }
        
        return ans;
    }
};