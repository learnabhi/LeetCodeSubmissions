class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = size(matrix) , n = size(matrix[0]);
        
        int low = 0 , high = m*n - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(matrix[mid/n][mid%n] == target) return true;
            else if(matrix[mid/n][mid%n] > target)
                high = mid - 1;
            else 
                low = mid + 1;
        }
        
        return false;
    }
};