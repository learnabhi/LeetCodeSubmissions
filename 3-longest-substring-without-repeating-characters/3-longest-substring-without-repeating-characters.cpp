class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0 , end = 0;
        int n = s.length();
        
        if(n == 0) return 0;
        
        unordered_map<char,int> mapka;
        
        int maxLen = 1;
        int counter = 0;
        while(end < n){
            char windowEndChar = s[end];
            mapka[windowEndChar]++;
            
            if(mapka[windowEndChar] > 1) counter++;
            
            end++;
            
            while(counter > 0){
                char windowStartChar = s[start];
                if(mapka[windowStartChar] > 1) counter--;
                mapka[windowStartChar]--;
                start++;
            }
            
            maxLen = max(maxLen , end - start);
        }
        
        return maxLen;
    }
};