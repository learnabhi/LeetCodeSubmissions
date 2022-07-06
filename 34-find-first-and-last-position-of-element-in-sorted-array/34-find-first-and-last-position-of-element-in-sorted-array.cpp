class Solution {
public:
    int binarySearchFirstOccurence(vector<int>& nums,int target, int low, int high){
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] > target)
                high--;
            else if(nums[mid] < target)
                low++;
            else{
                if(mid == low || (mid - 1 >= low && nums[mid - 1] != target))
                    return mid;
                else
                    high = mid - 1;
            }
        }
        
        return -1;
    }
    int binarySearchLastOccurence(vector<int>& nums,int target, int low, int high){
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] > target)
                high--;
            else if(nums[mid] < target)
                low++;
            else{
                if(mid == high || (mid +  1 <= high && nums[mid + 1] != target))
                    return mid;
                else
                    low = mid + 1;
            }
        }
        
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = binarySearchFirstOccurence(nums , target , 0 , n-1);
        if(first == -1)
            return {-1 , -1};
        
        int second = binarySearchLastOccurence(nums,target, first + 1 ,n-1);
        
        if(second == -1)
            return {first , first};
        else
            return {first , second};
    }
};