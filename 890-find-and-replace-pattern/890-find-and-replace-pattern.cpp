class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        pattern = normaliseWord(pattern);
        
        for(auto& word : words){
            if(normaliseWord(word) == pattern){
                res.push_back(word);
            }
        }
        
        return res;
    }
    
    string normaliseWord(string word){
        unordered_map<char,int> mapka;
        for(auto& ch : word){
            if(!mapka.count(ch))
                mapka[ch] = (int)mapka.size();
        }
        
        for(int i = 0;i<word.length();i++){
            word[i] = 'a' + mapka[word[i]];
        }
        
        return word;
    }
};