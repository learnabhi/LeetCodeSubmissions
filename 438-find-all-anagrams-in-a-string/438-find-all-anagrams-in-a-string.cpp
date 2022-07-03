class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.length() , m = s.length();
        if(m < n) return {};
        
        vector<int> freq_p(26,0) , window(26,0);
        for(int i = 0;i<n;i++){
            freq_p[p[i] - 'a']++;
            window[s[i]- 'a']++;
        }
        
        vector<int> ans;
        
        if(freq_p == window) 
            ans.push_back(0);
        
        for(int i = n;i<m;i++){
            window[s[i - n] - 'a']--;
            window[s[i] - 'a']++;
            
            if(freq_p == window)
                ans.push_back(i-n + 1);
        }
        
        return ans;
    }
};