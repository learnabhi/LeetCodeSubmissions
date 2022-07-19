class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin() , wordList.end());
        
        queue<string> q;
        
        if(!st.count(endWord))
            return 0;
        
        q.push(beginWord);
        
        if(st.count(beginWord))
            st.erase(beginWord);
        
        int steps = 1;
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                auto word = q.front();
                q.pop();
                
                
                if(word == endWord)
                    return steps;
                
                for(int i = 0;i<word.length();i++){
                    char oldChar = word[i];
                    for(int j = 0;j<26;j++){
                        word[i] = char(j + 'a');
                        if(st.count(word)){
                            q.push(word);
                            st.erase(word);
                        }
                    }
                    word[i] = oldChar;
                }
            }
            steps++;
        }
        
        return 0;
    }
};