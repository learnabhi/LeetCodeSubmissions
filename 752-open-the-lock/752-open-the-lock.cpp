class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin() , deadends.end());
        
        string start = "0000";
        
        if(st.count(start) || st.count(target))
            return -1;
        
        
        queue<string> q;
        q.push(start);
        st.insert(start);
        
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                string from = q.front();
                q.pop();
                
                if(from == target)
                    return steps;
                
                for(auto neigh : findNeigh(from)){
                    if(st.count(neigh))
                        continue;
                    
                    q.push(neigh);
                    st.insert(neigh);
                }
            }
            steps++;
        }
        
        return -1;
    }
    vector<string> findNeigh(string& str){
        vector<string> res;
        
        for(int i = 0;i<str.length();i++){
            string temp = str;
            temp[i] = (str[i] - '0' + 1) % 10 + '0';
            res.push_back(temp);
            
            temp[i] = (str[i] - '0' -1 + 10) % 10 + '0';
            res.push_back(temp);
        }
        
        return res;
    }
};