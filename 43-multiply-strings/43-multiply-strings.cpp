class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.length() < num2.length())
            return multiply(num2,num1);
        
        int n = num1.length();
        int m = num2.length();
        string ans(m + n , '0');
        
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                int val = (ans[i + j + 1] - '0') + (num2[i] - '0') * (num1[j] - '0');
                ans[i + j + 1] = val%10 + '0';
                ans[i + j] += val/10;
            }
        }
        
        for(int i = 0;i<m+n;i++){
            if(ans[i] != '0')
                return ans.substr(i);
        }
        
        return "0";
    }
};