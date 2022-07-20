class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
         int ans = 0;
        vector<vector<int>> mappings(26);  
        for(int i = 0; i < size(s); i++) 
            mappings[s[i] - 'a'].push_back(i);
        
        
        for(auto& word : words) {
            bool found = true;
            int prev = -1;
            for(int i = 0; i < size(word); i++) {
                auto& v = mappings[word[i]-'a'];
                auto it = upper_bound(begin(v), end(v), prev);   // check if current character exists in s with index > prev
                if(it == end(v)) {
                    found = false;
                    break;
                }// doesn't exist
                else prev = *it;                                 // update prev for next check
            }
            ans += found;
        }
        return ans;
    }
};