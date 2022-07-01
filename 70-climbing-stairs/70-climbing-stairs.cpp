class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        
        int a = 1, b = 2;
        for(int i = 3;i<=n;i++){
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};