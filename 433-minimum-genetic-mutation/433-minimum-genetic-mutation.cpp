class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st(bank.begin() , bank.end());
        
        if(st.find(end) == st.end())
            return -1;
        
        char choices[] = {'A' , 'C' , 'G' , 'T'};
        queue<string> q;
        
        q.push(start);
        
        if(st.find(start) != st.end())
            st.erase(start);
        
        int steps = 0;
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string fromGene = q.front();
                q.pop();
                
                if(fromGene == end){
                    return steps;
                }
                
                for(int i = 0;i<fromGene.length();i++){
                    char oldChar = fromGene[i];
                    
                    for(int j = 0;j<4;j++){
                        fromGene[i] = choices[j];
                        if(st.find(fromGene) != st.end()){
                            q.push(fromGene);
                            st.erase(fromGene);
                        }
                    }
                    
                    fromGene[i] = oldChar;
                }
            }
            steps++;
        }
        
        return -1;
    }
};