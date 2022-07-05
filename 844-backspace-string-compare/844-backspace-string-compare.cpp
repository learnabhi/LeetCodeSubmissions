class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.length() , m = t.length();
        
        stack<char> st1;
        stack<char> st2;
        
        for(auto& ch : s){
            if(ch == '#'){
                if(!st1.empty())
                    st1.pop();
            }else{
                st1.push(ch);
            }
        }
        
        for(auto& ch : t){
            if(ch == '#'){
                if(!st2.empty())
                    st2.pop();
            }else{
                st2.push(ch);
            }
        }
        
        while(!st1.empty() && !st2.empty()){
            char s_char = st1.top(); st1.pop();
            char t_char = st2.top(); st2.pop();
            
            if(s_char != t_char) return false;
        }
        
        return (st1.empty() && st2.empty());
    }
};