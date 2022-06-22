class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mapka;
        for(int i = 0;i<(int)nums.size();i++){
            int secondNum = target - nums[i];
            if(mapka.find(secondNum) != mapka.end()){
                return {i , mapka[secondNum]};
            }
            mapka[nums[i]] = i;
        }
        return {};
    }
};