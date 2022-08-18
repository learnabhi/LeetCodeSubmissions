class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ans, digitlogs;
        vector<pair<string,string>> letterlogs;
        for(string& s : logs){
            int i = 0;
            while(s[i] != ' '){
                i++;
            }
            if(isalpha(s[i+1]))
                letterlogs.push_back({s.substr(0 , i) , s.substr(i + 1) });
            else
                digitlogs.push_back(s);
        }
        
        sort(letterlogs.begin() , letterlogs.end() , [&](auto& a1 , auto& a2){
            return a1.second == a2.second ? a1.first < a2.first : a1.second < a2.second;
        });
        
        // cout<<"Reached Here!";
        
        for(auto& [first, second] : letterlogs){
            ans.push_back(first + " " + second);
        }
        
        for(auto& logs : digitlogs)
            ans.push_back(logs);
        
        return ans;
            
    }
};