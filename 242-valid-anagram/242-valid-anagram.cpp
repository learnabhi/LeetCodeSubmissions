class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length() , m = t.length();
        if(n != m) return false;
        
        vector<int> freq(26,0);
        for(int i = 0;i<n;i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        
        return count(freq.begin() , freq.end() , 0) == 26;
    }
};