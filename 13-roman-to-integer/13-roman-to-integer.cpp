class Solution {
public:
    int romanToInt(string s) {
        if(s.length() == 0)
            return 0;
        
        unordered_map<char,int> mapka = {
            {'I' , 1},
            {'V' , 5},
            {'X' , 10},
            {'L' , 50},
            {'C' , 100},
            {'D' , 500},
            {'M' , 1000}
        };
        
        int curr = mapka[s[0]];
        int sum = 0;
        for(int i = 1;i<s.length();i++){
            int right = mapka[s[i]];
            if(right > curr)
                sum -= curr;
            else
                sum += curr;
            
            curr = right;
        }
        
        return curr + sum;
    }
};