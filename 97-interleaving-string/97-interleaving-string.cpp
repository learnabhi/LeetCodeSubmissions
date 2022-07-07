class Solution {
public:
        int dp[101][101];
    bool isInterleavingUtil(string& s1, string& s2, string& s3, int i, int j){
        if(i == s1.length() && j == s2.length()) return true;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s3[i + j]){
            bool fromS1 = isInterleavingUtil(s1,s2,s3,i+1,j);
            dp[i][j] = fromS1 ? 1 : 0;
            if(fromS1){
                return true;
            }
        }
        
        if(s2[j] == s3[i + j]){
            bool fromS2 = isInterleavingUtil(s1,s2,s3,i,j+1);
            dp[i][j] = fromS2 ? 1 : 0;
            if(fromS2){
                return true;
            }
        }
        dp[i][j] = 0;
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length() , m = s2.length();
        int l = s3.length();
        
        if(l != (m + n)) return false;
        
        memset(dp,-1,sizeof dp);
        
        return isInterleavingUtil(s1,s2,s3,0,0);
    }
};