class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st(bank.begin() , bank.end());
        
        char choices[] = {'A' , 'C' , 'G' , 'T'};
        queue<string> q;
        
        q.push(start);
        
        if(st.find(start) != st.end())
            st.erase(start);
        
        int steps = 0;
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string from = q.front();
                q.pop();
                
                if(from == end){
                    return steps;
                }
                
                for(int i = 0;i<from.length();i++){
                    char oldChar = from[i];
                    
                    for(int j = 0;j<4;j++){
                        from[i] = choices[j];
                        if(st.find(from) != st.end()){
                            q.push(from);
                            st.erase(from);
                        }
                    }
                    
                    from[i] = oldChar;
                }
            }
            steps++;
        }
        
        return -1;
    }
};