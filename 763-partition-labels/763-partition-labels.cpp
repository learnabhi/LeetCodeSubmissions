class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26,0);
        
        int n = s.length();
        
        for(int i = 0;i<n;i++){
            freq[s[i] - 'a'] = i;
        }
        
        int last = 0 , start = 0;
        vector<int> ans;
        for(int i = 0;i<n;i++){
            last = max(last , freq[s[i] - 'a']);
            if(last == i){
                ans.push_back(i - start + 1);
                start = i + 1;
            }
        }
        
        return ans;
    }
};