class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) { 
        unordered_map<string,int> mapka;
        
        vector<string> morsecode = {
          ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."  
        };
        
        for(auto& word : words){
            string temp = "";
            for(int i = 0;i<word.size();i++){
                temp += morsecode[word[i] - 'a'];
            }
            mapka[temp]++;
        }
        
        return (int)mapka.size();
    }
};