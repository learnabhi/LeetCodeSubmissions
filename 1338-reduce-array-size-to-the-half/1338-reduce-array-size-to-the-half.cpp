class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int,int> mapka;
        for(auto& val : arr){
            mapka[val]++;
        }
        
        vector<int> counting(n + 1);
        for(auto&[key , val] : mapka){
            counting[val]++;
        }
        
        int ans = 0 , removed = 0 , half = n/2 , freq = n;
        while(removed < half){
            while(counting[freq] == 0)
                freq--;
            
            ans++;
            removed += freq;
            counting[freq]--;
        }
        
        return ans;
    }
};