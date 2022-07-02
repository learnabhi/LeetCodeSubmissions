class Solution {
public:
    int mod = 1000000007;
    int getMax(int size, vector<int> cuts){
        sort(cuts.begin() , cuts.end());
        int maxx = max(cuts[0] , size - cuts[cuts.size() - 1]);
        
        for(int i = 1;i<cuts.size();i++){
            maxx = max(maxx , cuts[i] - cuts[i-1]);
        }
        
        return maxx;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int lengthMax = getMax(h, horizontalCuts);
        int widthMax = getMax(w, verticalCuts);
        
        return ((long)lengthMax%mod * widthMax%mod) % mod;
    }
};