class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mapka;
        for(int i = 0;i<n;i++){
            mapka[nums[i]]++;
        }
        
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(auto it : mapka){
            pq.push({it.second, it.first});
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};