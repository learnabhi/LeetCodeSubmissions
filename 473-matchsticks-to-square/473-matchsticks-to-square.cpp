class Solution {
public:
    bool solve(int idx, vector <int>& sums, int target, vector <int>& matchsticks){
        //if index >= matchsticks size, then return true when sums[0], sum[1] and sum[2] all are same as targer
        
        if(idx >= matchsticks.size()){
            return sums[0] == sums[1] && sums[1] == sums[2] && sums[2] == target;
        }
        //for i in range 0 to 3
        for(int i = 0; i < 4; i++){
            //if sums[i] + matchsticks[index] > target, then skip the next part of the loop
            if(sums[i] + matchsticks[idx] > target)continue;
            //sums[i] = sums[i] + matchsticks[index]
            sums[i] += matchsticks[idx];
            //if solve(index + 1, sums, target, matchsticks ) is true, then return true
            if(solve(idx + 1, sums, target, matchsticks)) return true;
            //sums[i] := sums[i] – matchsticks[index]
            sums[i] -= matchsticks[idx];
        }
         return false;
   }
    bool makesquare(vector<int>& matchsticks) {
        //if matchsticks has no elements, then return false
        if(matchsticks.size() == 0) return false;
        int x = 0;
        //for i in range 0 to size of matchsticks, increase x by matchsticks[j]
        for(int i = 0; i < matchsticks.size(); i++){
           x += matchsticks[i];
        }
        //if x is divisible by 4, then return false
        if(x % 4) return false;
        //sort the matchsticks array
        sort(matchsticks.rbegin(), matchsticks.rend());
        //make an array sums of size 4
        vector <int> sum(4);
        
        return solve(0, sum,x / 4, matchsticks);
    }
};