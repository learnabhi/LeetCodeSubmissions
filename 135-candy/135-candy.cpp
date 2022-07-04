class Solution {
public:
    int candy(vector<int>& ratings) {
        int i = 1 , n = ratings.size();
        int candy = n;
        while(i < n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            
            int peaks = 0;
            while(i < n && ratings[i] > ratings[i-1]){
                peaks++;
                candy += peaks;
                i++;
            }
            
            int valley = 0;
            while(i < n && ratings[i-1] > ratings[i]){
                valley++;
                candy += valley;
                i++;
            }
            
            candy -= min(peaks , valley);
        }
        
        return candy;
    }
};