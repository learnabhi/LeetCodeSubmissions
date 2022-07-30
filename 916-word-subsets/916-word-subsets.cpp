class Solution {
public:
    int* countFreq(string& word){
        int* arr = new int[26];
        for(int i = 0;i<26;i++){
            arr[i] = 0;
        }
        for(auto& ch : word){
            arr[ch - 'a']++;
        }
        return arr;
    } 
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int maxFreq[26] = {0};
        for(auto& word : words2){
            int* temp = countFreq(word);
            for(int i = 0;i<26;i++){
                maxFreq[i] = max(maxFreq[i] , temp[i]);
            }
        }
        
        vector<string> ans;
        for(auto& word : words1){
            int* temp = countFreq(word);
            int i = 0;
            while(i < 26){
                if(temp[i] < maxFreq[i])
                    break;
                i++;
            }
            
            if(i == 26)
                ans.push_back(word);
        }
        
        return ans;
    }
};