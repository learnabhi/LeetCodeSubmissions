class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        
        string word;
        istringstream ss(s);
        
        while(ss >> word)
            words.push_back(word);
        
        
        int n = pattern.length() , m = words.size();
        if(n != m)
            return false;
        
        
        unordered_map<char,int> m1;
        unordered_map<string,int> m2;
        
        for(int i = 0;i<n;i++){
            if(m1[pattern[i]] != m2[words[i]])
                return false;
            
            m1[pattern[i]] = i+1;
            m2[words[i]] = i+1;
        }
        
        return true;
    }
};