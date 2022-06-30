class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        
        stack<char> st;
        for(char ch : s){
            if(ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else{
                if(st.empty()) return false;
                else{
                    char top = st.top();
                    st.pop();
                    if(!isMatch(top, ch)) return false; 
                }
            }
        }
        return st.empty();
    }
    
    bool isMatch(char& c1, char& c2){
        switch(c1){
            case '(':
                return c2 == ')';
            case '{':
                return c2 == '}';
            case '[':
                return c2 == ']';
            default:
                return false;
        }
        return false;
    }
};