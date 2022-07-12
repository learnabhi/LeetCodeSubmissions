class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        int buy = 0 , sell = 0;
        
        while(buy < n){
            while(buy + 1 < n && prices[buy + 1] < prices[buy])
                buy++;
            
            sell = buy;
            
            while(sell + 1 < n && prices[sell + 1] > prices[sell])
                sell++;
            
            
            profit += prices[sell] - prices[buy];
            
            buy = sell + 1;
        }
        
        return profit;
    }
};