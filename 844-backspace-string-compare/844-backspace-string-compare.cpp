class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int s_len = s.length() , t_len = t.length();
        
        int i = s_len - 1 , j = t_len - 1;
        int count1 = 0 , count2 = 0;
        
        while(i >= 0 || j >=0){
            while(i >= 0 && (s[i] == '#' || count1 > 0)){
                if(s[i] == '#') count1++;
                else count1--;
                i--;
            }
            
            while(j >= 0 && (t[j] == '#' || count2 > 0)){
                if(t[j] == '#') count2++;
                else count2--;
                j--;
            }
            
            if(i >= 0 && j >= 0 && s[i] == t[j]){
                i--;
                j--;
            }else{
                return (i == -1 && j == -1);
            }
        }
        
        return true;
    }
};