class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        vector<string> words;
        istringstream ss(s);
        
        string word;
        while(ss >> word){
            words.push_back(word);
        }
        
        for(int i = 0;i<words.size();i++){
            string in = words[i];
            reverse(in.begin(),in.end());
            ans += in;
            if(i != words.size() - 1){
                ans += " ";
            }
        }
        
        return ans;
    }
};