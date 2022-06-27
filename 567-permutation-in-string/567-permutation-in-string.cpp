class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length() , m = s2.length();
        if(m < n) return false;
        
        vector<int> freq(26,0);
        
        for(int i = 0;i<n;i++){
            freq[s1[i] - 'a']++;
        }
        
        int start = 0 , end = 0;
        while(end < m){
            char windowEndChar = s2[end];
            freq[windowEndChar - 'a']--;
            
            while(freq[windowEndChar - 'a'] < 0){
                char windowStartChar = s2[start];
                freq[windowStartChar - 'a']++;
                start++;
            }
            
            if(end - start + 1 == n) 
                return true;
            
            end++;
        }
        
        return false;
    }
};